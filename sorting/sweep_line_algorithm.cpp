/*
 suppose that there is a restaurant and we know the
arriving and leaving times of all customers on a certain day. Our task is to find out
the maximum number of customers who visited the restaurant at the same time.
For example, Fig. 4.7 shows an instance of the problem where there are four
customers A, B, C, and D. In this case, the maximum number of simultaneous
customers is three between A’s arrival and B’s leaving.
To solve the problem, we create two events for each customer: one event for
arrival and another event for leaving. Then, we sort the events and go through them
according to their times. To find the maximum number of customers, we maintain
a counter whose value increases when a customer arrives and decreases when a
customer leaves. The largest value of the counter is the answer to the problem
*/
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    pii arr[n];
    mii m;

    rp(i,0,n){
        cin >> arr[i].f >> arr[i].s;
        m[arr[i].f]++;
        m[arr[i].s]--;
    }

    int cnt = 0,ans = 0;
    
    for(auto i : m){
        cnt+=i.s;
        ans = max(ans,cnt);
        cout << i.f << " => " << cnt << "\n";
    }

    cout << "Ans: " << ans << "\n";

    return 0;}
/*
Solution - Jab koi enter hua us time pr + exit pr -.
            Jab bhi changes ho rahe h logo mein us time pr count update krte jaao.
            YOu will get the maximum count.
*/