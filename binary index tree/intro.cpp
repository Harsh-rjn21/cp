// rightmost set bit = x & (-x)
// rightmost bit removed = x - (x & (-x))

// Every element stores partial sum

// ith element stores sum from j+1 to i th elements
// j = i - (i & (-i)) [number after removing last set bit]

// that is,
// 13 = 13->13
// 12 = 9 ->12
// 11 = 11->11
// 10 = 9 ->10

// Sum of elements 1 to 13 = bit[13] + bit[13 - (13 & -13) = 12] + bit[12 - (12 & -12) = 8] till (n - (n&-n)) > 0

// For constructing array the value in ith bit will be added in ith,
// i1 =  i + (i & -i), i2 = i1 + (i1 &n-i1), i3 = i2 + (i2 & -i2) i <= N

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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int fen_arr[100],arr[100];

void update(int n, int x){
    for(int i = n; i <= 100 ; i += (i & (-i))){
        fen_arr[i] += x;
        cout << i << "\n";
    }
}

int sum(int n){
    int s = 0;

    for(int i = n ;i > 0; i-=(i & (-i))){
        s += fen_arr[i];
    }

    return s;
}

int main(){
    CODE BY HARPREET

    for(int i = 1; i <= 100 ; i++){
        arr[i] = 1;
        update(i,arr[i]);
    }

    for(int i = 1; i <= 6 ; i++){
        cout << fen_arr[i] << " ";
    }

    cout << "\n";

    for(int i = 1; i <= 6 ; i++){
        cout << sum(i) << " ";
    }

    return 0;}


