#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

// 0=D,1=A,2=B,3=C

int dp[10000001][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int z0 = 1;
    int z1 = 0;
    for (int i = 1; i <= n; i++)
    {
        int nz0 = z1 * 3LL % M;
        int nz1 = (z1 * 2LL + z0) % M;
        z0 = nz0;
        z1 = nz1;
    }
    cout << z0;

    return 0;
}