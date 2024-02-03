#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int dp[21];

ull fact(int n){
    if(n==1 || n==0) return 1;
    if(dp[n]!=-1)return dp[n];
    return n*fact(n-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    string a,b;

    cin >> a >> b;

    int ap = 0,bp=0, bq=0, n = a.length();

    for(int i = 0; i < n; i++) {
        if(a[i]=='+')ap++;
        if(b[i]=='+')bp++;
        if(b[i]=='?')bq++;
    }

    int total = 1<<bq;
    int diff = ap-bp;
    
    ull num = (diff>=0 && diff<=bq) ? fact(bq)/(fact(diff)*fact(bq-diff)) : 0;

    cout << setprecision(10) << (float)num/total;

    return 0;}