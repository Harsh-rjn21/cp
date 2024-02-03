#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {1,0,3,-3,5};

    auto sum = [](int x,int y){return x+y;};
    
    // bool all = all_of(arr,arr+5,[](int x){return x>0;});
    // bool none = none_of(arr,arr+5,[](int x){return x<0;});
    // bool any = any_of(arr,arr+5,[](int x){return x<0;});

    // cout<<all<<"\n"<<none<<"\n"<<any<<"\n";

    sort(arr,arr+5,[](int a,int b){return abs(a)!=abs(b) ? abs(a)<abs(b) : a<=b;});
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;}