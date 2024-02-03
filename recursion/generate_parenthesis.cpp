/*
Problem
Given n pairs of parentheses, write a function to brackets all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

deque<string> answer;

void brackets(int no, int nc,string s){
    if(no==0 && nc==0){answer.push_back(s);return;}
    if(no!=0){s.push_back('(');brackets(no-1,nc,s);s.pop_back();}
    if(nc>no && nc!=0){s.push_back(')');brackets(no,nc-1,s);s.pop_back();}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int no =n,nc=n;
    string s ="";
   
    brackets(no,nc,s);
   
    for(auto i : answer){
        cout<<i<<"\n";
    }
    
    return 0;}