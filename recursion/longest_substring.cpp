/*
Longest Substring with At Least K Repeating Characters
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:
1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int k;
    cin>>k;

    map<char,int> m;

    for(int i = 0; i<s.size();i++){
        if(m.count(s[i])){m[s[i]]++;}
        else{
            m.insert({s[i],1});
        }
    }

    int ans = 0;

    for(auto i:m){
        ans = i.second>=k ? ans+i.second : ans;
    }

    cout<<ans;

    return 0;}