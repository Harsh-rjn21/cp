#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll hashing[200007];
struct cmp{
    bool operator()(const int& a, const int& b) const{
        return a > b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m ;
    deq arr;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    while(m--){
        int l,r;
        cin >> l >> r;
        hashing[l]++;
        hashing[r+1]--;
    }

    ll ans = 0;
    int count[n+1];
    count[0] = 0;

    multiset<ll,cmp> answer;

    for(int i = 1; i<= n;i++){
        count[i] = hashing[i]+count[i-1];
        answer.insert(count[i]);
    }

    int z = 0;

    for(auto i : answer){
        if(i==0)break;
        ans += (i*arr[z]);
        ++z;
    }

    cout << ans;

    return 0;}