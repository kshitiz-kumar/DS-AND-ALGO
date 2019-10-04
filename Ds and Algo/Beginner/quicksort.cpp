#include<bits/stdc++.h>
using namespace std;


int partition(int arr[] , int l , int h)
{
    int piv = arr[h];
    int i=l-1;

    for(int j=l ; j<=h-1 ; j++)
    {
        if(arr[j] < piv)
        {
         i++;
         swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1], arr[h]);

    return i+1;
}


void quicksrt(int arr[], int l, int h)
{
    while(l < h)
    {
        int pi =  partition ( arr, l , h);

        quicksrt(arr, l , pi);
        quicksrt(arr, pi+1 , h);
    }
}

int main()
{
 ios_base::sync_with_stdio(false);

 cin.tie(0);
 cout.tie(0);


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

    quicksrt(arr,0,n-1);

 return 0;
}
