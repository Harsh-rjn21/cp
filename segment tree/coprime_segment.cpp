/*
Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if the GCD of all numbers on this segment is 1. Your task is to find the shortest good segment.

Input
The first line contains an integer n (1≤n≤105). The second line contains integers ai (1≤ai≤1018).

Output
Print one number, the minimum length of a good segment. If there is no good segment, print −1.

Example
inputCopy
5
4 6 9 3 6
outputCopy
3
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

int arr[100007],tree[100007];

void build(int node, int start, int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = __gcd(tree[2*node],tree[2*node+1]);
}

int solve(int node, int start, int end){
    if(tree[node]!=1){
        return INT_MAX;
    }
    int mid = (start+end)/2;
          
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    

    return 0;}