/* This Algorithm is a continuation of the previous algorithm:-Segment Tree 
"IF NOT SEEN I SUGGEST YOU TO FIRST HAVE A LOOK AT IT"

So, this algorithm is Lazy propagation with Segment Tree and the main idea behind this 
is as follows:-When there are many updates and updates are done on a range, we can postpone 
some updates (avoid recursive calls in update) and do those updates only when required.

Sometimes it is not necessary to update all the nodes covering the range. As a consequence of this 
our algorithm will be able to save a lot of time. The algorithm will update the nodes only when necessary.
*/


#include<bits/stdc++.h>//this particular header file is the root of all the header file
using namespace std;

int Lazytree[1000]={0};//this array is the shadow of the tree[] array as it will store the pending updates to be done on tree[]
//initially Lazytree[] will have all the values as zero in it. This indicates that there is no node in the tree[] array that is pending for updation


//this function will build the segment tree with the time complexity as O(n)
void build(int node,int start,int end,int array[],int tree[],int size)
{
	if(start==end)
	{
		tree[node]=array[start];
	}
	
	else
	{
		int mid = (start+end)/2;//finding the middle 
		build(2*node,start,mid,array,tree,size);//traversing the left child in a recursive manner
		build(2*node+1,mid+1,end,array,tree,size);//traversing the right child in a recursive manner
		
		tree[node] = tree[2*node] + tree[2*node+1];
	}
	
}

/* Here the update function is a little bit different from the update function in segment tree
here the condition for pending updates is shown. If the array to be updated  is already having a pending update 
first that thing is resolved by checing the lazytree[] array
*/
void update(int node,int start,int end,int val,int l,int r,int array[],int tree[],int size)
{
	
	if(Lazytree[node]!=0)//checking whether there is a pending update on this node 
	{
		//if there is pending update 
		tree[node]=tree[node]+(end-start)*Lazytree[node];//the segment tree is updated 
		
		if(start!=end)//if the node is not a leaf node
		{
			//the child nodes of the existing nodes are given a hint by updating them with the value of parent node
			Lazytree[2*node]+=Lazytree[node];//the left child updated from zero to Lazytree[node]
			Lazytree[2*node+1]+=Lazytree[node];//the right child updated from zero to Lazytree[node]
		}
		Lazytree[node]=0;//since the existing node is updated making the value zero in the lazy tree
	}
	
  if(start>r || l>end)//out of range 
  return;
  
  if(start<=l && r<=end)
  {
  	tree[node]+=(end-start)*val;//updating the parent node by adding new values
  	
  	if(start!=end)
  	{
  	 Lazytree[2*node]=val;
	 Lazytree[2*node+1]=val;  	
	}
	return;
  }
  
  
	int mid = (start+end)/2;//finding the middle 
	build(2*node,start,mid,array,tree,size);//traversing the left child in a recursive manner
	build(2*node+1,mid+1,end,array,tree,size);//traversing the right child in a recursive manner
		
	tree[node] = tree[2*node] + tree[2*node+1];
  
}

int query(int node,int start,int end,int l,int r,int array[],int tree[],int n)
{
	
	if(Lazytree[node]!=0)
	{
		tree[node]=tree[node]+(end-start)*Lazytree[node];
		
		if(start!=end)
		{
			Lazytree[2*node]+=Lazytree[node];
			Lazytree[2*node+1]+=Lazytree[node];
		}
		Lazytree[node]=0;
	}
	
	//so there three case for query
	
	//either the range is l to r doesn't exist in the segemnt tree
	if(r<start or l>end)
	return 0;
	
	//or the range l to r is completely in the range represented by nodes 
	if(start<=l && r<=end)
	return tree[node];
	
	
	//or the final case is the range l to r is partially in the range represented by nodes
	
	int mid = (start+end)/2;//finding the mid
	
	int p=query(2*node,start,mid,l,r,array,tree,n);//traversing the left child in a recursive manner
	int q=query(2*node+1,mid+1,end,l,r,array,tree,n);//traversing the right  child in a recursive manner
	
	return (p+q);//returning the sum over the range
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 		//here the user will input the size of array to be made
	cin>>n;
	int array[n+1],tree[2*n+1];// The array[] given by the user and tree[] is the segment tree
	for(int i=1;i<=n;i++)
	{
		cin>>array[i];
	}
	int start=1,end=n,node=1;// here start is the index of the first node and end is the index of last node.
	build(1,start,end,array,tree,n);//buiding the segment tree
	
	int val,l,r;//getting the range l to r and the value to be updated in them
	cin>>val>>l>>r;//taking the value val to be updated at index idx
	
	update(1,start,end,val,l,r,array,tree,n);//updating the array[] and hence the segment tree tree[]
	
	
	cin>>l>>r;//the range for which the sum is to be eavluated 
	int sum=query(1,start,end,l,r,array,tree,n);// getting the sum
	
	return 0;
}

