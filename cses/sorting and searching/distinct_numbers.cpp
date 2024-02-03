#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int arr[200007];

void merge(int arr[], int low, int mid, int high){
    int temp[high-low+1];
    int i = low,j=mid+1,k=0;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            ++i;
            ++k;
        }
        else{
            temp[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        ++i;++k;
    }
    while(j<=high){
        temp[k] = arr[j];
        ++j;++k;
    }

    rp(h,0,high-low+1){
        arr[h+low] = temp[h];
    }
}

void merge_sort(int arr[], int low, int high){
        if(low>=high)return;
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i,0,n)cin >> arr[i];

    merge_sort(arr,0,n-1);

    int ans = 1;
    rp(i,1,n){
        if(arr[i]!=arr[i-1])ans++;
    }

    cout << ans << "\n";

    return 0;}