/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8

Example 2:
Input: a = 2, b = [1,0]
Output: 1024

Example 3:
Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
 
Constraints:
1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1337;
using namespace std;

int arr[2001];

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    arr[0] = 1;

    int a,n;
    cin>>a;
    cin>>n;

    int b[n];
    for(int i =0; i < n; i++){
        cin>>b[i];
    }

    int m = 6*190;
    for(int i = 1; i<=n; i++){
        arr[i] = (arr[i-1] * 10)%m;
    }
    int exponent = 0;

    for(int i = 0; i<n; i++){
        exponent += (((b[n-i-1]%m) * (arr[i]%m))%m);
    }

    cout<<power(a,exponent);

    return 0;}