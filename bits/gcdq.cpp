#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int af[1000];
int ab[1000];

//a2d[1000][1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n+2];
    arr[0] = 0;
    arr[n+1] = 0;
    for(int i = 1; i<=n ; i++){
        cin>>arr[i];
    }

    for(int i = 1; i<=n;i++){
        cin>>x;
        af[i] = __gcd(af[i-1],arr[i]);
        ab[n-i] = __gcd(ab[n-i+1],arr[n-i]);
    }

    int l,r;
    cin>>l>>r;

    cout<<__gcd(af[l-1],ab[r+1]);

    // a2d[i][j] = __gcd(__gcd(a2d[i-1][j],a2d[i][j-1]),arr[i][j]);

    return 0;}