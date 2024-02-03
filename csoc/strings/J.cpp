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

    string s;
    int n;
    cin >> n;

    cin >> s;

    deque<char> str;

    for(int i = 0; i<s.length(); i++){
        str.push_back(s[i]);
    }

    int ans = 0;
    bool check = true;
    while(check){
        int k = -1;
        char x = 'a';
    for(int i = 0; i<str.size();i++){
        if((i-1)>=0 && str[i]==(str[i-1]+1) && str[i]>x){k=i;x=str[i];}
        if((i+1)<str.size() && str[i]==(str[i+1]+1) && str[i]>x){k=i;x=str[i];}
    }
    if(x=='a' || k==-1){check = false;break;}
    else if(k!=-1){
        ans++;
        str.erase(str.begin()+k);
    }
    }
    cout << ans;
    return 0;}