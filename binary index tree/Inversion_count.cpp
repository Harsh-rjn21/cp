// 1,2,3,4,5,6, given in array
// Find number of pairs such that a[i] > a[j] and  i < j

// We can solve using fenwich tree in n*log(n)
// Make hash array which stores count of each element
// Then during each insertion of element just calculate (fenwick[maxi] - fenwick[n]) then update in the hash array

// Eg - Array = 8,4,9,2,8

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int hash_arr[100007],fen_arr[100007];

void update(int n,int x){
    for(int i=n ; i<=100000;i+=(i & (-i))){
        fen_arr[i]+=x;
    }
}

int sum(int n){
    int s = 0;
    for(int i=n ; i>0;i-=(i & (-i))){
        s+=fen_arr[i];
    }
    return s;
}

int main(){
    CODE BY HARPREET

    int n;
    cin >> n;

    ll ans = 0;

    for(int i = 1; i<=n; i++){
        ll x;
        cin >> x;

        ans += (sum(100000) - sum(x));
        hash_arr[x]++;
        update(x,1);
    }

    cout << ans << "\n";

    return 0;}