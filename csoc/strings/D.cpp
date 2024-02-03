#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;

    deque<ll> d(26,0);
    set<char> check;

    bool x = true;

    for(ll i = 0; i<s.length();i++){
        d[s[i]-'a']++;
        check.insert(s[i]);
    }

    for(int i = 0; i<26;i++){
        if(d[i]%k!=0){x=false;break;}
    }

    string ans="";

    if(x){
        for(int i = 0; i<26;i++){
            char c = 'a'+i;
            ll h = d[i]/k;
            if(h!=0){for(ll j = 0;j<h;j++){
                ans+=c;
            }}
        }
    }

    if(x==false){cout<<"-1\n";}
    else{
        for(int i = 0; i<k; i++){
            cout<<ans;
        }
    }

    return 0;}