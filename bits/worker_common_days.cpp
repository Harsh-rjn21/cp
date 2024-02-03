/*
Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

deque<deq> d(5000);

int bit_masking(deq &d){
    int ans = 0;
    for(int i = 0; i < d.size(); i++){
        ans = ans | (1<<d[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,x;
    cin>>n;
    deq bits;
    for(int i = 0; i < n; i++){
        cin>>m;
        for(int j = 0; j < m; j++){
            cin>>x;
           d[i].push_back(x);
        }
        bits.push_back(bit_masking(d[i]));
    }

    int maxi = 0;
    pair<int,int> p = {0,0};

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x = __builtin_popcount((bits[i]&bits[j]));
        if(x>maxi){maxi = x;p = make_pair(i+1,j+1);}
    }
    }
    cout<<maxi<<"\n";
    cout<<p.first<<" "<<p.second<<"\n";

    return 0;}