/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
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
    double findMaxAverage(vector<int>& nums, int k) {
        // int n = nums.size();
        // double average = 0;
        // double sum = 0;
        
        // int i = 0;
        // while(i<k){ //窗口未占满时
        //     sum += nums[i];
        //     i++;
        // }
        
        // average = sum/k; //更新平均值

        // for(;i<n;i++){
        //     sum -=nums[i-k];//左出
        //     sum += nums[i];//右入

        //     double temp = sum/k;//求现在的平均值
        //     average = max(average,temp);//更新最大平均值
        // }
        // return average;      
        
        int n = nums.size();
        double maxAver = INT_MIN;
        double sum = 0.0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(i>=k-1) { //注意：采用这种统一方法时，当i和k-1相等时，就可以开始计算平均值了
                double aver = sum/k;
                maxAver = max(maxAver,aver);
                sum -= nums[i-k+1]; //注意：这里是i-k+1，而不是i-k，因为i是从0开始的
            }
        }
        return maxAver;
    }

};
// @lc code=end

