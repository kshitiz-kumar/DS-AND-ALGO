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

int main()
{
    ios;

    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

       long long int a[n+1],sum=0;
        map<int,int>mp;

        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                if(mp.find(a[i]) == mp.end())
                {
                    mp[a[i]]=i;
                }

                sum+=a[i];
        }

     if(sum % n != 0)
     {
        cout<<"Impossible"<<endl;
        continue;
     }


    else{

    int r = sum/n;
    int g = r * (n-1);
    int ans = sum - g;

    if(mp.find(ans) != mp.end())
    {
        cout<<mp[ans]<<endl;
    }

    else
    {
        cout<<"Impossible"<<endl;
    }
 }

}

    return 0;

}
