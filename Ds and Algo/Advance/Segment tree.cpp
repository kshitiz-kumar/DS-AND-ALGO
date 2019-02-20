/*
This code is an example of segment trees

Segment Tree is used in cases where there are multiple range queries on array and modifications of elements of the same array. 
For example, finding the sum of all the elements in an array from indices  to , or finding the minimum (famously known as Range
Minumum Query problem) of all the elements in an array from indices  to . These problems can be easily solved with one of the 
most versatile data structures, Segment Tree.
*/

/* Here you will see how to build a segment tree, how to update the array and hence the segment tree and also how to query for sum
over a range */

/* The total time complexity for build is O(n), for updation O(logn) and for query over a range O(logn)*/

#include<bits/stdc++.h>//this particular header file is the root of all the header file
using namespace std;

/* The build() function will build an array tree[] , which is the segment tree 

this particular segment tree is a Binary Tree in which the leaves of this binary tree are the elements of the input array

*/
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

/* The update function will do the updation operation in O(logn) time
  here the array[] is updated to new value val at the index idx
  Hence the segment tree is updated 
 */

void update(int node,int start,int end,int val,int idx,int array[],int tree[],int size)
{
	if(start==end)//if the leaf nodes are found update the array and the segment tree there
	{
		array[idx]=val;
		tree[node]=val;
	}
	
	else
	{
		int mid = (start+end)/2;//finding the mid
		
		if(idx>=start && idx<=mid)//if the index lie in the left subtree
		{
			update(2*node,start,end,val,idx,array,tree,size);
		}
		
		else//if the index lie in the right subtree
		{
			update(2*node+1,start,end,val,idx,array,tree,size);
		}
		
		tree[node]=tree[2*node]+tree[2*node+1];//when the childs are updated finally updating the segment tree
	}
}

/* The query() function will provide the the sum of the array in the range l to r

Time complexity for this will be O(logn)*/

int query(int node,int start,int end,int l,int r,int array[],int tree[],int n)
{
	
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
	
	int val,idx;
	cin>>val>>idx;//taking the value val to be updated at index idx
	
	update(1,start,end,val,idx,array,tree,n);//updating the array[] and hence the segment tree tree[]
	
	int l,r;
	cin>>l>>r;//the range for which the sum is to be eavluated 
	int sum=query(1,start,end,l,r,array,tree,n);// getting the sum
	
	return 0;
}
