/*
Problem
Joe is not good with strings, so you volunteer for his help in his task with strings.

Given a string(consisting of small case alphabets only), we need to find the length of largest possible palindrome for all queries , where each query contains an integer N , and the next line of the query includes N space seperated lowercase alphabets.You must keep the following things in mind:

1. For each query, you can use only the characters mentioned in the query to form the palindrome string.

2.Palindromic string can be produced using the alphabets of the input string in any order.

 

INPUT FORMAT -

First line contains the string.

The next line takes as input an integer q(denoting the number of queries).

For each query -

The first line contains an integer N denothing number of alphabets.

Next line consist of N space seperated alphabets(alphabets maybe repeated but yet you need to consider them once only).

 

OUTPUT FORMAT-

For each query, print the maximum size of palindrome possible only using the alphabets given in the query.

 

CONSTRAINS-

1≤|S|≤10000

1≤q≤10000

1≤N≤26
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int arr[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;

    while(q--){

        memset(arr, 0, sizeof(arr));

        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            char x;
            cin>>x;
            arr[x-'a']++;
        }

        bool odd = false;

        int maxi = 0;

        for(int i=0;i<26;i++){
            maxi+=(arr[i]/2);
            if(arr[i]%2!=0){odd=true;}
        }

        int ans = odd ? (2*maxi)+1 : 2*maxi;
        cout<<ans<<"\n";
    }

    return 0;}