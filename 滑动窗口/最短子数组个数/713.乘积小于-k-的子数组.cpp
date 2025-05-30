/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (52.47%)
 * Likes:    848
 * Dislikes: 0
 * Total Accepted:    142K
 * Total Submissions: 270K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,5,2,6], k = 100
 * 输出：8
 * 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 0
 * 输出：0
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        int prod = 1;

        if(k <= 1) return 0;//如果k<=1，那么任何乘积都不会小于k，直接返回0

        for(int right = 0;right < nums.size();right++){
            prod *= nums[right];
            while(prod >= k){  //不满足要求时才缩小窗口
                prod /= nums[left];
                left++;
            }
            res += right - left + 1; //从left left+1 ... right都是满足要求的,总共有right-left+1个
        }

        return res;
    }
};
// @lc code=end

