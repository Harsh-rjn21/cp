#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

const ll n = 100;
int pf2[n][n];

int main(){

    int N;
    cin>>N;
    int arr[N+1][N+1];

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin >> arr[i][j];
            pf2[i][j] = arr[i][j] + pf2[i-1][j] + pf2[i][j-1] - pf2[i-1][j-1];
        }
    }

    int i1,i2,f1,f2;
    cin>>i1>>i2>>f1>>f2;

    int ans =pf2[f1][f2] - pf2[f1][i2-1] - pf2[i1-1][f2] + pf2[i1-1][i2-1];
    cout<<ans;
    
    return 0;}