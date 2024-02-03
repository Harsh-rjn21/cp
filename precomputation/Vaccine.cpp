/*
Problem
A global pandemic is on the rise. But, somehow a vaccine came to rescue the people in despair. However some of the vaccines available are 'incorrect' (i.e. not upto the mark) and doesn't cure the infected person. Your job is to identify the total number of 'incorrect vaccines' from a grid of available vaccines. An "incorrect vaccine" is one which has an odd number printed on it. All the other vaccine are assumed to be correct.

You will be given a grid of size M X N containing integers and Q queries where each query contains four integers - l1, r1, l2, r2.  For each query you need to answer the number of incorrect vaccines from index (l1, r1) to (l2, r2) in the grid.

Can you help the people and save the world !!

Note: Assume 1-based indexing.

 

Input:

First Line  contains two integers M and N, where M and n are the number of rows and columns in the grid respectively.

Next M lines each contain N space-separated integers each representing the vaccine numbers on ith row of the grid.

Next line contains an integer Q, the number of queries.

Next Q lines contains four integers - l1, r1, l2, r2 representing the coordinates of the grid within which you need to find the number of incorrect vaccines.

 

Output:

Print the number of incorrect vaccines for each query in a new line.

 

Constraints:

1 <= N <= 103

1 <= M <= 103

1 <= Ai <= 109

 

Sample Test Case:

Input:

3 3

1 1 1 

1 2 1

1 1 1

4

1 1 3 3

1 2 1 2

2 2 3 3

2 2 2 2

 

Output:

8

1

3

0
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;
const int N = 1000;
ll arr[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,n;
    cin>>m>>n;

    ll vaccine[m][n];

    for(int i = 0; i <m; i++){
        for(int j = 0; j <n; j++){
            cin>>vaccine[i][j];
             ll x = arr[i][j+1] + arr[i+1][j] - arr[i][j];
            arr[i+1][j+1] = vaccine[i][j] % 2 != 0 ? 1+x : x; 
        }
    }

    int q;
    cin>>q;

    while(q--){
        int l1,l2,r1,r2;
        cin>>l1>>l2>>r1>>r2;

        ll ans = arr[r1][r2] - arr[r1][l2-1] - arr[l1-1][r2] + arr[l1-1][l2-1];

        cout<<ans<<"\n";
    }
    

    return 0;}