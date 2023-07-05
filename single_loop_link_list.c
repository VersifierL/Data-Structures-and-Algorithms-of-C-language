#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *init_loop_list()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = head;
    return head;
}

void head_insert(Node *list, int data)
{
    list->data++;

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
}

void tail_insert(Node *list, int data)
{
    list->data++;

    Node *head = list;

    list = list->next;
    while (list->next != head)
    {
        list = list->next;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    list->next = node;
}
void delete_data(Node *list, int data)
{
    list->data--;

    Node *pre = list;
    Node *current = list->next;

    while (current != list)
    {
        if (current->data == data)
        {
            pre->next = current->next;
            free(current);
            current = NULL;
            break;
        }
        pre = current;
        current = current->next;
    }
}
void print_loop_list(Node *list)
{
    Node *head = list;
    list = list->next;
    while (list != head)
    {
        printf("%d ->", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    Node *loop_list = init_loop_list();
    print_loop_list(loop_list);
    head_insert(loop_list, 1);
    head_insert(loop_list, 2);
    head_insert(loop_list, 3);
    print_loop_list(loop_list);
    tail_insert(loop_list, 4);
    tail_insert(loop_list, 5);
    tail_insert(loop_list, 6);
    print_loop_list(loop_list);
    delete_data(loop_list, 2);
    delete_data(loop_list, 6);
    print_loop_list(loop_list);
    return 0;
}