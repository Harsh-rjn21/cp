/*
Problem
Chef likes toys. His favourite toy is an array of length N. This array contains only integers. He plays with this array every day. His favourite game with this array is Segment Multiplication. In this game, the second player tells the left and right side of a segment and some modulo. The first player should find the multiplication of all the integers in this segment of the array modulo the given modulus. Chef is playing this game. Of course, he is the first player and wants to win all the games. To win any game he should write the correct answer for each segment. Although Chef is very clever, he has no time to play games. Hence he asks you to help him. Write the program that solves this problem.

Input
The first line of the input contains an integer N denoting the number of elements in the given array. Next line contains N integers Ai separated with spaces. The third line contains the number of games T. Each of the next T lines contain 3 integers Li, Ri and Mi, the left side of the segment, the right side of segment and the modulo.

Output
For each game, output a single line containing the answer for the respective segment.

Constraints
1 ≤ N ≤ 100,000
1 ≤ Ai ≤ 100
1 ≤ T ≤ 100,000
1 ≤ Li ≤ Ri ≤ N
1 ≤ Mi ≤ 109
Sample 1:
Input
5
1 2 3 4 5
4
1 2 3
2 3 4
1 1 1
1 5 1000000000

Output
2
2
0
120

*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int hash_of_prime_factors[100001][101];
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

void prime_factorisation(int i,int num){
   for(int j = 1; j<=100; j++){
        hash_of_prime_factors[i][j] = hash_of_prime_factors[i-1][j]; 
   }
   for(int j = 0; j < prime.size(); j++){
        if(num==1)break;

        while((num%prime[j])==0){
            hash_of_prime_factors[i][prime[j]]++;
            num/=prime[j];
        }
   }

}

int power(int a, int b,int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve_algorithm();
    int n;
    cin>>n;

    int arr[n+1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        prime_factorisation(i,arr[i]);
    }
   
    int t;
    cin>>t;
    while(t--){
        int l,r,m;
        cin>>l>>r>>m;

        ull ans = 1;

        for(int i = 2; i <= n; i++){
            int z = hash_of_prime_factors[r][i] - hash_of_prime_factors[l-1][i];
            if(z!=0){
                ans *= power(i,z,m);
                ans%=m;
            }
        }
        ans%=m;
        cout<<ans<<"\n";
    }

    return 0;}