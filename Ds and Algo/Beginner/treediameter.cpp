#include<bits/stdc++.h>
using namespace std;

class node {

 public:
 int data;
 node *left;
 node *right;

 node(int data)
 {
    this->data = data;
    left = NULL;
    right = NULL;
 }
};


node *buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    return NULL;

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int height(node *root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

int diameter(node *root)
{
    if(root == NULL)
    return 0;

    int d = height(root->left) + height(root->right);
    int l1 = diameter(root->left);
    int l2 = diameter(root->right);

    return max(d,max(l1,l2));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    node * root = buildTree();


    cout<<"DIAMETER: "<<diameter(root);

    return 0;
}
