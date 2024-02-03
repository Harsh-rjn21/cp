#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

int n,m;
int ans[1005][1005],visited[1005][1005];
string ans1;
string a[1005];
pii Start, End;

pii moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char path[4] = {'L', 'U', 'R', 'D'};

void solve()
{
    // if(x==End){
    //     if(z<ans){
    //         ans = z;
    //         ans1 = y;
    //         // cout << z << " " << y << "\n";
    //     }
    //     return;
    // }

    // rp(i,0,4){
    //     pii x1 = {x.f+moves[i].f,x.s+moves[i].s};
    //     if(x1.f>=0 && x1.f<n && x1.s>=0 && x1.s<m && visited[x1.f][x1.s]==0 && (a[x1.f][x1.s]=='.' || a[x1.f][x1.s]=='B')){
    //         string h = y;
    //         y.pb(path[i]);
    //         visited[x1.f][x1.s]=1;
    //         // cout << x1.f << " " << x1.s << " " << y << " " << z << "\n";
    //         solve(x1,y,z+1);
    //         y = h;
    //         visited[x1.f][x1.s]=0;
    //     }
    // }

    queue<pii> bfs;

    bfs.push(Start);

    while (bfs.size() != 0)
    {
        pii x = bfs.front();
        rp(i, 0, 4)
        {
            pii x1 = {x.f + moves[i].f, x.s + moves[i].s};
            if (x1.f >= 0 && x1.f < n && x1.s >= 0 && x1.s < m && visited[x1.f][x1.s]==0 && (a[x1.f][x1.s] == '.' || a[x1.f][x1.s] == 'B'))
            {
                visited[x1.f][x1.s] = 1;
                ans[x1.f][x1.s] = ans[x.f][x.s] + 1;
                // ans1[x1.f][x1.s] = ans1[x.f][x.s] + path[i];
                bfs.push(x1);
            }
        }
        bfs.pop();
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while (t--)
    {

        cin >> n >> m;

        rp(i, 0, n)
        {
            cin >> a[i];
            rp(j, 0, m)
            {
                if (a[i][j] == 'A')
                {
                    Start = {i, j};
                }
                if (a[i][j] == 'B')
                {
                    End = {i, j};
                }
            }
        }
        solve();
        // cout << Start.f << " " << Start.s << "\n" << End.f << " " << End.s << "\n";
        // cout << ans1 << "\n" << ans << "\n";
        if(ans[End.f][End.s]==0){
            cout << "NO\n";
            continue;
        }
        pii x = End;

    while(x!=Start){
        rp(i,0,4){
            pii x1 = {x.f + moves[i].f, x.s + moves[i].s};
            if(x1.f >= 0 && x1.f < n && x1.s >= 0 && x1.s < m && (a[x1.f][x1.s] == '.' || a[x1.f][x1.s] == 'A') && ans[x1.f][x1.s] == (ans[x.f][x.s]-1)){
                ans1.pb(path[i]);
                x = x1;
                break;
            }
        }
    }
    reverse(all(ans1));
        cout << "YES\n" << ans[End.f][End.s] << "\n" << ans1 << "\n";
    }

    return 0;
}