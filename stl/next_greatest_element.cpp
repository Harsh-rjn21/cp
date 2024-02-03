/*
Given: An array of integers.
har element ke liye array mein right side ka nearest greatest element
Example: 4,5,2,25,7,8
NGE: 5,25,25,-1,8,-1
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

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<pair<int,int>, int> m;
    stack<pair<int,int>> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().second < arr[i])
        {
            m.insert({s.top(), arr[i]});
            s.pop();
        }
        s.push(make_pair(i,arr[i]));
    }

    while (!s.empty())
    {
        m.insert({s.top(), -1});
        s.pop();
    }

    for (auto i : m)
    {
        cout << i.first.second << " " << i.second << endl;
    }

    return 0;
}