#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;

    int n = a.length();

    int index = 0;

    for(int i = 0; i < n; i++){
        if(a[i]=='0'){
            index = i;
            break;
        }
    }

    for(int i = index; i < (n-1); i++){
        a[i] = a[i+1];
    }

    a.pop_back();

    cout << a;

    return 0;}