#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

// int dp[][];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[n];

    int s = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int starting_at[n],ending_at[n];

    ending_at[0]=1;starting_at[n-1] = 1;

    for(int i = 1; i < n; i++){
        
        if(arr[i]>arr[i-1]){
            ending_at[i] = 1 + ending_at[i-1];
        }
        else{
            ending_at[i] = 1;
        }

        if(arr[n-i]>arr[n-i-1]){
            starting_at[n-i-1] = 1+starting_at[n-i];
        }
        else{
            starting_at[n-i-1] = 1;
        }
    }

    int ans = *max_element(starting_at, starting_at + n);

    for(int i = 1; i < n-1; i++){
        if(arr[i-1]<arr[i+1]){
            int z = ending_at[i-1]+starting_at[i+1];
            ans = max(ans,z);
        }
    }

    cout<<ans;

    return 0;}