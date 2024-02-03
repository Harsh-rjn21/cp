#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int pre_compute[10000001];
deq answers(100000001,-1);

void solve(){
    for(int i = 2; i<=10000000;i++){
        for(int j = i; j<=10000000;j+=i){
            pre_compute[j]+=i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    for(int i = 2; i<=10000000;i++){
        int c = pre_compute[i];
        if(answers[c+1]==-1){
            answers[c+1]=i;
        }
    }
    
    answers[1] = 1;

    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;
        cout << answers[x] <<"\n";
        
    }
    return 0;}