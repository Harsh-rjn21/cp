//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
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

int arr[100007];
pii tree[400007];

void build(int node, int start, int end){
    if(start==end){
        tree[node].f = arr[start];
        tree[node].s = 1;
        return;
    }
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node].f = min(tree[2*node].f,tree[2*node+1].f);
    tree[node].s = 0;
    if(tree[node].f==tree[2*node].f)tree[node].s+=tree[2*node].s;
    if(tree[node].f==tree[2*node+1].f)tree[node].s+=tree[2*node+1].s;
}

pii query(int node, int start, int end, int left, int right){
    if(left>end || start>right)return make_pair(INT_MAX,0);
    if(start>=left && right>=end)return tree[node];

    int mid = (start+end)/2;
    pii q1 = query(2*node,start,mid,left,right);
    pii q2 = query(2*node+1,mid+1,end,left,right);
    int ans = min(q1.f,q2.f);
    int cnt = 0;
    
    if(ans==q1.f)cnt+=q1.s;
    if(ans==q2.f)cnt+=q2.s;
    
    return make_pair(ans,cnt);
}

void update(int node, int start, int end, int pos, int num){
    if(start==end){
        arr[start] = num;
        tree[node] = {num,1};
        return;
    }
    int mid = (start+end)/2;
    if(pos<=mid){
        update(2*node,start,mid,pos,num);
    }
    else{
        update(2*node+1,mid+1,end,pos,num);
    }

    tree[node].f = min(tree[2*node].f,tree[2*node+1].f);
    tree[node].s = 0;
    if(tree[node].f==tree[2*node].f)tree[node].s+=tree[2*node].s;
    if(tree[node].f==tree[2*node+1].f)tree[node].s+=tree[2*node+1].s;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> arr[i];

    build(1,0,n-1);
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        if(x==1){
            update(1,0,n-1,y,z);
        }
        else if(x==2){
            auto ans = query(1,0,n-1,y,z-1);
            cout << ans.f << " " << ans.s << "\n";
        }
    }

    return 0;}