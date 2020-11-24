/*
LeetCode Link: https://leetcode.com/problems/partition-equal-subset-sum/

    Partition Equal Subset Sum

    Given a non-empty array nums containing only positive integers,
    find if the array can be partitioned into two subsets such that
    the sum of elements in both subsets is equal.

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isSubsetSum( int n,vector<int>& arr, int sum){
    bool t[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0) {
				t[i][j] = true;
			}
			else if(i == 0) {
				t[i][j] = false;
			}
			else{
				if (arr[i - 1] <= j) {
					t[i][j] = (t[i-1 ][j - arr[i - 1]] || t[i - 1][j]);
				}
				else {
					t[i][j] = t[i - 1][j];
				}
			}
		}
	}
    return t[n][sum];

}

int main() {

	//int n = 5, sum = 14;
	//int arr[] = { 4, 1, 11, 5 };
    vector<int> nums = { 1, 2, 3, 5 };

    int n = nums.size();

    int sum = accumulate(nums.begin(),nums.end(),0);

	if (sum % 2){
        cout << false;
	}
	else{
        cout << isSubsetSum( n, nums, sum/2);
	}
return 0;
}
