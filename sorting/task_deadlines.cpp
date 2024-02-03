/*
Consider a problem where we are given n tasks with durations and deadlines
and our task is to choose an order to perform the tasks. For each task, we earn d − x
points where d is the task’s deadline and x is the moment when we finish the task.
What is the largest possible total score we can obtain?
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
    pii duration_deadline[n];

    rp(i,0,n){
        cin >> duration_deadline[i].f >> duration_deadline[i].s;
    }

    sort(duration_deadline,duration_deadline+n);

    int passed = 0,ans = 0;

    rp(i,0,n){
        ans+=(duration_deadline[i].s - duration_deadline[i].f -passed);
        passed+=duration_deadline[i].f;
    }

    cout << ans << "\n";

    return 0;}

    /*
    It turns out that the optimal solution to the problem does not depend on the
deadlines at all, but a correct greedy strategy is to simply perform the tasks sorted
by their durations in increasing order. The reason for this is that if we ever perform
two tasks one after another such that the first task takes longer than the second task,
we can obtain a better solution if we swap the tasks
    */