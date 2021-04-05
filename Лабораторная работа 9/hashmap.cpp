#include <iostream>

typedef struct Node
{
    int key;
    int value;
    Node * next;
};

Node* init(int size)
{
    Node* head = new Node;
    // (*head)->value = value;
    (head)->next = NULL;
    (head)->key = 0;

    Node * p_node = head;

    for (int i = 1; i < size; i++)
    {
        Node * new_node = new Node;
        p_node->next = new_node;
        p_node->key = i;
        // new_node->value = value;
        p_node = p_node->next;
    }

    p_node->next = NULL;

    return head;
}

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

    void add(int x, int value)
    {

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

};

int main() {
    return 0;
}
