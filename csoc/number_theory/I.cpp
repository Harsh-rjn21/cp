#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq table;

bool solve(int n){
    bool ans = false;

    for(int i = 0; i < n ; i++){
        bool check = true;
        if(table[i]==1){
            for(int j = n+i;j<table.size();j+=n){
                if(table[j]==0){check = false;break;}
            }
            if(check){ans = true;break;}
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool check = true;

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x==0)check = false;
        table.push_back(x);
    }

    if(check){cout << "YES\n";return 0;}

    for(int i = 2; i<=sqrt(n); i++){
        if((n%i)==0){
            if((n/i)>=3 && solve(i)){cout << "YES\n";return 0;}
            if(i>=3 && solve(n/i)){cout << "YES\n";return 0;}
        }
    }

    cout << "NO\n";

    return 0;}