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
    int a;
    ll pre_sum[n+1];
    pre_sum[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> a;
        pre_sum[i] = a+pre_sum[i-1];
    }

    if((pre_sum[n]%3)!=0 || n<3){
        cout<<"0\n";
    }
    else if(pre_sum[n]==0){
        ull ans = 0;

        for(int i = 1; i<n; i++){
            if(pre_sum[i]==0){
                ans++;
            }
        }
        ull z = 0;
        if(ans==1)z=0;
        else{
            z = ans*(ans-1)/2;
        }
        cout << z << "\n";
    }
    else {
        int start = 0,end = 0;

        ull s = pre_sum[n]/3;
        ull ans1 = 0,ans2=0;
        for(int i = 0; i < n; i++){
            if(pre_sum[i+1]==s){
                ans1++;
            }
            if(pre_sum[n]-pre_sum[i]==s){
                ans2++;
            }
        }

        cout<<ans1*ans2<<"\n";    }

    return 0;}