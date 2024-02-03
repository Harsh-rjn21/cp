#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq primes;

void seive_algorithm(){
    bool isPrime[1001] = {0};

    for(int i = 2; i <=1000; i++){
        if(isPrime[i]==0){
            primes.push_back(i);
            for(int j = (2*i) ; j<=1000;j+=i){
                if(isPrime[j]==0){isPrime[j] = 1;}
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    seive_algorithm();

    int t;
    cin >> t;
while(t--){
    int n;
    cin >> n;

    int a;
    deq ans;
    mii res;

    for(int i = 0; i < n; i++){
        cin >> a;

        for(int j = 0; j < a; j++){
            if((a%primes[j]) == 0){
                ans.push_back(j+1);
                res[j+1]++;
                break;
            }
        }
    }

    int z = *max_element(ans.begin(),ans.end());

    cout << z <<"\n";

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }

    cout << "\n";
}
    return 0;}