#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int n;
deque<pii> primes;

void seive_algorithm(int n){
    int isPrime[n+1]={0};

    for(int i = 2;i<=n;i++){

        if(isPrime[i]==0){
            primes.push_back({0,i});
            for(int j = 2*i;j<=n;j+=i){
                isPrime[j] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxi = *max_element(a,a+n);
    seive_algorithm(maxi);
    for(int i = 0; i < n; i++){
        int j = 0;
        while(a[i]>1 && j<primes.size()){
            if((a[i]%(primes[j].second)) == 0)primes[j].first++;
            while(a[i]%(primes[j].second) == 0){a[i]/=(primes[j].second);}
            ++j;
        }
    }

    pii ans = *max_element(primes.begin(), primes.end());    
    
    cout << ans.first;

    return 0;}