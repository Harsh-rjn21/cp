/*
    Divide the size of array, by 2
    That is make a binary tree which stores the query for size of array divided by 2;
    Eg sum query for array 1,2,3,4,5;
                            (1-5)15
                        (1-2)3     (3-5)12
                     (1)1  (2)2   (3)3  (4-5)9
                                    (4)4    (5)5  
*/

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


int arr[100007],tree[400007];

void build(int node, int start, int end){
    if(start==end){
        tree[node] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int& left, int& right){
    // cout << node << "\n";
    if(end<left || start>right){
        return 0;
    }
    if(left<=start && right>=end){
        return tree[node];
    }

    int mid = (start+end)/2;
    int q1 = query(2*node,start,mid,left,right);
    int q2 = query(2*node+1,mid+1,end,left,right);
    return (q1+q2);
}

void update(int node, int start, int end, int pos, int num){
    if(pos > end || pos < start)return;
    if(start==end){
        tree[node]+=num;
        arr[pos]+=num;
        return;}
    tree[node] += num ;
    int mid = (start+end)/2;
    if(pos>mid)update(2*node+1,mid+1,end,pos,num);
    else update(2*node,start,mid,pos,num);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)cin >> arr[i];

    build(1,0,n-1);

    for(int i=1; i <= 4*n; i++)cout << tree[i] << " ";

    // while(true){
    //     int x;
    //     cin >> x;

    //     if(x==-1)break;

    //     int l,r;
    //     cin >> l >> r;

    //     cout << query(1,0,n-1,l,r) << "\n";

    // }

    update(1,0,n-1,1,5);
    cout << "\n";
    for(int i=1; i <= 4*n; i++)cout << tree[i] << " ";
    cout << "\n";

    return 0;}