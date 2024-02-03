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
 
    ull t;
    cin >> t;
   while(t--){
    ull n,k;
    cin >> n >> k;
    
    int arr[n];
 
    deque<pii> effective_damage;
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        effective_damage.push_back({arr[i]-n+1+i,i});
    }
 
    sort(effective_damage.begin(), effective_damage.end());
    reverse(effective_damage.begin(), effective_damage.end());
 
    ull ans = 0;
 
    for(int i = 0; i < k; i++){
        int index = effective_damage[i].second ;
        ans += (n-1-index);
    }
    ll decre = k*(k-1);
    ans -= (decre/2);
    for(int i = k; i < n; i++){
        int index = effective_damage[i].second ;
        ans += arr[index];
    }
 
    cout << ans <<"\n";}
 
    return 0;}