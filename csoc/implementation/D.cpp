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

    string str;
    cin >> str;

    map<double,int> ans;

    double l = 0;
    double r = 1;

    deq right;
    deq left;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'l')left.push_back(i+1);
        if(str[i] == 'r')right.push_back(i+1);
    }

    reverse(left.begin(), left.end());

    for(int i = 0; i < right.size(); i++) {
        cout << right[i]<<"\n";
    }
    for(int i = 0; i < left.size(); i++) {
        cout << left[i]<<"\n";
    }
    

    return 0;}