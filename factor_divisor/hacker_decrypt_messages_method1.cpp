/*
Problem
Alex has started hacking websites, and also started learning encryption and decryption of messages. Once he faced an interesting issue, where he needs to decrypt the message in a different way.
Initially, he will be given an array A of N integers, and has to decrypt Q messages. In each message he will get an integer X, and if X can be converted into product of two different or same prime numbers, then the real message is "YES" (without quotes), otherwise the message is "NO" (without quotes).

To convert X, he can choose one element from array say Y (X should be divisible Y), and can divide X by Y any number of times (till X is divisible by Y). Help Alex in decrypting the messages.

Input Format:

First line will contain an integer N and Q,, denoting the number of elements in the array and number of encrypted messages respectively.

Next line will contain N space-separated integers representing the elements of the array.

In next Q lines, each line will contain an integer X , representing an encrypted message.

Output Format:

For each encrypted message, output the decrypted message in new line.

Constraints:
N<=10^5
Ai,Q,X<=10^6

Sample Input
4 3
2 22 7 10
16
429
42

Sample Output
YES
NO
YES

Explanation
For X=16,
We can choose 2 from the given array and divide X by 2 , two times, which will result in 4.
As, 4=2*2. So answer is YES.

For X=429, we can't choose any number from the array by using which we can convert X in product of two primes. So answer is NO.

For X=42,
We can choose 2 from the given array and divide X by 2 only one time, which will result in 21.
As, 21=7*3. So answer is YES.
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq primes;
deque<bool> is_prime(1000001, true);
set<int> req_number;
deque<bool> factor_present_in_arr(250001,false);

void seive_algorithm()
{
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= 1000; j += i)
            {
                is_prime[j]=false;
            }
        }
    }
}

void fill_req_numbers(){
    for(int i = 0; i<primes.size();i++){
        for(int j = i; j < primes.size(); j++){
            ull x = primes[i]*primes[j];
            if(x>1000000)break;
            req_number.insert(x);
        }
    }
}

void find_if_it_is_nth_power_of_any_number_in_arr(int arr[],int n){
    for(int i = 0; i<n;i++){
        for(int j = arr[i];j<=250000;j*=arr[i]){
            if(factor_present_in_arr[j]==false){
                factor_present_in_arr[j] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    seive_algorithm();
    fill_req_numbers();

    int n,q;
    cin>>n>>q;
    int arr[n];

    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    find_if_it_is_nth_power_of_any_number_in_arr(arr,n);

    while(q--){
        int x;
        cin>>x;
        deq possible_numbers_which_should_have_a_factor_in_arr;
        bool can_be_converted_to_req_number = false;
        bool ans = false;
        for(auto i : req_number){

            if(i>x)break;

            if((x%i)==0){
                possible_numbers_which_should_have_a_factor_in_arr.push_back(x/i);
                can_be_converted_to_req_number = true;
            }
            else if(x==i){ans = true;}
        } 

        if(can_be_converted_to_req_number && !ans){
             for(auto i : possible_numbers_which_should_have_a_factor_in_arr){
                if(factor_present_in_arr[i]){ans=true;break;}
            }
        }

        ans ? cout<<"YES\n":cout<<"NO\n";
    }

    return 0;
}