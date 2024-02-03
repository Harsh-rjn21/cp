#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<pair<int,string>> d(2);

    d[0] = {2,"gh"};
    d[1] = make_pair(3,"ab");
    d.push_back(make_pair(4,"abcdef"));
    d.push_front({1,"ef"});

    for(auto i : d){
        cout<<i.first<<" "<<i.second<<"\n";
    }

    deque<pair<int,string>> :: iterator itr = d.begin();
    ++itr;

    cout<<(*itr).first<<" "<<(*itr).second<<"\n";

    //  THIS FOR LOOP NOT POSSIBLE WITH ITERATOR
    // for(auto i : d.begin()){
    //     cout<<(*i).first<<" "<<(*i).second<<"\n";
    // }

    for(auto i = d.begin(); i != d.end(); ++i){
        cout<<(*i).first<<" "<<(*i).second<<"\n";
    }

    return 0;}