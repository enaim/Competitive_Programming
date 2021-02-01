
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        queue<Node*>Q;
        Q.push(root);
        while(!Q.empty())
        {
            Node * top = Q.front();
            Q.pop();
            cout<<top->data<<" ";
            if(top->left!=NULL)
                Q.push(top->left);
            if(top->right!=NULL)
                Q.push(top->right);
        }
    }
