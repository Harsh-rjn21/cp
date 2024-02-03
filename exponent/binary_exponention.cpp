/*
    Do not use pow(a,b);
    Since returns double => So precision error possible
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power_rec(int a, int b)
{
    if (b == 0)
        return 1;

    int x = power_rec(a, b / 2);
    if (b & 1)
        return ((a % mod) * (x % mod) * (x % mod)) % mod;
    else
        return ((x % mod) * (x % mod)) % mod;
}
// eg: 2^13 => 2^(1101)2 So, exponent ko right shift kar rahe h, Jab (exponent & 1 == 1) h. Keval tab multiply kar rhe h power ke saath
int power(int a, int b){
    int ans = 1;

    while (b > 0){

        if (b & 1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }

    return ans;}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << power_rec(2, 13) << "\n";
    cout << power(2, 13) << "\n";

    return 0;
}