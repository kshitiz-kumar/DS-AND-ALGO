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

void bfs(node *root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node *ele = q.front();
        q.pop();

        cout<<ele->data<<" ";

        if(ele->left)
        q.push(ele->left);

        if(ele->right)
        q.push(ele->right);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    node *root = buildTree();

    bfs(root);

    return 0;
}
