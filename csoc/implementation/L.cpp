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

    int n,k,m,t;

    cin >> n >> k >> m >> t ;

    while(t--){
        int a,b;
        cin >> a >> b ;
        if(a == 0){
            int r = b + 1;
            if(k<=b){
                n-=(n-b);
            }
            if(k>=r){
                n-=b;
                k-=b;
            }
        }
        if(a==1){
            if(b<=k){
                n++;
                k++;
            }
            if(k<b){
                n++;
            }
        }
        cout << n << " " << k << "\n";
    }

    return 0;}