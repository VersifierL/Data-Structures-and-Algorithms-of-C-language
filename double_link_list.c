#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
} Node;

Node *init_list()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->prior = NULL;
    head->next = NULL;
    return head;
}

void head_insert(Node *list, int data)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    if (list->data == 0)
    {   
        list->data++;
        // 链表为空
        node->next = list->next;
        node->prior = list;
        list->next = node;
    }
    else
    {   list->data++;
        node->next = list->next;
        node->prior = list;
        list->next->prior = node; // 重要、且要在上一句之前
        list->next = node;

    }
}

void tail_insert(Node *list, int data)
{
    list->data++;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    while (list->next != NULL)
    {
        list = list->next;
    }

    node->next = list->next;
    node->prior = list;
    list->next = node;
}

int delete_data(Node *list, int data)
{
    list->data--;
    Node *current = list->next;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current->next != NULL)
            {
                current->prior->next = current->next;
                current->next->prior = current->prior;
            }
            else
            {
                current->prior->next = current->next;
            }
            free(current);
            current = NULL;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_list(Node *list)
{
    list = list->next;
    while (list != NULL)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    Node *list = init_list();
    head_insert(list, 1);
    head_insert(list, 2);
    head_insert(list, 3);
    tail_insert(list, 1);
    tail_insert(list, 2);
    tail_insert(list, 3);
    print_list(list);
    delete_data(list, 3);
    delete_data(list, 3);
    delete_data(list, 1);
    printf("the length of list is %d\n", list->data);
    print_list(list);
    return 0;
}