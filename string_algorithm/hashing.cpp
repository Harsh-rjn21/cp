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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    map<char,int> code;
    set<char> words;

    string a;
    cin >> a;
    rp(i,0,a.length()){
        words.insert(a[i]);
    }
    int x = 0;
    for(auto i : words){
        code[i] = x;
        ++x;
    }

    int hash[a.length()]= {0};

    hash[0] = code[a[0]];

    rp(i,1,a.length()){
        hash[i] = ((hash[i-1]%M * x%M)%M + code[a[i]]%M )%M;
    }

    rp(i,0,a.length())cout << hash[i] << " ";
    cout << endl;

    int t;
    cin >> t;

    while(t--){
        int i,j;
        cin >> i >> j;
        if(i==0){
            cout << hash[j] << "\n";
            continue;
        }
        cout << hash[j] - hash[i-1]*pow(x,j-i+1) << "\n";
    }

    return 0;}