/*
In this problem, you need to add to the segment tree the operation of finding the k-th one.
Input
The first line contains two numbers n and m (1≤n,m≤100000), the size of the array and the number of operations. The next line contains n numbers ai, the initial state of the array (ai∈{0,1} ). The following lines contain the description of the operations. The description of each operation is as follows:

1 i: change the element with index i to the opposite.
2 k: find the k-th one (ones are numbered from 0, it is guaranteed that there are enough ones in the array).
Output
For each operation of the second type, print the index of the corresponding one (all indices in this problem are from 0).

Example
inputCopy
5 7
1 1 0 1 0
2 0
2 1
2 2
1 2
2 3
1 0
2 0
outputCopy
0
1
3
3
1
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

void update(int node, int start, int end,int pos,bool inc){
    if(start==end){
        arr[start] = inc ? 1 : 0;
        tree[node] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    if(pos<=mid){
        update(2*node,start,mid,pos,inc);
    }
    else{
        update(2*node+1,mid+1,end,pos,inc);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start,int end, int k){
    if(start==end){
        return start;
    }
    int mid = (start+end)/2;
    if(tree[2*node]>=k){
        return query(2*node,start,mid,k);
    }
    else{
        return query(2*node+1,mid+1,end,(k-tree[2*node]));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,q;
    cin >> n >> q;

    rp(i,0,n)cin >> arr[i];

    build(1,0,n-1);

    // rp(i,1,4*n)cout << tree[i] << " ";

    while(q--){
        int x,y;
        cin >> x >> y;
        if(x==2){cout << query(1,0,n-1,y+1) << "\n";}
        else if(x==1){
            bool inc = (arr[y]==1) ? false : true;
            update(1,0,n-1,y,inc);
            }
    }

    return 0;}