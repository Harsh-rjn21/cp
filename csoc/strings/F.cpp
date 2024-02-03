#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

bool good[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;

    for (int i = 0; i < a.length(); i++)
    {
        good[a[i] - 'a'] = true;
    }

    string b;
    cin >> b;
    int m = b.length();
    bool hash = false;
    for(int i = 0; i < m; i++){
        if(b[i]=='*'){
            hash=true;
            break;
        }
    }
    int n;
    cin >> n;

    while (n--)
    {
        string c;
        cin >> c;
        bool ans = true;
        int n1 = c.length();

            int i = 0, j = 0;
            int x = n1 - m;

            if((!hash && x!=0) || (hash && x<-1)){cout<<"NO\n";continue;}

            while(i<m && j<n1){
                if(b[i]!=c[j] && !(b[i]=='?' || b[i]=='*')){
                    ans = false;
                    break;
                }

                else if(b[i]=='?' && !good[c[j] - 'a']){
                    ans = false;
                    break;
                }

                else if(b[i]=='*' && x>=0){
                    bool check = false;
                    for(int h= 0; h<=x;h++){
                        if(good[c[j+h]-'a']){
                            ans = false;
                            check = true;
                            break;
                        }
                    }
                    
                    if(check)break;
                    j+=x;
                }
                else if(b[i]=='*' && x<0)--j;
                ++i;++j;
            }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}