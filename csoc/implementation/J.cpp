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

    int n;
    cin >> n;
    string arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            bool check1 = false;
            for (int k = 0; k <= (9 - j); k++)
            {
                // string z = arr[i].substr(k, j);
                // bool check = true;
                // for (int h = 0; h < n; h++)
                // {
                //     if ((arr[h].find(z) <= 9) && (h != i))
                //     {
                //         check = false;
                //         break;
                //     }
                // }
                // if (check)
                // {
                //     ans.push_back(z);
                //     check1 = true;
                //     break;
                // }
            }
            // if (check1)
            //     break;
        }
    }

    map<string,int> sub_string;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 0; k <= (9 - j); k++)
            {
                string z = arr[i].substr(k, j);
                bool y = sub_string.count(z);
                if(y && sub_string[z]!=i){
                    sub_string[z] = -1;
                }
                else if(!y){
                    sub_string.insert({z,i});
                }
            }
        }
    }

    string ans[n];

    for(auto z : sub_string){
        int y = z.second;
        string x = z.first;
        if(y!=-1){if(ans[y]=="" || ans[y].length() > x.length()){
            ans[y] = x;
        }}
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}