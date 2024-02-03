/*
Problem
Monk loves cycling. He wants to buy his favorite bicycle costing P dollars. But his father won’t give him the money so easily as he wants Monk to understand the importance of money. So they made a deal.
Monk starts with Zero dollars in his piggybank. On each day, Monk will go to another city where God of Money lives, and will get as much as dollars he wants from him.

At the end of each day, Monk brings the piggybank to his father, who counts the money in the piggybank and deposits as much more money as the amount that is present in the piggybank, which eventually doubles the amount in piggybank. As a result, the money in the piggybank keeps growing. Note that, his father does not deposit any money if the piggybank is empty.
Monk wants to ask God of Money for as minimum dollars as possible. Find the minimum dollars that Monk has to ask from God of Money, so that he has exactly P dollars in his piggybank, irrespective of the number of days he takes.

Input:
The first line consists of integer T. T testcases follow. The first line of each testcase consists of an integer P, denoting the cost of the bicycle.

Output:
For each testcase, print the answer in a single line.

Constraints:
T<=10
P<=10^18

Sample Input
2
1
2
Sample Output
1
1
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
In the second testcase, Monk asks for 1 dollar from God of Money on the first day. He takes the piggybank with 1 Dollar to his father who deposits 1 Dollar, making a total of 2 Dollars i.e. cost of the bicycle.
*/

/*
SOLUTION:
    Since, minimum so he should only take 0 or 1 from the God;
    
    METHOD 1 => Day 1 takes x1, Day2 takes x2,......Day n takes xn.
    Amount after Day 1 = 2x1
    Amount after Day 2 = 4x1 + 2x2
            .
            .
            .
    Amount after Day n = (2^n)x1+(2^n-1)x2+......+2xn => Similar to binary representation of the amount

    To minimise = (x1+x2+x3....+xn) => So: x1,x2,x3....xn = 0 or 1.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        ull p;
        cin>>p;
        cout<<__builtin_popcountll(p)<<"\n";
    }

    return 0;}