/*
MAS - Moumita and Assignments
#math #newyear2017

Moumita doesn’t like assignments. Whenever she is given any assignment, she feels helpless and wants to destroy the world. Unfortunately, she has a pending assignment. As she doesn’t know how to do it, she is preparing to destroy everything. Can you help her to complete it and save the world???
The assignment is, you are given an array A of n elements and a function F(A) which is defined as:

  F(A) = (Σ(j) Σ(i) ((A[i]-A[j])^2))%mod

where, mod = 2,760,727,302,517

You have to perform Q queries of the following types:

1 x v  ( which means set A[x] = v. )

2 x v  ( which means add v to A[x] i.e., A[x] = A[x]+v. )

3         ( which means compute F(A) and output it in a single line. )
 

Input

Input starts with an integer T denoting the number of test cases.

The first line of each case contains two integers n and Q. The next line contains n space separated integers, where ith integer denotes the value of A[i].

Each of next Q lines contains a query of the above specified types.

Constraints:

1 ≤ T ≤ 6

1 ≤ x ≤ n ≤ 100000

1 ≤ Q ≤ 100000

0 ≤ A[i], v ≤ 1000000000

Output

For each case, print the case number first. Then for each query of  type 3, print the value of F(A) in each line. See sample I/O for more clarification.

Example
Input:
1
3 5
1 2 3
3
1 1 5
3
2 3 6
3


Output:
Case 1:
6
14
74
*/