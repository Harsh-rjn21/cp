#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

deque<bool> d(101,true);
deque<int> prime;
deq highest_prime_divisor(101);
deq lowest_prime_divisor(101);

void sieve_algorithm(){
    d[0] = false;
    d[1] = false;
    for(int i = 2; i<=100;i++){
        if(d[i]){
            highest_prime_divisor[i] = lowest_prime_divisor[i] = i;
            prime.push_back(i);
            for(int j = 2*i; j<=100; j+=i){
                if(d[j]==true){lowest_prime_divisor[j]=i;}
                d[j] = false;
                highest_prime_divisor[j] = i;
            }
        }
    }
}
deq prime;

deque<bool> d(101,true);
void sieve_algorithm(){
    d[0] = false;
    d[1] = false;
    for(int i = 2; i<=100;i++){
        if(d[i]){
            prime.push_back(i);
            for(int j = 2*i; j<=100; j+=i){
                d[j] = false;
            }
        }
    }
}
deq prime_factors;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve_algorithm();
    int num;
    cin>>num;

    int x;
    int i = 0;
    while(num>1){
        x = prime[i];
        while(num%x==0){
            prime_factors.push_back(x);
            num/=x;
        }
        ++i;
    }

    for(auto i : prime_factors){
        cout<<i<<" ";
    }

    return 0;}