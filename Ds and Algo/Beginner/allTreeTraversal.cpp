#include<bits/stdc++.h>
using namespace std;

//a node of tree
class node{

public:
int data;
node *left = NULL;
node *right = NULL;

node(int ele)
 {
    data=ele;
    left=NULL;
    right=NULL;
 }
};

//build the tree
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

//finding the height of tree
int height(node *root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

//preorder traversal of tree
void preOrder(node *root)
{
    if(root == NULL)
    return;

    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);

}

//inorder traversal of tree
void inOrder(node *root)
{
    if(root == NULL)
    return;

    preOrder(root->left);
    cout<<root->data<<endl;
    preOrder(root->right);

}

//postorder traversal of tree
void postOrder(node *root)
{
    if(root == NULL)
    return;

    preOrder(root->left);
    preOrder(root->right);

    cout<<root->data<<endl;

}


//level order traversal of tree
void levelOrder(node *root ,int k)
{
    if(root == NULL)
    return;

    if(k == 1)
    {
        cout<<root->data<<endl;
    }

    if( k > 1)
    {
        levelOrder(root->left,k-1);
        levelOrder(root->right,k-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout<<"Enter the nodes of the tree (make sure to enter -1 for the child of terminal nodes)";
    node*root = buildTree();
    int h = height(root);//finding the height of tree

    preOrder(root);
    cout<<endl;

    inOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    for(int i=1;i<=h;i++)
    {
        levelOrder(root,i);
    }

    return 0;
}
