#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        ll arr[n];

        ll sum = 0;
        ll maxi = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            if(arr[i]>maxi)maxi = arr[i];
        }

        maxi *= 2;

        if (sum == 0)
            cout << 0 << "\n";
        else if (maxi <= sum)
            cout << 1 << "\n";
        else if (sum < maxi)
            cout << (maxi - sum) << "\n";
    }
    return 0;
}