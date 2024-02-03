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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b ;

        int ans = 0;

        for(int i = 0; i < n; i++){
            if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                ans += 2;
                continue;
            }
            if( (i+1) < n && ((a[i]=='1' && b[i]=='1') && (a[i+1]=='0' || b[i+1]=='0'))){
                ans += 2;
                ++i;
                continue;
            }
            if( (i+1) < n && (a[i]=='0' && b[i]=='0') && (a[i+1]=='1' && b[i+1]=='1')){
                ans+=2;
                ++i;
                continue;
            }
            if((a[i]=='0' && b[i]=='0')){
                ans+=1;
                continue;
            }
        }

        cout << ans <<"\n";
    }

    return 0;}