/*
D. Christmas Trees

There are n Christmas trees on an infinite number line. The i-th tree grows at the position xi. All xi are guaranteed to be distinct.

Each integer point can be either occupied by the Christmas tree, by the human or not occupied at all. Non-integer points cannot be occupied by anything.

There are m people who want to celebrate Christmas. Let y1,y2,…,ym be the positions of people (note that all values x1,x2,…,xn,y1,y2,…,ym should be distinct and all yj should be integer). You want to find such an arrangement of people that the value ∑j=1mmini=1n|xi−yj| is the minimum possible (in other words, the sum of distances to the nearest Christmas tree for all people should be minimized).

In other words, let dj be the distance from the j-th human to the nearest Christmas tree (dj=mini=1n|yj−xi|). Then you need to choose such positions y1,y2,…,ym that ∑j=1mdj is the minimum possible.

Input
The first line of the input contains two integers n and m (1≤n,m≤2⋅105) — the number of Christmas trees and the number of people.

The second line of the input contains n integers x1,x2,…,xn (−109≤xi≤109), where xi is the position of the i-th Christmas tree. It is guaranteed that all xi are distinct.

Output
In the first line print one integer res — the minimum possible value of ∑j=1mmini=1n|xi−yj| (in other words, the sum of distances to the nearest Christmas tree for all people).

In the second line print m integers y1,y2,…,ym (−2⋅109≤yj≤2⋅109), where yj is the position of the j-th human. All yj should be distinct and all values x1,x2,…,xn,y1,y2,…,ym should be distinct.

If there are multiple answers, print any of them.

Examples
inputCopy
2 6
1 5
outputCopy
8
-1 2 6 4 0 3 
inputCopy
3 5
0 3 1
outputCopy
7
5 -2 4 -1 2 
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int n,m;
set<int> tree;
set<pii> answers;

void breadth_first_search(){
    queue<int> bfs;

    for(auto i : tree){
        bfs.push(i);
    }

    while(!bfs.empty()){
        int z = bfs.front();
        bool right = true;
        bool left = true;
        for(int i = 1; i <= m;i++){
            if(tree.count(z+i))right = false;
            if(tree.count(z-i))left = false;
            if((!right)&&(!left))break;
            if(right && (!answers.count({i,z+i})))answers.insert({i,z+i});
            if(left&&(!answers.count({i,z-i})))answers.insert({i,z-i});
        }
        bfs.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        tree.insert(x);
    }

    breadth_first_search();

    int i = 0;
    int ans = 0;
    for(auto a: answers){
        if(i>=m)break;
        ans+=a.first;
        cout<<a.second<<" ";
        ++i;
    }
    cout<<"\n"<<ans;
    return 0;}