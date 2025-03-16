/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
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
    vector<int> getAverages(vector<int>& nums, int k) {
        long sum = 0;
        
        int n = nums.size();
        vector<int> res(n,-1);
        if(k == 0 )
        {
            return nums;
        }
        if(n < 2*k+1)
        {
            return res;
        }
            
        for(int j = 0 ;j<2*k;j++){//先计算前2k个数的和
            sum += nums[j];
        }

        for (int i = k; i < n-k; i++) {//达到2k后，开始更新窗口
            
            sum += nums[i+k];
            res[i] = sum / (2*k+1);
            sum -= nums[i-k];
        }

        return res;
    }
};
// @lc code=end

