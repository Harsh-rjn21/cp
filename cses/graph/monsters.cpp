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

int levela[1007][1007], levelm[1007][1007], n, m;
int visiteda[1007][1007], visitedm[1007][1007];
char a[1007][1007];

pii moves[4] = {{0,1},{0,-1},{1,0},{-1,0}};
char path[4] = {'L','R','U','D'};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while (t--)
    {

        cin >> n >> m;
        vector<pii> monsters;pii Start;

        rp(i, 0, n)
        {
            rp(j,0,m){
                cin >> a[i][j];
            }
        }
        rep(i,0,n){
            rp(j, 0, m)
            {
                if (a[i][j] == 'A')
                {
                    Start = {i, j};
                }
                if (a[i][j] == 'M')
                {
                    monsters.pb({i, j});
                }
            }
        }
        rp(i,0,n){
            rp(j,0,m){
                levela[i][j] = LLONG_MAX;
                levelm[i][j] = LLONG_MAX;
            }
        }

    queue<pii> bfsa;
    bfsa.push(Start);
    levela[Start.f][Start.s] = 0;
    visiteda[Start.f][Start.s] = 1;

    while(sz(bfsa)!=0){
        pii x = bfsa.front();
        bfsa.pop();
        rp(i,0,4){
            pii x1 = {x.f+moves[i].f,x.s+moves[i].s};
            if(x1.f >= 0 && x1.f < n && x1.s >= 0 && x1.s < m && visiteda[x1.f][x1.s] == 0 && (a[x1.f][x1.s] == '.')){
                visiteda[x1.f][x1.s] = 1;
                levela[x1.f][x1.s] = 1 + levela[x.f][x.s];
                bfsa.push(x1);
            }
        }
    }

    bool check = false;

    rp(i,0,n){
        if(levela[i][0]!=LLONG_MAX){
            check = true;
            break;
        }
        if(levela[i][m-1]!=LLONG_MAX){
            check = true;
            break;
        }
        if(levela[0][i]!=LLONG_MAX){
            check = true;
            break;
        }
        if(levela[n-1][i]!=LLONG_MAX){
            check = true;
            break;
        }
    }

    if(!check){
        cout << "NO\n";
        continue;
    }

    queue<pii> bfsm;
    rp(i,0,sz(monsters)){
        bfsm.push({monsters[i].f,monsters[i].s});
        levelm[monsters[i].f][monsters[i].s] = 0;
        visitedm[monsters[i].f][monsters[i].s] = 1;
    }

    while(sz(bfsm)!=0){
        pii x = bfsm.front();
        bfsm.pop();
        rp(i,0,4){
            pii x1 = {x.f+moves[i].f,x.s+moves[i].s};
            if(x1.f >= 0 && x1.f < n && x1.s >= 0 && x1.s < m && (visitedm[x1.f][x1.s] == 0 || levelm[x1.f][x1.s]>levelm[x.f][x.s]+1) && (a[x1.f][x1.s] == '.')){
                visitedm[x.f][x.s] = 1;
                levelm[x1.f][x1.s] = 1 + levelm[x.f][x.s];
                bfsm.push(x1);
            }
        }
    }

    pii ans = {-1,-1};

    rp(i,0,n){
        if(levela[i][0]<levelm[i][0]){
            ans = {i,0};
            break;
        }
        if(levela[i][m-1]<levelm[i][m-1]){
            ans = {i,m-1};
            break;
        }
        if(levela[0][i]<levelm[0][i]){
            ans = {0,i};
            break;
        }
        if(levela[n-1][i]<levelm[n-1][i]){
            ans = {n-1,i};
            break;
        }
    }

    if(ans.f==-1||ans.s==-1){
        cout << "NO\n";
        continue;
    }

    cout << "YES\n" << levela[ans.f][ans.s] << "\n";

    string ans1;
    
    pii x = ans;
    while(x!=Start){
        rp(i,0,4){
            pii x1 = {x.f+moves[i].f,x.s+moves[i].s};
            if(x1.f>=0 && x1.f<n && x1.s>=0 && x1.s<m && levela[x1.f][x1.s]==levela[x.f][x.s]-1){
                ans1.pb(path[i]);
                x = x1;
                break;
            }
        }
    }
    reverse(all(ans1));
    cout << ans1 << "\n";
    // cout << Start.f << "," << Start.s << " " << ans.f << "," << ans.s << "\n" << levela[999][5] << " " << levelm[999][5] << " ";
    }
    return 0;
}