#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    int a = 0,m=n.length();

    if(m==1){
        a += (n[0]-'0');
    }
    else{
        a+=((n[m-2]-'0')*10 + (n[m-1]-'0'));
    }

    int p = a%4;

    int ans = (1LL + power(2,p,5) + power(3,p,5) + power(4,p,5) )%5;

    cout << ans;

    return 0;}