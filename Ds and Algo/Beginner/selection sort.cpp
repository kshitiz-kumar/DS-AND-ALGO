#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	int a[n+1];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		int pos=i;
		int min=a[i];
		for(int j=i+1;j<=n-1;j++)
		{
			if(a[j]<min)
			{
				pos=j;
				min=a[j];
			}
		}
		
		a[pos]=a[i];
		a[i]=min;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
