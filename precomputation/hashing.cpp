#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;
ll arr[11];

int main(){
    string a;
    cin>>a;

    for(ll i = 0; i<a.size();i++){
        arr[a[i]-'0']++;
    }
    int z;
    cin>>z;
    cout<<arr[z];
    fact[0] = a[0]-'0';
  
    return 0;}