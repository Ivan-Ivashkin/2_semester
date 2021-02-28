#include <iostream>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push_left(Node ** head, int value) { // заполняем список, чтобы отследить удаление значений
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

void clear_list(Node ** head) {
    Node * p_node = *head;
    Node * p_node_next = p_node->next;

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
    Node * list = NULL;
    for (int i = 1; i <= 10; ++i) push_left(&list, i);
    print_list(list);
    clear_list(&list);
    print_list(list);
    return 0;
}