#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int k;
int cnt[26];
deq ans;

void dfs(int n){
    while (cnt[n] < k) {
    int u = cnt[n]++;
    dfs(u);
    ans.push_back(u);
  }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n>> k;
    
    dfs(0);

    cout << 'a';
    int s = ans.size();
    for(int i=0; i<n-1; i++){
        cout<<(char)(ans[i%s]+'a');
    }

    return 0;}