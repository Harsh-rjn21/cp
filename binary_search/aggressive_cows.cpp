/*
AGGRCOW - Aggressive cows

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
Input:
1
5 3
1
2
8
4
9

Output:
3

Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int N;
int c;
int arr[10];

bool check_distance_possible(int x){
    int y = c-1;
    bool update = true;
    int distance = 0;

    for(int i=1; i<N; i++){
        if(update){distance=0;}
        if(y==0)break;
        distance += (arr[i] - arr[i-1]);
        if(distance>=x){update = true; --y;}
        else{update = false;}
    }

    return y<=0;
}

int max_minimum_distance(){
    int low = 0,high = arr[N-1]-arr[0];

    while(high - low > 1){
        int mid = (high+low)/2;
        
        if(check_distance_possible(mid)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    if(check_distance_possible(high))return high;
    else return low;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){

    cin>>N>>c;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    sort(arr,arr+N);

    int ans = max_minimum_distance();
    cout<<ans;}

    return 0;}