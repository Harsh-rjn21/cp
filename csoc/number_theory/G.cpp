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

    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    while(a!=0 && b!=0){
        if(a>=b){
        ans += a/b;
        a = a%b;
        }
        else{
        ans += b/a;
        b = b%a;
        }
    }

    cout << ans;

    return 0;}