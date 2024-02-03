#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

string convert_to_binary(int num){
    int i = 0;
    string ans = "";
    while((1<<i)<=num){
        if(((1<<i)&num) != 0){ans = "1" + ans;}
        else{ ans = "0"+ans;}
        ++i;
        
    }
    return ans;
}

int set_bit(int num,int n){
    return ((1<<n) | num);
}

int unset_bit(int num,int n){
    return ((~(1<<n))&num);
}

int toggle_bit(int num,int n){
    return ((1<<n)^num);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // if bit = 1, means it is set
    // if bit = 0, means it is unset

    int num;
    cin>>num;
    int n;
    cin>>n;
    cout<<convert_to_binary(num)<<"\n";
    cout<<set_bit(num,n)<<"\n";
    cout<<unset_bit(num,n)<<"\n";
    cout<<toggle_bit(num,n)<<"\n";
    cout<<"Set bit count = "<<__builtin_popcount(num)<<"\n";
    return 0;}