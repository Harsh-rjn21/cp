/*
Misha listens to music on his player, his playlist consists of n songs that are played in a specific order. After the last song ends, the first one starts playing. Each song has its own characteristic, positivity ai, given by an integer. After listening to the i-h song, Misha's mood increases by ai.

Misha can start listening to any of the songs and listen to any number of songs in a row, while he may listen to some songs more than once.

Misha feels happy if his mood after listening to the songs has increased by at least p. He wants to feel happy listening to as few songs as possible. Help him choose the song to start listening to and the number of songs to listen to to be happy.

Input
The first line contains two integers n and p (1 ≤ n ≤ 1000, 1 ≤ p ≤ 1018), the number of songs in the playlist and the amount that Misha wants increase his mood.

The second line contains n integers ai (1 ≤ ai ≤ 109), positivity of the songs.

Output
Print two numbers, the index of the song k, with which you should start listening, and the number of songs c, which you should listen to. If there are several possible answers, print any.

Examples
inputCopy
9 10
1 2 3 4 5 4 3 2 1
outputCopy
3 3
inputCopy
5 6
3 1 1 1 4
outputCopy
5 2
inputCopy
3 100
10 10 10
outputCopy
1 10
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,p;
    cin >> n >> p;

    ll arr[n], ans = 0,sum = 0;

    rp(i,0,n){
        cin >> arr[i];
        sum+= arr[i];
    }

    ll a = p/sum;
    ans+=(a*n);
    p-=(a*sum);

    if(p==0){
        cout << 1 << " " << ans << "\n";
        return 0;
    }

    int i=0,j=0,x=0,c=INT_MAX;

    int t = 0;
    int k = 0;

    while(j<2*n){
        x+=arr[j%n];
        while((x-arr[i%n])>=p){
            x-=arr[i%n];
            ++i;
        }
        if(x>=p && c>(j-i+1)){
            c = j-i+1;
            t = i;
        }
        ++j;
    }

    cout << (t+1) << " " << (ans + c) << "\n";

    return 0;}