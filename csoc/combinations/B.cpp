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

    int a,b,c,d;
    cin >> a >> b >> c >> d ;

    float x = (float)a/b;
    float y = (float)c/d;

    float deno = 1 - ((1-x) * (1-y));

    cout << setprecision(10) << x/deno;

    return 0;}