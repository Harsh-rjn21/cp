#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin>>a;

    map<ll,ll> m;
    ll count=0;


    for(ll i = 0; i<a.length()-1;i++){
        if(a[i]=='v' && a[i+1]=='v'){
            count++;
        }
        else if(a[i]=='o'){
            m.insert({i,count});
        }
    }

    ll ans = 0;

    for(auto i:m){
        ll h = i.second;
        ll k =(count-i.second);
        ans+=(h*k);
    }

    cout<<ans<<"\n";

    return 0;}