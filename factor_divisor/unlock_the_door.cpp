/*
Problem
Our Friend Monk has finally found the Temple of Programming secrets. However, the door of the temple is firmly locked. Now, as per the rules of the temple, Monk needs to enter a Secret Password in a special language to unlock the door. This language, unlike English consists of K alphabets. The properties of this secret password are:

It has a length of N characters.

It is composed only of the K characters belonging to the Special language.

Each character belonging to the special language has been used at max once in the secret code.

Now, Monk has no idea about what the ideal password may be and needs you help. You need to help Monk find the total number of distinct candidate Strings for it Modulo .10^9 + 7

Input Format:

The first line contains a single integer T denoting the number of test cases. Each of the next T lines contain two integers N and K denoting the length of the Secret Password and the number of characters of the Special language to be used respectively.

Output Format:

For each test case, output the number of possible distinct secret passwords Modulo 10*9 + 7.

Constraints:

1 <= N <= K <= 10^5

Note:

You need to print the value of each element and not their weight.

Sample Input
1
3 3
Sample Output
6
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
Let's number the characters of the special language to be 1 , 2 and 3 respectively. So, all possible candidate Strings are:

123
231
312
132
231
321
So, here we have 6 possible passwords. So, the answer = 6%(10^9 + 7) = 6
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int mod = 1000000007;
using namespace std;

deq fact(100001,1);

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = ((ans%mod) * 1LL * (a%mod)) % mod;}
        a = ((a%mod) * 1LL *(a%mod)) % mod;
        b >>= 1;}
    return ans;}

void factorial(){
    for(int i = 2; i<=100000;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial();
    int N,K;
    cin >> N >> K;

    int inverse = power(fact[K-N],mod-2)%mod;
    cout<<inverse<<"\n";
    int ans = ((fact[K]%mod) * 1LL *(inverse%mod))%mod;
    cout<<ans;
    return 0;}