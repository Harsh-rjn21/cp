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

    int n;
    cin >> n;

    int a;

    mii primes;

    for(int i = 0; i < n; i++){
        cin >> a;
        float z = sqrt(a);
        for(int j = 2;j<=z;j++){
            if((a%j)==0)primes[j]++;              

            while((a%j)==0)a/=j;
        }
        if(a>1)primes[a]++;
    }

    int ans = 1;
    for(auto i : primes){
        if(ans<i.second)ans = i.second;
        // cout << i.first << " " << i.second<<"\n";
    }    

    cout << ans;

    return 0;}