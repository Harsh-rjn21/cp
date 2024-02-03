#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        bool check = true;
            int mid = n/2;
        if(n%2==1){
            for(int i = 1; i<=mid;i++){
                if(a[mid+i]==a[mid-i] || a[mid+i]-1==a[mid-i]+1 || a[mid+i]+1==a[mid-i]-1){check=true;}
                else{
                    check=false;
                    break;
                }
            }
            }
        else if(n%2==0){
            for(int i = 0; i<mid;i++){
                if(a[mid+i]==a[mid-1-i] || a[mid+i]-1==a[mid-1-i]+1 || a[mid+i]+1==a[mid-1-i]-1){check=true;}
                else{
                    check=false;
                    break;
                }
            }

        }
        check ? cout<<"YES\n":cout<<"NO\n";
    }
    return 0;}