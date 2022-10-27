#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};
node *buildBT(node *root)
{
    cout << "enter data: ";
    int d;
    cin >> d;
    root = new node(d);
    if (d == -1)
        return NULL;
    cout << "enter left node of " << d << " ";
    root->left = buildBT(root->left);
    cout << "enter right node of " << d << " ";
    root->right = buildBT(root->right);
}
void count(node *root,int &c)
{
    
    if(root==NULL)
    return ;
    count(root->left,c);
    if(root->left==NULL && root->right==NULL)
    c++;
    count(root->right,c);
}
int main()
{
node * root=NULL;
root=buildBT(root);
int c=0;
count(root,c);
cout<<c;
}
