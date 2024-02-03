/*
Problem
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100
1 <= Marks <= 100

Sample Input
3
Eve 78
Bob 99
Alice 78

Sample Output
Bob 99
Alice 78
Eve 78
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    map<int,multiset<string>> m;

    for(int i = 0;i<n;i++){
        int x;
        string y;
        cin>>y>>x;
        if(m.count(x)){m[x].insert(y);}
        else{
            m.insert({x,{y}});
        }
    }

    for(auto i : m){
        for(auto j : i.second){
            cout<<i.first<<" "<<j<<"\n";
        }
    }

    return 0;}