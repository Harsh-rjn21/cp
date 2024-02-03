#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin>>a;

    stack<char> s;

    bool correct = true;

    for(auto i : a){

        if(i=='(' || i=='[' || i=='{'){s.push(i);}

        else if((i==']'||i==')'||i=='}') && s.empty()){
            correct = false;
            break;
        }

        else if((i==']' && s.top()=='[')||(i=='}' && s.top()=='{')||(i==')' && s.top()=='(')){s.pop();}
        else{
            correct = false;
            break;
        }
    }

    (correct && s.empty()) ? cout<<"TRUE\n" : cout<<"FALSE\n";

    return 0;}