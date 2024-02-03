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

    int test;
    cin >> test;
    while(test--){
    int n,T,req[2],cntB=0,cntA=0;

    cin >> n >> T >> req[0] >> req[1];

    int diff[n];

    for(int i=0;i<n;i++){
        cin >> diff[i];
        if(diff[i])cntB++;
        else cntA++;
        }

    deque<pii> times;

    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        times.push_back({a,diff[i]});
    }
    times.push_back({T+1,0});
    ll ans = 0;

    sort(times.begin(), times.end());
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= n; i++) {
            ll need = cnt1 * req[0] + cnt2 * req[1];
            ll has = times[i].first - 1 - need;
            if (has >= 0) {
                ll canA = min((cntA - cnt1), has / req[0]);
                has -= canA * req[0];
                ll canB = min((cntB - cnt2), has / req[1]);
                ans = max(ans, cnt1 + cnt2 + canA + canB);
            }
            int l = i;
            while (l < times.size() && times[l].first == times[i].first) {
                if (times[l].second) {
                    cnt2++;
                } else {
                    cnt1++;
                }
                l++;
            }
            i = l - 1;
        }

     cout << ans << "\n";
    }

    return 0;}
// 7 17 1 6
// 1 1 0 1 0 0 0
// 1 7 0 11 10 15 10

// 0 1 1 0  0  1  0 
// 0 1 7 10 10 11 15

// 6 17 2 6
// 0 0 1 0 0 1
// 7 6 3 7 10 12

// 1 0 0 0 0   1
// 3 6 7 7 10  12