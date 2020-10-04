#include<stdio.h>

struct node{
    int roll;
    node *next;
};
node *root = NULL;

void append(int roll)
{
    if(root==NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
        return;
    }
    node *current_node = root;
    while(current_node->next!=NULL)
        current_node = current_node->next;
    node* temp = new node();
    temp->roll = roll;
    temp->next = NULL;
    current_node->next = temp;
    return;
}

void Delete(int roll)
{
    if(root==NULL)
    {
        printf("Root is NULL\n");
        return;
    }
    if(root->roll == roll)
    {
        node *temp = root;
        root = root->next;
        delete(temp);
        return;
    }
    node *current_node = root;
    node *previous_node = NULL;

    while(current_node->roll != roll && current_node->next!=NULL)
    {
        previous_node=current_node;
        current_node = current_node->next;
    }
    if(current_node->roll!=roll)
    {
        printf("Roll didn't found\n");
        return;
    }
    previous_node->next = current_node->next;
    delete(current_node);
}

void Insert(int roll,int pos)
{
    if(pos==1)
    {
        node *temp = new node();
        temp->roll = roll;
        temp->next = root;
        root = temp;
        return;
    }
    int cnt = 0;
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node!=NULL && cnt<pos-1)
    {
        cnt++;
        previous_node=current_node;
        current_node = current_node->next;
    }
    if(cnt<pos-1)
    {
        printf("Undeclared position\n");
        return;
    }
    if(current_node==NULL)
        printf("Insert in last position\n");
    node *temp = new node();
    temp->roll = roll;
    temp->next = current_node;
    previous_node->next = temp;
}

void print()
{
    node *current_node = root;
    while(current_node!=NULL)
    {
        printf("%d ",current_node->roll);
        current_node = current_node->next;
    }
    printf("\n");
}

int main()
{
    Delete(40);

    printf("\n");
    append(10);
    append(20);
    append(30);
    print();

    printf("\n");
    Insert(60,4);
    print();

    printf("\n");
    Delete(20);
    print();

    printf("\n");
    Delete(40);

    printf("\n");
    Insert(15,2);
    print();

    printf("\n");
    Insert(5,1);
    print();

    printf("\n");
    Insert(40,5);
    print();

    printf("\n");
    Insert(70,10);

    return 0;
}
