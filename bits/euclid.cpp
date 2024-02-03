/*
For GCD and LCM. Euclid Division Algorithm
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    if(a==b) return a;
    return (a*b)/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b;

    cin>>a>>b;

    cout<<gcd(a,b)<<" "<<lcm(a,b)<<"\n";

    return 0;
}