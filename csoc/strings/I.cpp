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
    int s,t;
    cin >> s>>t;
    cin >> a;  

    string b = "";

    set<char> alpha;

    for(int i = 0; i<a.length();i++){
        alpha.insert(a[i]);
    }

    if(t>s){
        b = a;
        char z = *(alpha.begin());
        for(int i = 0; i<(t-s);i++){
            b.push_back(z);
        }
    }  
    else{
        b = a.substr(0,t);
        char z = *(alpha.begin());
        char y = *(--alpha.end());
        for(int i = (b.length()-1);i>=0;i--){
            if(b[i]==y)b[i]=z;
            else{
                char h = *(++alpha.find(b[i]));
                b[i] =  h;
                break;
            }
        }
    }

    cout << b;
    return 0;}