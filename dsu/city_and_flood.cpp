/*
Problem
Fatland is a town that started with N distinct empires, namely empires 1, 2, ..., N. But over time, the armies of some of these empires have taken over other ones. Each takeover occurred when the army of empire i invaded empire j. After each invasion, all of empire j became part of empire i, and empire j was renamed as empire i.

Empire Huang, leader of Badland, wants to invade Fatland. To do this, he needs to calculate how many distinct empires still remain in Fatland after all the takeovers. Help him with this task.

Input:

The first line contains an integer N, the number of empires that were originally in Fatland.

The second line contains an integer K, denoting the number of takeovers that took place.

Each of the next K lines contains 2 space-separated integers i, j, representing that the army of empire i took over that of empire j. As a result, empire j does not exist anymore and is now renamed as empire i. It is guaranteed that empire i still exists.

Output: Output one integer, the number of empires that exist in Fatland.

Constraints:

1 <= N <= 105

1 <= K <= 105

Sample Input
4
2
1 2
4 1
Sample Output
2

Explanation
Fatland started with empires 1, 2, 3, 4. First, empire 1 invaded empire 2, so empire 2 was renamed to empire 1. Then, empire 4 invaded empire 1. So what were at the beginning empires 1 and 2 were renamed to empire 4. Now, only empires 3 and 4 remain, so the answer is 2.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int parent[100];
int size[100];
set<int> connected;

void make(int n){
    parent[n] = n;
    size[n] = n;
}

int find(int n){
    if(parent[n] == n)return n;
    return parent[n] = find(parent[n]);
}

void Union(int a,int b){
    int x = find(a), y = find(b);
    if(size[x]>size[y])
        swap(x,y);
        parent[x] = y;
        size[y] += size[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        make(i);
    }

    for(int i = 1; i <= k; i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    for(int i = 1; i <= n; i++){
        connected.insert(find(i));
    }
    cout<<connected.size()<<endl;

    return 0;}