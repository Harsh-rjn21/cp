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

    ll cnt[10]={1,1,1,1,1,1,1,1,1,1};
   
    string letters = "codeforces";
    ll a;
    cin >> a;

    ll z = 1;
    int i = 0;

    while(a>z){
        z  *= (cnt[i]+1);
        z/= cnt[i];
        cnt[i]++;
        i = (i+1)%10;
    }

    string ans = "";

    for(int i = 0; i<10;i++){
        while(cnt[i]--){
            ans.push_back(letters[i]);
        }
    }

    cout<<ans;

    return 0;}