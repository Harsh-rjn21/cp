#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq primes;
int dp[1000001];

void seive_algorithm(int maxi){
    int isPrime[maxi+1] = {0};
    for(int i = 2; i <= maxi;i++){
        if(isPrime[i]==0){
            primes.push_back(i);
            for(int j = 2*i;j<=maxi;j+=i){
                isPrime[j] = 1;
            }
        }
    }
}

void solve(int maxi){
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 1; i < primes.size()-1; i++){
        int z = 1+dp[primes[i-1]];
        for(int j = primes[i]; j<primes[i+1];j++){
            dp[j] = z;
        }
    }

    int z = 1 + dp[primes[primes.size()-2]];
    for(int i = primes[primes.size()-1]; i <= maxi;i++){
        dp[i] = z;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int t;
    cin >> t;
    deq ques;

    int x;
    for(int i = 0; i < t; i++){
        cin >> x;
        ques.push_back(x);
    }

    int maxi = *max_element(ques.begin(),ques.end());

    seive_algorithm(maxi);
    solve(maxi);

    for(int i = 0; i<t; i++){
        cout << dp[ques[i]] - dp[(int)sqrt(ques[i])] + 1<<"\n";
    }

    return 0;}