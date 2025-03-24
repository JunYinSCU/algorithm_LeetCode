/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
 *
 * algorithms
 * Medium (41.36%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 59.1K
 * Testcase Example:  '[1,5,4,2,9,9,9]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：
 * 
 * 
 * 子数组的长度是 k，且
 * 子数组中的所有元素 各不相同 。
 * 
 * 
 * 返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。
 * 
 * 子数组 是数组中一段连续非空的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,5,4,2,9,9,9], k = 3
 * 输出：15
 * 解释：nums 中长度为 3 的子数组是：
 * - [1,5,4] 满足全部条件，和为 10 。
 * - [5,4,2] 满足全部条件，和为 11 。
 * - [4,2,9] 满足全部条件，和为 15 。
 * - [2,9,9] 不满足全部条件，因为元素 9 出现重复。
 * - [9,9,9] 不满足全部条件，因为元素 9 出现重复。
 * 因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [4,4,4], k = 3
 * 输出：0
 * 解释：nums 中长度为 3 的子数组是：
 * - [4,4,4] 不满足全部条件，因为元素 4 出现重复。
 * 因为不存在满足全部条件的子数组，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)，空间复杂度O(n)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = INT_MIN;
        long long sum = 0;
        int left = 0;
        unordered_map<int, int> numMap;

        for(int i = 0;i < nums.size();i++){ //循环遍历
            sum += nums[i];  //1.右指针进
            numMap[nums[i]]++;

            if(i >= k-1){ //当窗口大小达到K时
                if(numMap.size() == k){
                    res = max(res, sum); //2.满足要求时更新结果
                }
                sum -= nums[left]; //3.左指针出
                numMap[nums[left]]--; //4.更新其他信息
                if(numMap[nums[left]] == 0){
                    numMap.erase(nums[left]);
                }
                left++;
            }
            
        }
        return res == INT_MIN ? 0 : res;
    }
};
// @lc code=end

