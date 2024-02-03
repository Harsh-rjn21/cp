/*
    HACKERRANK ARRAY MANIPULATION
    Given: n-sized array of zeros
    q queries with initial,final,number
    in each query add number from initial to final in the array

    Find: Maximum element
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

const ll N = 1000007;
ll arr[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int q;
    cin>>q;

    while(q--){
        int l,r,num;
        cin>>l>>r>>num;

        arr[l-1] += num;
        arr[r] -= num;
    }

    ll prefix[n] = {0};
    prefix[0] = arr[0];

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    ll maxi = prefix[0];
    for(int i = 1; i < n; i++){
        if(prefix[i] > maxi)maxi=prefix[i];
    }

    cout<<maxi;

    return 0;}