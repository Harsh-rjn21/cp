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

class solution{
    public:
    int sum;
    int preffix;
    int suffix;
    int ans;
};

int arr[100007];
solution tree[400007];

void build(int node, int start, int end){
    if(start==end){
        tree[node].sum = arr[start];
        tree[node].preffix = max(arr[start],0LL);
        tree[node].suffix = max(arr[start],0LL);
        tree[node].ans = max(arr[start],0LL);
        return;
    }

    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);

    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    tree[node].preffix = max(tree[2*node].preffix, tree[2*node].sum+tree[2*node+1].preffix);
    tree[node].suffix = max(tree[2*node].suffix + tree[2*node+1].sum ,tree[2*node+1].suffix);
    tree[node].ans = max(tree[2*node].ans,tree[2*node+1].ans);
    tree[node].ans = max(tree[node].ans,tree[2*node].suffix+tree[2*node+1].preffix);
}

void update(int node, int start, int end, int pos, int num){
    if(start>pos || pos>end)return;
    
    if(start==end){
        arr[start] = num;
        tree[node].sum = arr[start];
        tree[node].preffix = max(arr[start],0LL);
        tree[node].suffix = max(arr[start],0LL);
        tree[node].ans = max(arr[start],0LL);
        return;
    }
    
    int mid = (start+end)/2;

    if(pos<=mid){
        update(2*node,start,mid,pos,num);
    }
    else{
        update(2*node+1,mid+1,end,pos,num);
    }

    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    tree[node].preffix = max(tree[2*node].sum + tree[2*node+1].preffix, tree[2*node].preffix) ;
    tree[node].suffix = max(tree[2*node+1].sum + tree[2*node].suffix ,tree[2*node+1].suffix);
    tree[node].ans = max(tree[2*node].ans , tree[2*node+1].ans);
    tree[node].ans = max(tree[node].ans, tree[2*node+1].preffix + tree[2*node].suffix);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,n)cin >> arr[i];

    build(1,0,n-1);

    cout << tree[1].ans << "\n";

    while(m--){
        int i,v;
        cin >> i >> v;
        update(1,0,n-1,i,v);
        cout << tree[1].ans << "\n";
    }

    return 0;}