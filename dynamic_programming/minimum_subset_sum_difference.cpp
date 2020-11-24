/*
GFG Link: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

        Minimum Subset Sum Difference

        Given an integer array arr of size N, the task is to divide it
        into two sets S1 and S2 such that the absolute difference between
        their sums is minimum and find the minimum difference.
*/


#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//This is dynamic programming solution
//Not suggested when sum is too large(array will be large)
bool isSubsetSum(int n,int arr[], int sum){

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

//This is recursion solution
//Not suggested when number of element is too large(complexity 2^n)
int findMinDiff(int counter, int num[], int sumCalculated, int sumTotal){
    if (counter == 0){
        return abs(sumTotal - 2* sumCalculated);
    }

    return min( findMinDiff( counter-1, num, sumCalculated + num[counter -1], sumTotal),
               findMinDiff( counter-1, num, sumCalculated, sumTotal));

}


int minDiffernce(int nums[], int n) {
	int sum = 0;

    for (int i = 0; i <n; i++){
        sum += nums[i];
    }

    if (sum < 1000 || n >50){

        int potential_sum = sum / 2;

        while ( !isSubsetSum(n, nums, potential_sum)){
            if ( potential_sum == 0){
                break;
            }
            else{
                potential_sum--;
            }
        }
        return (sum - 2*potential_sum);
    }
    else{
        return findMinDiff( n, nums, 0, sum);
    }
}

int main() {

        int nums[] = { 20, 19, 18,  20, 16 };
        int n = 5;
        cout << minDiffernce(nums, n);
}
