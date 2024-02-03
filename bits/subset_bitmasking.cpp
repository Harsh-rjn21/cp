/*Generate power set of a given set using bitmask.
    LOGIC: A set has n elements then write bitmask of 0 to (2^n)-1;
   Eg: n=3;
    0: 000 => no element present            4: 100
    1: 001 => 0th element present           5: 101
    2: 010 => 1th element present           6: 110
    3: 011 => 0th and 1th element present   7: 111

    Assign an index to each element. Then just write in above form
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

deq subset;

set<int> bit_to_set(int a){
    set<int> s;
    int i = 0;
    
    while(a>=(1<<i)){
        if((a&(1<<i))!=0){s.insert(subset[i]);}
        ++i;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;

    int n;
    cin>>n;

    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        subset.push_back(x);
    }

    int total = pow(2,n);

    for(int i=0;i<total;i++){
        for(auto j : bit_to_set(i)){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

    return 0;}