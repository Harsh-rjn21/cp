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
        string a;
        cin >> a;

        string x = "1", y = "1";
        bool check = false;

        for (int i = 1; i < n; i++)
        {
            if(a[i]=='0'){
                x.push_back('0');
                y.push_back('0');
            }
            if(a[i]=='1'){
                if(x<=y){
                    x.push_back('1');
                    y.push_back('0');}
                else{
                    y.push_back('1');
                    x.push_back('0');}
                }
            if(a[i]=='2'){
                if(x==y){
                    x.push_back('1');
                    y.push_back('1');
                }
                else if(x<y){
                    x.push_back('2');
                    y.push_back('0');
                }
                else if(x>y){
                    y.push_back('2');
                    x.push_back('0');
                }
            }
            }
        
        cout << x << "\n"
             << y << "\n";
    }

    return 0;
}