/*
LeetCode Link: https://leetcode.com/problems/target-sum/

    Target Sum

    You are given a list of non-negative integers, a1, a2, ..., an,
    and a target, S. Now you have 2 symbols + and -. For each integer,
    you should choose one from + and - as its new symbol.

    Find out how many ways to assign symbols to make sum of integers
    equal to target S.

    */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int targetSum(vector<int>& nums, int sumAsDiff){
    int sumTotal = 0 ;

    for (int num : nums){
        sumTotal += num;
        }
    if (sumTotal < sumAsDiff ||(sumTotal + sumAsDiff) % 2){
        return 0;
    }

    int len = (sumTotal + sumAsDiff)/2 + 1;
    int* t = new int[len] { 0 };
    t[0] = 1;

    for(int num : nums){
        for(int i = len -1; i >= num; i--){
            t[i] += t[ i - num];
        }
    }
    return t[len -1];
}

int main() {
        vector<int> nums = {9,7,0,3,9,8,6,5,7,6};
        int sum = 2;
        cout << targetSum(nums, sum);
        return 0;
}
