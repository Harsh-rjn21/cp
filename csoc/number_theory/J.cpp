#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

deq solution[100001];
int isPrime[100001];

void seive_algorithm(){
    for(int i=2; i<100001; i++){
        if(isPrime[i]==0){
            for(int j=2*i; j<100001; j+=i){
                isPrime[j] = 1;
            }
        }
    }
}

void solve(int t)
{
    int x = t;
    for (int i = 2; i <= sqrt(t); i++)
    {
       if(t%i==0){
        if(isPrime[i]==0)solution[x].push_back(i);
        if(isPrime[t/i]==0)solution[x].push_back(t/i);
       }
    }

    if(solution[x].empty())solution[x].push_back(t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    seive_algorithm();

    int n, m;
    cin >> n >> m;

    set<int> on;
    mii factors;

    deque<pair<char, int>> query;

    for (int i = 0; i < m; i++)
    {
        char x;
        int t;
        cin >> x >> t;

        query.push_back(make_pair(x, t));
        solve(t);
    }

    for (int l = 0; l < m; l++)
    {
        char x = query[l].first;
        int t = query[l].second;
        if (x == '-')
        {
            if (on.count(t))
            {
                cout << "Success\n";
                on.erase(t);
                deq fas;
                for (auto i : factors)
                {
                    if (i.second == t)
                    {
                        fas.push_back(i.first);
                    }
                }
                for (auto i : fas)
                {
                    factors.erase(i);
                }
            }
            else
            {
                cout << "Already off\n";
            }
        }

        if (x == '+')
        {
            if (on.count(t))
                cout << "Already on\n";
            else
            {
                bool check = true;
                deq fac;
                for (auto i : solution[t])
                {

                    if (factors.count(i))
                    {
                        cout << "Conflict with " << factors[i] << "\n";
                        check = false;
                        break;
                    }
                    else
                    {
                        fac.push_back(i);
                    }
                }
                if (check)
                {
                    on.insert(t);
                    for (auto j : fac)
                    {
                        factors[j] = t;
                    }
                    cout << "Success\n";
                }
            }
        }
    }
    return 0;
}