#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int visit[10][10];
int ans;
string a;

char paths[4] = {'D','U','L','R'};

pii char_to_path(char x){
    if(x=='U')return {-1,0};
    if(x=='D')return {1,0};
    if(x=='L')return {0,-1};
    if(x=='R')return {0,1};
}

void solve(int x,int y, int index){
    if(index==48){
        if(x==7 && y==1){ans++;}
        return;
    }
    if(a[index]!='?'){
        pii move = char_to_path(a[index]);
        int h = x + move.f, k = y + move.s;
        if(h>=1 && h<=7 && k>=1 && k<=7 && visit[h][k]==0){
            visit[h][k] = 1;
            solve(h,k,index+1);
            visit[h][k] = 0;
        }
    }
    else{
        rp(i,0,4){
            pii move = char_to_path(paths[i]);
            int h = x + move.f, k = y + move.s;
            if(h>=1 && h<=7 && k>=1 && k<=7 && visit[h][k]==0){
                visit[h][k] = 1;
                solve(h,k,index+1);
                visit[h][k] = 0;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> a;
    visit[1][1] = 1;

    solve(1,1,0);

    cout << ans << "\n";

    return 0;}