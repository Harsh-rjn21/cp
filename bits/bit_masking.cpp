#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int bit_mask(int arr[],int n){
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = ans | (1<<arr[i]);
    }

    return ans;
}

string num_to_bits(int num){
    int n = 0;
    string ans = "";

    while(num>=(1<<n)){
        if(((1<<n)&num)!=0){ans = "1"+ans;}
        else{ans = "0"+ans;}
        ++n;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[] = {2,3}; int na = 2;
    int b[] = {0,1,2}; int nb = 3;
    int c[] = {1,3}; int nc = 2;

    int bita = bit_mask(a,na);
    int bitb = bit_mask(b,nb);
    int bitc = bit_mask(c,nc);

    cout<<bita<<"\n";
    cout<<bitb<<"\n";
    cout<<bitc<<"\n";

    cout<<num_to_bits(bita & bitb)<<"\n";
    cout<<num_to_bits(bitb & bitc)<<"\n";
    cout<<num_to_bits(bitc & bita)<<"\n";

    return 0;}