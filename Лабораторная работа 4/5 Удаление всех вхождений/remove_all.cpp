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
        std::cout << p_node->value << ' ' << p_node->next << ' ';
        p_node = p_node->next;
    }
    std::cout << '\n';
}

void remove_all(Node ** head, int value)
{
    Node * p_node = *head;
    Node * p_node_prev = *head;

    for (int i = 0; i<20; i++) { // не получается применить цикл while с условием на указатель (начинается бесконечный цикл)
       if (p_node->value == value) {

           if (p_node_prev->next == p_node->next) {
               *head = p_node_prev->next;
           } else {p_node_prev->next = p_node->next;}

           delete [] p_node;
       }
       p_node_prev = p_node;
       p_node = p_node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node * list = NULL;
    for (int i = 1; i <= 10; ++i) push_left(&list, i);
    for (int i = 1; i <= 10; ++i) push_left(&list, i);
    print_list(list);
    std::cout << "mark" << '\n';
    remove_all(&list, 5);
    print_list(list);
    return 0;
}
