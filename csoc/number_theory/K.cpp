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

    int x,y,n = a.length();

    cin >> x >> y;

    int back[n]={0},front[n]={0};

    int p = 1;

    back[n-1] = (a[n-1] - '0')%y;

    for(int i = n-2; i >= 0; i--){
        p = (p*1LL*10)%y;
        back[i] = (back[i+1] + 0LL + ((a[i]-'0')*1LL*p)%y)%y;
    }    

    front[0] = (a[0]-'0')%x;

    for(int i = 0; i < n-1; i++){
        
        if(front[i]==0 && back[i+1]==0 && a[i+1]!='0'){
            cout << "YES\n" << a.substr(0,i+1) << "\n" << a.substr(i+1);
            return 0;
        }

        front[i+1] = ((10*1LL*front[i])%x + 0LL + (a[i+1]-'0')%x)%x;
    }

    cout << "NO\n";

    return 0;}