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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string a;
        cin >> a;

        int arr[n] = {0};
        int z = 0;

        for(int i = 0; i < n; i++){
            if(a[i]=='*'){
                arr[z] = i;
                ++z;
            }
        }

        int x = z/2;
        int r = arr[x]+1,l=arr[x]-1;
        ll ans = 0;
        for(int i = x+1;i<z;i++){
            ans+=abs(r-arr[i]);
            r++;
        }
        for(int i = x-1;i>=0;i--){
            ans+=abs(arr[i]-l);
            l--;
        }
        cout << ans<<"\n";
    }

    return 0;}