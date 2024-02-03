#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    unordered_set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(4);
    
    for(auto i : s)cout<<i<<"\n";

    cout<<"AFTER DELETING:\n";

    s.erase(5);
    for(auto i : s)cout<<i<<"\n";

    return 0;}