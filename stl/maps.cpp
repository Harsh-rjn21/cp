/*
    A) Given N strings , Print unique strings with their frequencies alphabaically
    B) Given N strings , Print unique strings with their frequencies.
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string,int> m;
    unordered_map<string,int> um; // Since iski time complexity less to not alphabatical mein iska use kiya
    int n;
    cin>>n;

    string a;

    for(int i =0; i<n;i++){
        cin>>a;
        if(m.find(a)==m.end()){m.insert({a,1});um.insert({a,1});}
        else {m[a]++;um[a]++;}
    }

    m.erase("abc");
    um.erase("abc");

    cout<<"ALPHABETICALLY\n";
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<"\n";
    }

    cout<<"UNALPHABETICALLY\n";
    for(auto i : um){
        cout<<i.first<<" "<<i.second<<"\n";
    }

    return 0;}