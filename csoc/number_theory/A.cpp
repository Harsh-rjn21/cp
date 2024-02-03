#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;
    
int a[100007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x = 1;

    for(int i = 2; i <= n; i++) {
        if(a[i]!=0)continue;
        for(int j = i; j <= n; j+=i) {
            a[j]=x;
        }
        ++x;
    }

    for(int i = 2; i <= n; i++) {
        cout << a[i]<<" ";
    }

    return 0;}