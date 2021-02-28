#include <iostream>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_left(Node ** head, int value) { // заполнение списка для проверки правильности работы функции
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
    }

    Node * new_node = new Node;
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;    
}

void print_list(Node * head)
{
    Node * p_node = head;
    while (p_node->next != NULL) {
        std::cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    std::cout << '\n';
}

void replace_all(Node * head, int old_value, int new_value)
{
    Node * p_node = head;

    while (p_node->next != NULL) {
       if (p_node->value == old_value) {p_node->value = new_value;}
       p_node = p_node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * list = NULL;
    for (int i = 1; i <= 10; ++i) push_left(&list, i);
    for (int i = 1; i <= 10; ++i) push_left(&list, i);
    print_list(list);
    replace_all(list, 5, 37);
    print_list(list);
    return 0;
}
