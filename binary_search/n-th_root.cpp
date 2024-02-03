#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

double precision = 0.00001;

double nth_root(double num){
    double low = num >=1 ? 1 : num;
    double high = num>=1 ? num : 1;

    while(high - low > precision){
        double mid = (high+low)/2;
        if(mid*mid>num)high = mid;
        else low = mid;
    }
    return high;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int n;
    // cin>>n;

    // double num;
    // cin>>num;

    long long ans = nth_root(1000000000000000000);
    cout<<ans<<"\n";

    return 0;}