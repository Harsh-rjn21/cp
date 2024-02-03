#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

string check_odd_even(int num){
    return num&1 ? "odd" : "even";
}

int multiply_by_2(int num){
    return (num<<1);
}

int divide_by_2(int num){
    return (num>>1);
}
char lower_to_upper(char c){
    return ('_'&c);
}
char upper_to_lower(char c){
    return (' ' | c);
}
bool check_nth_power_of_2(int num){
    return !(num & (num-1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num = 9;

    char c = 'c';
    char d = 'D';

    cout<<check_odd_even(num)<<"\n";
    cout<<divide_by_2(num)<<"\n";
    cout<<multiply_by_2(num)<<"\n";
    cout<<lower_to_upper(c)<<"\n";
    cout<<upper_to_lower(d)<<"\n";
    cout<<check_nth_power_of_2(8)<<"\n";
    cout<<check_nth_power_of_2(7)<<"\n";
    return 0;}