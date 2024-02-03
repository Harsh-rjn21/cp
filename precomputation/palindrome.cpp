/*
    Given: A string of n characters
    Query: index l and r
    Find: if we can get palindrome for that part of string
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

const ll N = 1000007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;
        string S;
        cin>>S;

        int arr[n+1][26] = {0};

        for(int i = 1; i <= S.size(); i++)
        {
            arr[i][S[i-1]-'a']++;
        }

        for(int i = 1; i<=S.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                arr[i][j] += arr[i-1][j];
            }
        }
        while(q--)
        {
            int count = 0;
            int l,r;
            cin>>l>>r;

            for(int i = 0;i<26;i++)
            {
                if((arr[r][i] - arr[l-1][i])%2!=0)count++;
            }
            count<=1 ? cout<<"YES\n":cout<<"NO\n";
        }
    }

    return 0;}