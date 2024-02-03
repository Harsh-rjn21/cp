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

    int t;
    cin >> t;

    while(t--){
        string a;
        cin >> a;

        int n = a.length();

       if((n%2)==1 || a[0]==')' || a[n-1]=='('){cout<<"NO\n";}
       else{
            cout << "YES\n";
       }

    }

    return 0;}