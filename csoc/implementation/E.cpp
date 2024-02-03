#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t; 

   while(t--){
    string ans = "";
    int n,m;
    cin >> n >> m;
    int hashing[m][26] = {0};

    for(int i = 1; i < (2*n); i++){
        string a;
        cin >> a;
        for(int j = 0; j < m; j++){
            hashing[j][a[j]-'a']++;
        }
    }

    for(int i = 0; i<m;i++){
        for(int j = 0; j < 26; j++){
            if((hashing[i][j]%2)==1){
                char x = 'a' + j;
                ans.push_back(x);
                break;
            }
        }
    }
    cout << ans<<"\n";
    
}
    return 0;}