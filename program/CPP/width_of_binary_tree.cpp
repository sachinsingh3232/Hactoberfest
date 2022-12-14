#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node (int value)
    {
        data = value;
        left = right = NULL;
    }
};

int width(Node *root)
{
    if(root == NULL)
        return 0;
    int w = 0;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int cnt = q.size();
        w = max(w,cnt);
        for(int i = 0; i < cnt; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
    return w;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->right = new Node(20);
    root->left->right->right= new Node(30);

    cout << width(root) << '\n';

    return 0;
}
