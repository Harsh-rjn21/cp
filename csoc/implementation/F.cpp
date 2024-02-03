#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq funky;

bool binary_search(int x,int low,int high){
    if(funky[low]==x || funky[high]==x){
        return true;
    }
    bool ans = false;
    while(low<=high){
        int mid = (low+high)/2;
        if(x == funky[mid]){
            ans = true;
            break;
        }
        if(x > funky[mid]){
            low = mid+1;
        }
        if(x < funky[mid]){
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;


    for(int i = 1; ;i++){
        int z = i*(i+1)/2;
        if(z>n)break;
        funky.push_back(z);
    }

    int x = funky.size();

    bool ans = false;

    for(int i = 0; i < x; i++){
        if(binary_search(n-funky[i],0,x-1)){
            ans = true;
            break;
        }
    }
    
    ans ? cout << "YES\n" : cout << "NO\n";
    return 0;}