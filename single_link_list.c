#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *init_list()
{
    // ͷ�ڵ��������������������ĳ���
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void head_insert(Node *list, int data)
{
    list->data++;

    // ��ʼ��
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    // node->next = NULL;

    // ��ʼ����
    node->next = list->next;
    list->next = node;
}

void tail_insert(Node *list, int data)
{
    list->data++;

    // ��ʼ���½ڵ�
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    // ָ���׽ڵ�
    list = list->next;
    // ָ��β�ڵ�
    while (list->next)
    {
        list = list->next;
    }
    list->next = node;
}

void delete_data(Node *list, int data)
{
    list->data--;

    Node *pre = list;
    Node *current = list->next;

    while (current)
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
void delete_index(Node *list, int index)
{

    Node *pre = list;
    Node *current = list->next;

    for (int i = 1; i < index; i++)
    {
        pre = current;
        current = current->next;
    }

    pre->next = current->next;
    free(current);
    current = NULL;

    list->data--;
}

void insert_index(Node *list, int index, int data)
{
    list->data++;

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    Node *pre = list;
    Node *current = list->next;

    for (int i = 1; i < index; i++)
    {
        pre = current;
        current = current->next;
    }

    pre->next = node;
    node->next = current;
}

void printf_list(Node *list)
{
    // ����ͷ�ڵ�
    list = list->next;
    if (list == NULL)
    {
        printf("������");
    }
    else
    {
        while (list)
        {

            printf("%d ", list->data);
            list = list->next;
        }
    }
    printf("\n");
}

int main()
{
    Node *list = init_list();
    head_insert(list, 1);
    head_insert(list, 2);
    head_insert(list, 3);
    head_insert(list, 4);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);
    tail_insert(list, 5);
    tail_insert(list, 6);
    tail_insert(list, 7);
    tail_insert(list, 8);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);
    delete_data(list, 4);
    delete_data(list, 8);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);
    delete_index(list, 1);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);
    delete_index(list, 5);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);
    insert_index(list,1,1);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);   
    insert_index(list,6,5);
    printf("the length of list is %d \n ", list->data);
    printf_list(list);  
}