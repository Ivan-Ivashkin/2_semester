#include <iostream>

struct Node
{
    int key;
    int value;
    bool is_deleted;
};

struct HashMap
{
    int key, em_key; // emergency key
    int size;
    int n_elements;
    Node * table[];

    HashMap()
    {
        key = 0;
        em_key = 0;
        n_elements = 0;

        for (int i = 0; i < size; i++)
        {
            table[size] = NULL;
        }
    }

    int hash(int x)
    {
        return (x * key) % size;
    }

    int em_hash(int x)
    {
        return (x * em_key) % size;
    }

    void add(int x, int value)
    {
        int i = 0;
        while (table[hash(x) + i*em_hash(x)] != NULL) i++;

        table[hash(x) + i*em_hash(x)]->value = value;
        table[hash(x) + i*em_hash(x)]->key = x;
    }

    int get(int x)
    {

    }

    void reallocate()
    {

    }

    int pop(int x)
    {

    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << table[i]->value << " ";
        }
    }

};

int main() {

    HashMap A;

    A.size = 20;
    A.key = 7;
    A.em_key = 13;

    for (int i = 0; i < A.size; i++)
    {
        A.add(i, i);
    }

    A.print();

    return 0;
}
