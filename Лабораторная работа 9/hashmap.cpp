#include <iostream>

struct Node
{
    int key;
    int value;
    Node * next;

};

struct HashMap
{
    int key;
    int em_key; // emergency key
    int size;
    int n_elements;
    Node * table[];

    int hash(int x)
    {
        return (x * key) % size;
    }

    int em_hash(int x)
    {
        return (x * em_key) % size;
    }

    void add(int key, int value)
    {

    }

    int get(int key)
    {

    }

    void reallocate()
    {

    }

    int pop(int key)
    {

    }

};

int main() {
    return 0;
}
