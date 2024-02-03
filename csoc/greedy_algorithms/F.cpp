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

    int n, s;
    cin >> n >> s;
    
    if(n==1 && s<=(9*n)){cout<<s<<" "<<s<<"\n";return 0;}

    if (s < 1 || s > (9 * n))
    {
        cout << "-1 -1\n";
    }

   else{
        string mini = "", maxi = "";
        for (int i = 0; i < n; i++)
        {
            if (s >= 9)
            {
                maxi.push_back('9');
                s -= 9;
            }
            else
            {
                maxi.push_back('0' + s);
                s = 0;
            }
        }

        for (int i = (n - 1); i >= 0; i--)
        {
            mini.push_back(maxi[i]);
        }

        if (mini[0] == '0')
        {
            int index = 0;
            while (mini[index] == '0')
            {
                index++;
            }
            mini[0] = '1';
            mini[index]--;
        }

        cout << mini << " " << maxi;
    
   }
    return 0;
}