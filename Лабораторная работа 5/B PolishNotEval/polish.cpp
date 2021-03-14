#include <iostream>

using namespace std;

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

void push_left(Stack ** head, int value)
{
    if (*head == NULL) {
        *head = new Stack;
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        Stack * new_node = new Stack;
        new_node->value = value;
        new_node->next = *head;
        *head = new_node;
    }
}

void pop(Stack ** head)
{
    Stack * p_node = *head;
    *head = (*head)->next;
    delete p_node;
}

int top(Stack ** head)
{
    Stack * p_node = *head;
    return p_node->value;
}

void clear(Stack ** head) {
    Stack * p_node = *head;
    Stack * p_node_next = p_node->next;

    while (p_node->next != NULL) {
        delete [] p_node;
        p_node = p_node_next;
        p_node_next = p_node->next;
        *head = p_node;
    }
    delete [] p_node;
    *head = NULL;
}

int main(int argc, char const *argv[])
{
    Stack * stack = NULL;
    string memory;

    int a, b, c;
    while (cin >> memory)
    {
        if (memory == "+")
        {
            b = top(&stack); pop(&stack);
            a = top(&stack); pop(&stack);
            c = a + b;
            push_left(&stack, c);
        }
        else if (memory == "-")
        {
            b = top(&stack); pop(&stack);
            a = top(&stack); pop(&stack);
            c = a - b;
            push_left(&stack, c);
        }
        else if (memory == "*")
        {
            b = top(&stack); pop(&stack);
            a = top(&stack); pop(&stack);
            c = a * b;
            push_left(&stack, c);
        }
        else if (memory == "/") 
        {
            b = top(&stack); pop(&stack);
            a = top(&stack); pop(&stack);
            c = a / b;
            push_left(&stack, c);
        }
        else
        {
            push_left(&stack, atoi(memory.c_str()));
        }
    }
    cout << top(&stack);
    clear(&stack);
    return 0;
}