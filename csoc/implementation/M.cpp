#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;
int arr[300007];

int check(int y,int n){
    if(y==1 || y==n)return 0;
    if((arr[y]>arr[y-1] && arr[y]>arr[y+1]) || (arr[y]<arr[y-1] && arr[y]<arr[y+1]))return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arry[n+2] = {0};

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int ans = 0;
        for(int i = 2; i <= n-1; i++){
            if(check(i,n)){arry[i]=1;ans++;}
            else arry[i] = 0;
        }

        int s = ans;
        for(int i = 2; i <= n-1; i++){
            int t = arr[i];
        
                arr[i] = arr[i-1];
                ans = min(ans,s-arry[i]-arry[i-1]-arry[i+1]+check(i,n)+check(i-1,n)+check(i+1,n));
            
            
                arr[i] = arr[i+1];
                ans = min(ans,s-arry[i]-arry[i-1]-arry[i+1]+check(i,n)+check(i-1,n)+check(i+1,n));

            arr[i] = t;
        }

        cout<<ans<<"\n";
    }
    return 0;
}