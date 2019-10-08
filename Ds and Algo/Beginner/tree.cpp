#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

    vector< pair <int,char> > vec[1000+10];

typedef struct node{

    int val;
    string str;

    struct node *left, *right;
}node;


node *newnode(int v)
{
  node *temp =(node*)malloc(sizeof(node));
  temp->val = v;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void constructTree( node *root,int n)
{
  queue< node *>q;

  q.push(root);

  while(!q.empty())
  {
      node *r = q.front();
      int ele = r->val;
      q.pop();

      for(int i=0;i<vec[ele].size();i++)
      {
          int element = vec[ele].first;
          char pos = vec[ele].second;

          node *newn = newnode(element);

          if( pos == 'L')
          {
              r->left = newn;
          }

          else
          {
              r->right = newn;
          }
      }
  }


}

int main()
{
    ios;

    int n,q;
    cin>>n>>q;


    for(int i=1;i<n-1;i++)
    {
        int p,c;
        char pos;

        cin>>p>>c>>pos;

        vec[p].push_back(make_pair(c,pos));
    }

    node *root = newnode(1);

    constructTree(root,n);

    return 0;

}
