/*
Problem
You are given an integer C such that the XOR of two integers C  is . In short A⊕ B = C (⊕ denotes the bitwise the XOR operation).

Out of all possible pairs of A and B, you must find two integers such that their product is maximum. 

Let us define L(C) as the length of C in its binary representation. Then, L(A)<=L(C) and L(B)<=L(C).

Input format 

A single integer representing C (0<=C<=10^5)

Output format 

Print the maximum product you can achieve under the given conditions.

Sample Input
13
Sample Output
70

Explanation
The binary representation of 13 is "1101".

We can use A=10 ("1010" in binary) and B=7 ("0111" in binary). This gives us the product 70. No other valid pair (A,B) can give us a larger product.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;
deq products;

void max_product(int c,int index,int a,int b){
    int z = (1<<index);
    if(z>c){products.push_back(a*b);return;}

    if((z&c)==0){
        a = a | z;
        b = b | z;
        max_product(c,index+1,a,b);
    }
    else if((z&c)!=0){
        a = a | z;
        max_product(c,index+1,a,b);
        a = a & (~z);
        b = b | z;
        max_product(c,index+1,a,b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin>>c;
    max_product(c,0,0,0);
    
    int ans = *max_element(products.begin(),products.end());
    cout<<ans;
    return 0;}