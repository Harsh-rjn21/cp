/*
LCS 
You are given strings s and t. Find one longest string that is a subsequence of both s and t.
Notes
A subsequence of a string x is the string obtained by removing zero or more characters from x and concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1≤∣s∣,∣t∣≤3000
Input
Input is given from Standard Input in the following format:

s
t
Output
Print one longest string that is a subsequence of both s and t. If there are multiple such strings, any of them will be accepted.

Sample Input 1 
Copy
axyb
abyxb
Sample Output 1 
Copy
axb
The answer is axb or ayb; either will be accepted.

Sample Input 2 
Copy
aa
xayaz
Sample Output 2 
Copy
aa
Sample Input 3 
Copy
a
z
Sample Output 3 
Copy
The answer is (an empty string).

Sample Input 4 
Copy
abracadabra
avadakedavra
Sample Output 4 
Copy
aaadara
*/

//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

int dp[3005][3005];
string a,b;

int solve(int ia, int ib){
    if(ia == a.length() || ib==b.length())return 0;

    if(dp[ia][ib]!=-1) return dp[ia][ib];

    ll ans = 0;

    if(a[ia] == b[ib]){
        ans = 1+solve(ia+1,ib+1);
    }

    ans = max(solve(ia+1,ib),ans);
    ans = max(solve(ia,ib+1),ans);
    return dp[ia][ib] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    memset(dp,-1,sizeof(dp));

    cin >> a >> b;
    ll n = solve(0,0);

    int i = 0, j = 0;
    string ans = "";

    while(n){
        if(a[i]==b[j]){
            ans.pb(a[i]);
            ++i;
            ++j;
            --n;
        }
        else{
            if(dp[i+1][j]>=dp[i][j+1]){
                ++i;
            }
            else{
                ++j;
            }
        }
    }

    cout << ans << "\n";
    
    return 0;}