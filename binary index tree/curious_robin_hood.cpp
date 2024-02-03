/*Robin Hood likes to loot rich people since he helps the poor people with this money. Instead of keeping all the money together he does another trick. He keeps n sacks where he keeps this money. The sacks are numbered from 0 to n-1.

Now each time he can he can do one of the three following tasks:

Give all the money of the ith sack to the poor, leaving the sack empty.
Add new amount (given in input) in the ith sack.
Find the total amount of money from ith sack to jth sack.
Since he is not a programmer, he seeks your help.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case contains two integers n (1 ≤ n ≤ 105) and q (1 ≤ q ≤ 50000). The next line contains n space separated integers in the range [0, 1000]. The ith integer denotes the initial amount of money in the ith sack (0 ≤ i < n).

Each of the next q lines contains a task in one of the following form:

1 i - give all the money of the ith.
2 i v - add money v (1 ≤ v ≤ 1000) to the ith (0 ≤ i < n) sack.
3 i j - find the total amount of money from the ith sack to the jth sack (0 ≤ i ≤ j < n).
Output
For each test case, print the case number first. If the query type is 1, then print the amount of money given to the poor. If the query type is 3, print the total amount from ith to jth sack.

Sample
Input	Output
1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1

Case 1:
5
14
1
13
2
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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int money[100007],fenwick[100007];

int N;

void update(int n,int x){
    for(int i = n ; i <=N; i+=(i & (-i))){
        fenwick[i]+=x;   
    }
}

int sum(int n){
    int ans = 0;
    for(int i = n ; i > 0; i-=(i&(-i))){
        ans+=fenwick[i];
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){
        
        memset(money,0,sizeof(money));
        memset(fenwick,0,sizeof(fenwick));

        int q;
        cin >> N >> q;

        for(int i = 1; i<=N;i++){
            int x;
            cin >> x;
            money[i]=x;
            update(i,x);
        }

        while(q--){
            int x,y,z;
            cin >> x;

            if(x==1){
                cin >> y;
                cout << money[y+1] << "\n";
                update(y+1,-money[y+1]);
                money[y+1] = 0;
            }
            else if(x==2){
                cin >> y >> z;
                money[y+1]+=z;
                update(y+1,z);
            }
            else if(x==3){
                cin >> y >> z;
                cout << (sum(z+1) - sum(y)) << "\n";
            }
        }
    }

    return 0;}