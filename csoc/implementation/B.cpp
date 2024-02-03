#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    int arr[m];

    for(int i=0; i<m; i++){
        cin >> arr[i];
    }

    int x = 1;
    ll ans = 0;

    for(int i=0; i<m; i++){
        if((arr[i] - x)>=0){
            ans += (arr[i] - x);
            x = arr[i];
        }
        else{
            ans+=(arr[i]-x+n);
            x = arr[i];
        }
    }

    cout << ans;

    return 0;}