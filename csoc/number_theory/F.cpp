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

    mii primes;

    int n;
    cin >> n;
    ll ans = 0,z = n,sq = sqrt(n);
    set<int> num;
    for(int j = 2; j<=sq;j++){
        if((z%j)==0)num.insert(j);
        while(z%j==0){
            primes[j]++;
            z/=j;
        }
    }
    if(z!=1){num.insert(z);primes[z]++;}


    if(n==1){cout << n <<" "<<0<<"\n";return 0;}

    int maxi = 0;
    int k = 0;
    bool check = false;

    ll mini = 1;
    for(auto i : primes){
        maxi=max(maxi,i.second);
        mini*=i.first;
    }
    for(int i = 0; i<maxi; i++){
        if((1<<i)>=maxi){
            k=i;
            break;
        }
    }

    maxi = (1<<k);
    for(auto i : primes){
        if(i.second == maxi)continue;
        else{check = true;
        break;}
    }

    check ? cout << mini <<" " << 1+k : cout << mini<<" " << k;

    return 0;}