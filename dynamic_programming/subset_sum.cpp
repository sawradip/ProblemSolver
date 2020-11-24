/*
HackerEarth Link: https://www.hackerearth.com/problem/algorithm/subset-sum-2/

    Given a set A which contains elements ranging from 1 to N.Find
    the sum of the elements in all possible subsets of the given set.

    Input Format:
    T, the number of test cases. Following T lines contain N, number
    of elements in set.

    Output Format:
    T lines indicating the subset sum. print the answer modulo (109+7).

*/

#include<iostream>

using namespace std;

int subset_sum(int n){

    long long subset_num[n+1] = {0}, sum[n+1] = {0};

    subset_num[1] = 1;
    sum[1] = 1;
    for (int i = 2; i <= n; i++){

        subset_num[i] = 2*subset_num[i-1] +1;
        sum[i] = (2*sum[i-1] + (subset_num[i-1]+1)*i);
    }
    return sum[n]% 1000000007;
}

int main(){

    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){

        cin >> n;
        cout  << subset_sum(n) << endl;
    }
}
