/*
D. Add to Neighbour and Remove

Polycarp was given an array of a[1…n] of n integers. He can perform the following operation with the array a no more than n times:

Polycarp selects the index i and adds the value ai to one of his choice of its neighbors. More formally, Polycarp adds the value of ai to ai−1 or to ai+1 (if such a neighbor does not exist, then it is impossible to add to it).
After adding it, Polycarp removes the i-th element from the a array. During this step the length of a is decreased by 1.
The two items above together denote one single operation.

For example, if Polycarp has an array a=[3,1,6,6,2], then it can perform the following sequence of operations with it:

Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[4,6,6,2].
Polycarp selects i=1 and adds the value ai to (i+1)-th element: a=[10,6,2].
Polycarp selects i=3 and adds the value ai to (i−1)-th element: a=[10,8].
Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[18].
Note that Polycarp could stop performing operations at any time.

Polycarp wondered how many minimum operations he would need to perform to make all the elements of a equal (i.e., he wants all ai are equal to each other).

Input
The first line contains a single integer t (1≤t≤3000) — the number of test cases in the test. Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤3000) — the length of the array. The next line contains n integers a1,a2,…,an (1≤ai≤105) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 3000.

Output
For each test case, output a single number — the minimum number of operations that Polycarp needs to perform so that all elements of the a array are the same (equal).

Example
inputCopy
4
5
3 1 6 6 2
4
1 2 2 1
3
2 2 2
4
6 3 2 1
outputCopy
4
2
0
2
Note
In the first test case of the example, the answer can be constructed like this (just one way among many other ways):

[3,1,6,6,2] −→−−−−−−−i=4, add to left [3,1,12,2] −→−−−−−−−−i=2, add to right [3,13,2] −→−−−−−−−−i=1, add to right [16,2] −→−−−−−−−i=2, add to left [18]. All elements of the array [18] are the same.

In the second test case of the example, the answer can be constructed like this (just one way among other ways):

[1,2,2,1] −→−−−−−−−−i=1, add to right [3,2,1] −→−−−−−−−i=3, add to left [3,3]. All elements of the array [3,3] are the same.

In the third test case of the example, Polycarp doesn't need to perform any operations since [2,2,2] contains equal (same) elements only.

In the fourth test case of the example, the answer can be constructed like this (just one way among other ways):

[6,3,2,1] −→−−−−−−−−i=3, add to right [6,3,3] −→−−−−−−−i=3, add to left [6,6]. All elements of the array [6,6] are the same.
*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int min_operations(deq d){
    int y = d[0];
    if(all_of(d.begin(),d.end(),[y](int x){return x==y;}))return 0;
    int operations = INT_MAX;
    for(int i = 0; i<d.size();i++){
        if(i!=0){
        deq temp(d); 
        int x = temp[i]; temp[i-1]+=x;
        temp.erase(temp.begin()+i);
        operations = min(operations,1+min_operations(temp));}

        if(i!=d.size()-1){
        deq temp(d); 
        int x = temp[i]; temp[i+1]+=x;
        temp.erase(temp.begin()+i);
        operations = min(operations,1+min_operations(temp));
        }
    }
    return operations;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    deque<int> d;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        d.push_back(x);
    }

    deque<int> ans_deq;

    int ans = min_operations(d);
    cout<<ans;

    return 0;}