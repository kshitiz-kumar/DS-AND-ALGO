#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

class pairs{

    public :
    int height,diameter;
};

int height(node *root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}

node *buildTree()
{
  int d;
  cin>>d;
  if(d == -1)
  return NULL;

  node *root = new node(d);

  root->left = buildTree();
  root->right = buildTree();

  return root;
}

pairs optimizedDiameter(node *root)
{
    pairs p;
    if(root == NULL)
    {
      p.height = p.diameter = 0;
      return p;
    }

    pairs left = optimizedDiameter(root->left);
    pairs right = optimizedDiameter(root->right);

    p.height = max( left.height , right.height  )+1;

    p.diameter = max( left.height+right.height,max(left.diameter,right.diameter));

    return p;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    node *root = buildTree();

    pairs dia = optimizedDiameter(root);

    cout<<"Optimized Diameter "<<dia.diameter;

    return 0;
}
