#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deque<string> arr;
deque<string> answers;

char give_value(char x, char y){
    if((x=='S' && y=='E') ||(x=='E' && y=='S') )return 'T';
    if((x=='S' && y=='T') ||(x=='T' && y=='S') )return 'E';
    if((x=='T' && y=='E') ||(x=='E' && y=='T') )return 'S';
}

bool binary_search(string x,int low,int high){
    if(x==arr[low] || x==arr[high])return true;

    bool nas = false;

    while(low<=high && !nas){
        int mid = (high+low)/2;
        if(arr[mid]==x){
            nas = true;
            break;
        }
        if(x > arr[mid]){
            low = mid+1;
        }
        if(x < arr[mid]){
            high = mid-1;
        }
    }
    return nas;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(),arr.end());

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            string z ="";
            for(int k = 0; k < m; k++){
                if(arr[i][k]==arr[j][k])z.push_back(arr[i][k]);
                else z.push_back(give_value(arr[j][k],arr[i][k]));
            }
            if(binary_search(z,j+1,n-1)){
                ans++;
                }
        }
    }

    cout << ans;

    return 0;}