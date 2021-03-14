#include <iostream>

using namespace std;

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

void push_left(Stack ** head, int value) // вершина - в начале списка
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
    int x = 1; // произвольное значение для входа в цикл
    
    while (x != 0) {
        cin >> x;

        if (x > 0) {
            push_left(&stack, x);
        } else if (stack != NULL) {
            if (-x < top(&stack)) {
                stack->value = stack->value + x;
            } else {
                pop(&stack);
            }
        }
    }

    if (stack != NULL) {
        cout << depth(stack) << ' ' << top(&stack) << '\n';
        clear (&stack);
    } else {
        cout << depth(stack) << ' ' << -1 << '\n';
    }

    return 0;
}