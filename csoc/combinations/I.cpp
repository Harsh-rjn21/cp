#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

float power(float a, int b){
    float ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans * a);}
        a = (a*a);
        b >>= 1;}
    return ans;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    float m;int n;
    cin >> m >> n ;

    float ans = 0;

    for(float i =1; i<=m;i++){
        ans += i*(power(i/m,n)-power((i-1)/m,n));
    }

    cout << setprecision(10) << ans;

    return 0;}