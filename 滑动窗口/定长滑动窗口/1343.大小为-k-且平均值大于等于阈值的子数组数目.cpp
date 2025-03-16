/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(i>=k-1) {
                //if(sum/k>=threshold) res++; 
                if(sum>=k*threshold) res++; //如果并不关心平均值，可以用乘法来计算，更加快
                sum -= arr[i-k+1];
            }
        }
        return res;
    }
};
// @lc code=end

