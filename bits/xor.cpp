#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Swap
    int a = 2, b = 3;
    
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<a<<" "<<b<<"\n";

    /*
    Given an array of n integers , all integers have even count except one.
    Find that number.

    Logic = Poore array ka xor le le aapas mein.
    => (a^a)^(b^b)^(c)^(d^d)^(e^e)..... 
    =>0^0^c^0^0.... = c
    */

    array<int,19> arr = {1,1,2,2,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,};

    int ans = 0;

    for(int i=0; i<arr.size(); i++){
        ans^=arr[i];
    }

    cout<<ans;

    return 0;}