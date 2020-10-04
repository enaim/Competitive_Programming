#include<stdio.h>


struct node{
    int roll;
    node *next,*prev;
};

node *root=NULL;
node *tail=NULL;

void append(int roll)
{
    if(root==NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
        root->prev = NULL;
        tail = root;
    }
    else
    {
        node *temp = new node();
        temp->roll = roll;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void Delete(int roll)
{
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node->roll != roll)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node==root)
    {
        node *temp = root;
        root = root->next;
        root->prev = NULL;
        if(tail==temp)
            tail = root;
        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;
        node *temp = current_node->next;
        temp->prev = previous_node;
        delete(current_node);
    }
}

void Insert(int roll,int pos)
{
    if(pos==1)
    {
        node *tmp = root;
        node *temp = new node();
        temp->roll = roll;
        temp->next = tmp;
        temp->prev = NULL;
        tmp->prev = temp;
        root = temp;
        return;
    }
    int cnt = 0;
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node != NULL && cnt<pos-1)
    {
        cnt++;
        previous_node = current_node;
        current_node = current_node->next;
    }
    node *newNode = new node();
    newNode->roll = roll;
    newNode->next = current_node;
    newNode->prev = previous_node;
    previous_node->next = newNode;
    current_node->prev = newNode;
}

void print()
{
    printf("From Left to Right - > ");
    node *current_node = root;
    while(current_node != NULL)
    {
        printf("%d ",current_node->roll);
        current_node = current_node->next;
    }
    printf("\n");
}

void ReversePrint()
{
    printf("From Right to Left - > ");
    node *previous_node = tail;
    while(previous_node != NULL)
    {
        printf("%d ",previous_node->roll);
        previous_node = previous_node->prev;
    }
    printf("\n");
}

int main()
{
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    print();
    ReversePrint();

    printf("\n");
    Delete(10);
    print();
    ReversePrint();

    printf("\n");
    Delete(40);
    print();
    ReversePrint();

    printf("\n");
    Insert(10,1);
    print();
    ReversePrint();

    printf("\n");
    Insert(40,4);
    print();
    ReversePrint();

    return 0;
}
