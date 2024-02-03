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
        int n, k, z;

        cin >> n >> k >> z;

        int arr[n + 1];

        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int answer = 0;
        for (int j = 0; j <= z; j++)
        {
            int maxi = 0, maxi_x = 0, x = k, y = j, sum = 0;
            if ((k - (2 * j) + 1) < 0)
                continue;
            int total = min(n, (k - (2 * j) + 1));
            for (int i = 1; i <= total; i++)
            {
                if ((arr[i] + arr[i + 1]) > maxi)
                {
                    maxi = arr[i] + arr[i + 1];
                    maxi_x = i;
                }
                sum += arr[i];
            }

            answer = max(answer, j * maxi + sum);
        }
        cout << answer << "\n";
    }
    return 0;
}