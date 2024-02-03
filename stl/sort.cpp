#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first > b.first;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<pair<int,int>> d;

    d.push_back({4,3});
    d.push_back({5,5});
    d.push_back({5,3});
    d.push_back({25,6});
    d.push_back({7,9});
    d.push_back({8,5});

    sort(d.begin(), d.end(),cmp);

    for(auto i : d){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;}