#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int hashing[26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;

    int n = a.length();

    for(int i = 0; i < n; i++){
        hashing[a[i]-'a']++;
    }

    int z = 0;

    for(int i = 0; i < 26; i++){
        if(hashing[i]&1)z++;
    }
    if(z==0 || z==1)cout<<"First\n";
    else{
        ((z-1)&1) ? cout<<"Second\n": cout<<"First\n";
    }
    return 0;}