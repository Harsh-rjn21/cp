/*
Problem
"Money money MONEY, I want money" thought Alex. "Now how do I get money? Well... I'll open up a camp!"

Well, unfortunately things didn't go so well for Alex's campers, and now there are N campers wandering around the city aimlessly. You have to handle Q queries; which consist of two groups finding each other and becoming one larger group. After each query, output the difference between the group of largest size and group of smallest size. If there is only one group, output 0. At first, everyone is in their own group.

Also note, if the two campers in the query are already in the same group, print the current answer, and skip merging the groups together.

Input:

The first line consists of two space separated integers, N and Q

The next Q line consists of two integers, A and B, meaning that the groups involving camper A and camper B find each other.

Output:

Output Q lines, the answer after each query.

Constraints:

1 <= N <= 105

1 <= Q <= 105

Sample Input
2 1
1 2
Sample Output
0

Explanation
Here, the two campers find each other, so the answer is 0.
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
multiset<int> sizes;

void make(int n){
    parent[n] = n;
    size[n] = 1;
    sizes.insert(1);
}

int find(int n){
    if(parent[n] == n)return n;
    return parent[n] = find(parent[n]);
}

void Union(int a,int b){
    int x = find(a), y = find(b);
    if(size[x]>size[y]){swap(x,y);}
    parent[x] = y;
    sizes.erase(sizes.find(size[x]));
    sizes.erase(sizes.find(size[y]));
    size[y] += size[x];
    size[x] = size[y];
    sizes.insert(size[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i = 1; i<=n; i++){
        make(i);
    }

    for(int i = 1; i<=k; i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    deq answer;

    for(int i = 1; i<=n; i++){
        answer.push_back(size[i]);
    }

    sort(answer.begin(), answer.end());

    for(int i = 0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    
    sizes.size() == 1 || sizes.size() == 0 ? cout<<"0\n": cout<< (*(sizes.end()--)) - (*sizes.begin()) <<"\n";

    return 0;}