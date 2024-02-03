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
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]>=0){
            arr[i] = (-1) * (arr[i] + 1);
        }
    }

    if(n&1){int index = 0;
    int mini = arr[index];

    for(int i = 0; i< n; i++){
        if(mini>arr[i]){
            mini = arr[i];
            index = i;
        }
        }
        arr[index] = (-1)*(arr[index]+1);
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;}