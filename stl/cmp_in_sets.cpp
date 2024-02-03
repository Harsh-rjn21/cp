#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

// Follow this syntax
struct cmp{
    bool operator()(int a,int b) const{
        return a>b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<int,cmp> x; // Since cmp diya, so ye decreasing order mein elements rakhega/. 
    x.insert(1); 
    x.insert(2); 
    x.insert(3);

    cout<<*(x.begin()); 

    return 0;}