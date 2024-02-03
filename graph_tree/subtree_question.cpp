/*
    Given q queries 
    Each query has an integer V giving the node value.

    Find number of trees and sum of elements in the subtree corresponding to the V.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq tree[100007];
bool visited[100007];

map<int,int> even_numbers_count;
map<int,int> sum;

void solve(int num){

    if(tree[num].empty()){
        visited[num] = true;
        sum.insert({num,num});
        int z = (num & 1) ? 0 : 1;
        even_numbers_count.insert({num,z}); 
        return;
    }


    visited[num] = true;

    int subtree_sum = num,subtree_even_count = (num&1) ? 0 : 1;

    for(auto i : tree[num]){
        if(!visited[i]){
            solve(i);
        }
        subtree_sum += sum[i];
        subtree_even_count += even_numbers_count[i];
    }
    sum.insert({num,subtree_sum});
    even_numbers_count.insert({num,subtree_even_count});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m; i++){
        int parent,child;
        cin >> parent >> child;
        tree[parent].push_back(child);
    }

    solve(1);

    for(int i = 1; i <= n; i++){
        cout<<i<<" "<<sum[i]<<" "<<even_numbers_count[i]<<"\n";
    }

    return 0;}