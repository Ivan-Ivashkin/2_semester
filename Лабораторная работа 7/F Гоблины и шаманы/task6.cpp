#include <iostream>

using namespace std;

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

int depth(Stack * head)
{
    Stack * p_node = head;
    int counter = 0;
            
    while (p_node != NULL) {
        counter++;
        p_node = p_node->next;
    }

    return counter;
}

void push_right(Stack ** head, int value)
{
    if (*head == NULL) {
        *head = new Stack;
        (*head)->value = value;
        (*head)->next = NULL;

    } else {
        Stack * p_node = *head;
        Stack * p_node_next = p_node->next;

        while (p_node->next != NULL) {
            p_node = p_node_next;
            p_node_next = p_node->next;
        }

        Stack * new_node = new Stack;
        new_node->value = value;
        new_node->next = NULL;
        p_node->next = new_node;
    }
}

void insert(Stack ** head, int value)
{
    if (*head == NULL) {
        *head = new Stack;
        (*head)->value = value;
        (*head)->next = NULL;

    } else {
        int num = depth(*head) / 2;
        if (depth(*head) % 2 != 0) {
            num++;
        }

        Stack * p_node = *head;
        Stack * p_node_next = p_node->next;

        int index = 1;

        while (index < num) {
            p_node = p_node_next;
            p_node_next = p_node->next;
            index++;
        }

        Stack * new_node = new Stack;
        new_node->value = value;
        new_node->next = p_node_next;
        p_node->next = new_node;
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

void print_list(Stack ** head)
{
    Stack * p_node = *head;
    while (p_node != NULL) {
        std::cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    Stack * stack = NULL;
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;

        if (x == "+") {
            cin >> x;
            push_right(&stack, atoi(x.c_str()));
        } else if (x == "*") {
            cin >> x;
            insert(&stack, atoi(x.c_str()));
        } else if (x == "-") {
            cout << top(&stack) << '\n';
            pop(&stack);
        }
    }

    clear(&stack);

    return 0;
}