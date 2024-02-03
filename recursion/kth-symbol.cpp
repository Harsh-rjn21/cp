/*
 K-th Symbol in Grammar

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

Example 1:
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

Example 2:
Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01

Example 3:
Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
 

Constraints:
1 <= n <= 30
1 <= k <= 2n - 1
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int n,k;

void generate_string(int N, string &s){
    if(N==n) return ;

    int i = 0;

    while(i!=s.size()){

        if(s[i]=='0'){
            s.replace(i,1,"01");
            i+=2;
        }
        if(s[i]=='1'){
            s.replace(i,1,"10");
            i+=2;
        }
    }

    generate_string(N+1,s);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    string s = "0";

    generate_string(1,s);
    
    cout<<s[k-1];
    return 0;}