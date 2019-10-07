#include<bits/stdc++.h>
using namespace std;

void merge(int arr[] , int l , int m , int r)
{
    int l1 = m - l;
}

void mergeSort(int arr[] , int l , int r)
{
  while(l<r)
  {
    int m = l+ (r-l)/2;

    mergeSort(arr,l,m);

    mergeSort(arr,m+1,r);

    merge(arr,l,m,r);
  }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;

    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int arr[n+1];

    cout<<"Enter the elements"<<endl;

    for(int i=0;i<n;i++)
    {
     cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    return 0;

}
