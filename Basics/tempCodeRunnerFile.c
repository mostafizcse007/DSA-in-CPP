#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    int count = 0;
    if (head == NULL)
    {
        printf("The list is empty");
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;

    printf("%d/n", head->next);
    printf("%d/n", temp);
}
int main()
{
    struct node *head, *body, *leg;
    head = malloc(sizeof(struct node));
    body = malloc(sizeof(struct node));
    leg = malloc(sizeof(struct node));

    head->data = 45;
    head->next = NULL;

    body->data = 69;
    body->next = NULL;

    leg->data = 3;
    leg->next = NULL;

    head->next = body;
    body->next = leg;

    display(head, 65);

    return 0;
}