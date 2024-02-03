#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int kings[26][26];
deque<string> king;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string a;

    for(int i = 0; i < n; i++){
        cin >> a;
        king.push_back(a);
        int n = a.length()-1;
        kings[a[0]-'a'][a[n]-'a']++;
    }

    return 0;}