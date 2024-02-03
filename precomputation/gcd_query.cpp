/*
Given : array of n integers .
q queries with two int l,r
Find: GCD of array after excluding the array from l to r
*/

#include <bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n], forward[n + 2], backward[n + 2];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        forward[1] = arr[0];
        backward[n] = arr[n - 1];
        forward[0] = forward[n + 1] = backward[n + 1] = backward[0] = 0;

        for (int i = 2; i <= n; i++)
        {
            forward[i] = __gcd(forward[i - 1], arr[i - 1]);
            backward[n - i + 1] = __gcd(backward[n - i + 2], arr[n - i]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int ans = __gcd(forward[l - 1], backward[r + 1]);
            cout << ans << "\n";
        }
    }
    return 0;
}