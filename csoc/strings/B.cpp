#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin>>s>>t;
    deque<ll> ds(26,0);
    deque<ll> dt(26,0);

    for(ll i = 0; i<s.length();i++){
        ds[s[i]-'a']++;
    }
    for(ll i = 0; i<t.length();i++){
        dt[t[i]-'a']++;
    }

        bool array = true;
        bool both  = false;
        for(int i = 0; i<26; i++){
            if(ds[i]<dt[i]){cout<<"need tree\n";return 0;}
        }
        if(s.length()==t.length()){cout<<"array\n";return 0;}

        int j = 0;
        for(int i = 0; i<s.length();i++){
            if(s[i]==t[j]){
                ++j;
            }
        }
            if(j==t.length()){
                cout<<"automaton\n";
            }
            else{
                cout<<"both\n";
            }

    return 0;}