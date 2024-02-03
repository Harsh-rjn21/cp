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
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    if(n==1){cout<<"-1\n";return 0;}
        set<int> ans;
    if(n==2){
        int d = arr[1] - arr[0];
        if(d==0){
            ans.insert(arr[0]);
        }
        else if((d%2)==0){
            ans.insert(arr[0]-d);
            ans.insert(arr[1]+d);
            ans.insert((arr[0]+arr[1])/2);
        }
        else if((d%2)!=0){
            ans.insert(arr[0]-d);
            ans.insert(arr[1]+d);
        }
        
    }
        set<int> diff;
        map<int,set<int>> differ;
    if(n==3){
        for(int i = 1; i<n; i++){
            int d = arr[i]-arr[i-1];
            diff.insert(d);
            if(differ.count(d)){
                differ[d].insert(i);
            }
            else{
                set<int> j;
                j.insert(i);
                differ.insert({d,j});
            }
        }
        if(diff.size()==1){
            int d = *(diff.begin());
            ans.insert(arr[0]-d);
            ans.insert(arr[n-1]+d);
        }
        else{
            deq h;

            for(auto i : diff){
                h.push_back(i);
            }

            if(h[1]!=(2*h[0])){
                cout << 0;return 0;
            }

            int l = *(differ[h[1]].begin());
            ans.insert(arr[l]-h[0]);
        }
    }
    if(n>=4){

        for(int i = 1; i<n; i++){
            int d = arr[i]-arr[i-1];
            diff.insert(d);
            if(differ.count(d)){
                differ[d].insert(i);
            }
            else{
                set<int> j;
                j.insert(i);
                differ.insert({d,j});
            }
        }
        if(diff.size()==1){
            int d = *(diff.begin());
            ans.insert(arr[0]-d);
            ans.insert(arr[n-1]+d);
        }
        else if(diff.size()==2) {
            int d = 0;
            int l = 0;
            int d0 = 0;
            for(auto i : diff){
                if(differ[i].size()==1){
                    l = *(differ[i].begin());
                    d0=i;
                }
                else{
                    d = i;
                }
            }
            if(d0==0 || d0!=(2*d)){
                cout<<0;return 0;
            }
            ans.insert(arr[l]-d);
        }
        else{
            cout<<0;return 0;
        }
    }
    cout<<ans.size()<<"\n";
        for(auto i : ans){
            cout<<i<<" ";
        }

    return 0;}