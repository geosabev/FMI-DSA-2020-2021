#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>
#include <queue>
#include <string>
using namespace std;

struct Element
{
    int value, chunk_index;

    Element(int v = 0, int idx = 0)
    {
        this->value = v;
        this->chunk_index = idx;
    }
};

class DataChunk
{
public:
    DataChunk(int c = 25000000)
        : data(new int[c]), CAP(c), size(0) {}
    ~DataChunk()
    {
        delete this->data;
    }

    int get_size() const
    {
        return this->size;
    }

    void add(const int& element)
    {
        if (this->size == this->CAP)
            return;

        this->data[this->size++] = element;
    }

    void sort_data()
    {
        sort(this->data, this->data + this->size);
    }

    void export_to_file(string& prefix, int idx) const
    {
        string filename = prefix + to_string(idx) + ".txt";

        int s = this->size;

        ofstream output_file(filename.c_str());

        for (int i = 0; i < s; i++)
            output_file << this->data[i] << '\n';

        output_file.close();
    }

    void clear()
    {
        this->size = 0;
    }

private:
    int* data;
    int size, CAP;
};

class Compare_Elements
{
public:
    bool operator()(const Element& e1, const Element& e2)
    {
        return (e1.value > e2.value);
    }
};

int split_data(string input, string output, double chunk_size)
{
    int current_number = 0, chunk_amount = 1, numbers_CAP = (chunk_size * (int)1e6) / sizeof(int);

    ifstream input_file(input + ".txt");

    DataChunk chunk(numbers_CAP);

    bool processed = false;

    while (input_file >> current_number)
    {
        processed = false;

        chunk.add(current_number);

        if (chunk.get_size() == numbers_CAP)
        {
            chunk.sort_data();
            
            chunk.export_to_file(output, chunk_amount++);

            chunk.clear();

            processed = true;
        }
    }

    if (processed)
        chunk_amount--;
    else
    {
        chunk.sort_data();

        chunk.export_to_file(output, chunk_amount);

        chunk.clear();
    }

    input_file.close();

    return chunk_amount;
}

void kWayMerge(string output_name, int k)
{
    if (k == 0)
        return;

    priority_queue<Element, vector<Element>, Compare_Elements> pq;

    ifstream* chunks = new ifstream[k];

    for (int i = 0; i < k; i++)
    {
        string current_chunk = output_name + to_string(i + 1) + ".txt";

        chunks[i].open(current_chunk.c_str());

        int value;
        chunks[i] >> value;

        Element first_element(value, i);

        pq.push(first_element);
    }

    ofstream output_file(output_name + ".txt");

    while (pq.empty() == false)
    {
        Element min_element = pq.top();

        pq.pop();

        output_file << min_element.value << '\n';

        int next;

        if (chunks[min_element.chunk_index] >> next)
        {
            Element to_add(next, min_element.chunk_index);

            pq.push(to_add);
        }
    }

    for (int i = 0; i < k; i++)
    {
        chunks[i].close();

        string chunk_name = output_name + to_string(i + 1) + ".txt";

        remove(chunk_name.c_str());
    }

    output_file.close();

    delete[] chunks;

    cout << "\nYour data has been sorted successfully! Check " << output_name << ".txt for the results.\n";   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input_name, output_name;
    int chunk_size_mb;

    cout << "Enter input filename, output filename and memory to use for chunks (in megabytes):\n";

    cin >> input_name >> output_name;
    cin >> chunk_size_mb;

    auto start = chrono::high_resolution_clock::now();

    int chunk_amount = split_data(input_name, output_name, chunk_size_mb);

    kWayMerge(output, chunk_amount);

    auto stop = chrono::high_resolution_clock::now();

    double duration = chrono::duration<double>(stop - start).count();

    cout << "The whole process took " << duration << " seconds to finish." << '\n';

    return 0;
}