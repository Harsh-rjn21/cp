#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m,k;
    cin >> n >> m >> k;

    // int desire[n],apartment[m];
    deq desire(n);
    set<int> apartment;
    mii cnt;
    
    rp(i,0,n)cin >> desire[i];
    rp(i,0,m){
        int x;
        cin >> x;
        cnt[x]++;
        apartment.insert(x);
    }

    sort(all(desire));
    // sort(all(apartment));

    int i = 0, j = 0, ans = 0;

    rp(i,0,n){
        int x = desire[i]-k>=0 ? desire[i]-k : 0;
        auto itr = apartment.lower_bound(x);
            while(itr!=apartment.end()){
                int z = *itr;
                if(abs(z-desire[i])>k){
                    break;
                }
                ++itr;
                if(cnt[z]!=0){
                    cnt[z]--;
                    ++ans;
                    if(cnt[z]==0){
                        apartment.erase(z);
                    }
                    break;
                }
        }
    }

    cout << ans << endl;

    return 0;}