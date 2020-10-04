#include<stdio.h>

struct node{
    int roll;
    node *next;
    node *prev;
};
node *root = NULL;
node *tail = NULL;

void append(int roll)
{
    if(root==NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
        root->prev = NULL;
        tail = root;
        return;
    }
    node* temp = new node();
    temp->roll = roll;
    temp->next = NULL;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
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
        root->prev = NULL;
        if(tail==temp)
            tail = NULL;///tail = root also works
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
    node *temp1 = current_node->next;
    node *temp2 = previous_node;
    temp2->next = temp1;
    temp1->prev = temp2;
    if(tail==current_node)
        tail = current_node->prev;
    delete(current_node);
}

void Insert(int roll,int pos)
{
    if(pos==1)
    {
        node *temp = new node();
        temp->roll = roll;
        temp->next = root;
        temp->prev = NULL;
        root->prev = temp;
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
    {
        printf("Insert in last position\n");
        append(roll);
        return;
    }
    node *temp = new node();
    temp->roll = roll;
    temp->next = current_node;
    temp->prev = current_node->prev;
    previous_node->next = temp;
    current_node->prev = temp;

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
    Insert(60,6);
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

    printf("\n");
    Insert(100,10);

    return 0;
}
