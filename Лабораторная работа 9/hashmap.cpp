#include <iostream>

struct Node
{
    int key;
    int value;
    bool deleted = true;
};

struct HashMap
{
    int size;
    int key;
    int col_key;
    int n_elements;
    Node **table;

    HashMap()
    {
        size = 100;
        key = size - 1;
        col_key = size + 1; //collision key
        n_elements = 0;
        table = new Node* [100];
    }

    ~HashMap()
    {
        for (int i = 0; i < size; i++)
        {
            delete table[i];
        }
        delete[] table;
    }

    int hash(int x)
    {
        return (x * key) % size;
    }

    int col_hash(int x)
    {
        return (x * col_key) % size;
    }

    int count_hash(int x, int i)
    {
        int a = hash(x);
        for (int j = 0; j < i; j++) {
            a = a + col_hash(x);
        }
        return a;
    }

    void add(int x, int value)
    {
        int i = 0;
        while (table[count_hash(x, i)] == NULL) {i++;}

        table[count_hash(x, i)] = new Node;

        table[count_hash(x, i)]->key = x;
        table[count_hash(x, i)]->value = value;
        table[count_hash(x, i)]->deleted = false;
    }

    int get(int x)
    {
        return 0;
    }

    void reallocate()
    {}

    int pop(int x)
    {
        return 0;
    }

};

int main() {

    using std::cout;

    HashMap A;
    A.add(3, 17);

    return 0;
}
