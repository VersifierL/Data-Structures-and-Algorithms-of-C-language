#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int stack_is_emtpy(Node *s)
{
    if (s->data == 0 && s->next == NULL)
    {
        return 1;
    }
    return 0;
}
int pop(Node *s)
{
    if (stack_is_emtpy(s))
    {
        return -1;
    }
    else
    {
        Node *node = s->next;
        int data = 0;

        s->next = node->next;
        data = node->data;
        free(node);
        node = NULL;
        return data;
    }
}

void push(Node *s, int data)
{
    s->data++;

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = s->next;
    s->next = node;
}

Node *init_stack()
{
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = 0;
    s->next = NULL;
    return s;
}

void print_stack(Node *s)
{
    s = s->next;
    while (s)
    {
        printf("%d ->", s->data);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    Node *s = init_stack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    print_stack(s);
    pop(s);
    print_stack(s);   
    return 0;
}