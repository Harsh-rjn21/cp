#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int hash_map[1000007][27];
int b_hash[26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;

    int n = a.length();

    for(int i = 0; i < n; i++){
        if(a[i]=='?')hash_map[i+1][26] = 1 + hash_map[i][26];
        else hash_map[i+1][26] = hash_map[i][26];
        for(int j = 0;j<26;j++){
            if(a[i]=='a'+j)hash_map[i+1][j] = 1+hash_map[i][j];
            else hash_map[i+1][j] = hash_map[i][j];
        }
    }

    string b;
    cin >> b;

    int m = b.length();


    for(int i = 0; i < m; i++){
        b_hash[b[i]-'a']++;
    }

    int ans = 0;

    for(int i = 1; i<=(n-m+1);i++){
    
        int ques = hash_map[i+m-1][26] - hash_map[i-1][26];

        bool check = true;
        for(int j = 0; j<26; j++){
            int x = hash_map[i+m-1][j] - hash_map[i-1][j];
            if(x>=b_hash[j])continue;
            if(ques>=(b_hash[j]-x)){
                ques-=(b_hash[j]-x);
            }
            else{
                check = false;
                break;
            }
          
        }
        if(check)ans++;        
    }

    cout << ans<<"\n";

    return 0;}