#include<bits/stdc++.h>
using namespace std;

class node{

public:
int n;
node *left = NULL;
node *right = NULL;

node(int ele)
 {
    n=ele;
    left=NULL;
    right=NULL;
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

void printNode(node *root)
{
    if( root == NULL)
    return;

    cout<<root->n;
    printNode(root->left);
    printNode(root->right);

}

int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);

 node *root = buildTree();

 printNode(root);

 return 0;
}
