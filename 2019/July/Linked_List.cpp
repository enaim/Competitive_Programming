#include<stdio.h>

struct node{
    int roll;
    node *next;
};
node *root=NULL;

void append(int roll)
{
    if(root==NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
    }
    else
    {
        node *current_node = root;
        while(current_node->next!=NULL)
        {
            current_node = current_node->next;
        }
        node *newNode = new node();
        newNode->roll = roll;
        newNode->next = NULL;
        current_node->next = newNode;
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
        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;
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
    previous_node->next = newNode;
}

void print()
{
    node *current_node = root;
    while(current_node != NULL)
    {
        printf("%d ",current_node->roll);
        current_node = current_node->next;
    }
    printf("\n");
}

int main()
{
    append(10);
    append(20);
    append(30);
    print();

    Delete(20);
    print();

    Insert(15,2);
    Insert(5,1);
    Insert(40,5);
    print();

    return 0;
}
