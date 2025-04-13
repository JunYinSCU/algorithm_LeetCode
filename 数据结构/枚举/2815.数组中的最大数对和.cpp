/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 *
 * [2815] 数组中的最大数对和
 *
 * https://leetcode.cn/problems/max-pair-sum-in-an-array/description/
 *
 * algorithms
 * Easy (72.67%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 20.5K
 * Testcase Example:  '[112,131,411]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。
 * 
 * 返回最大和，如果不存在满足题意的数字对，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [51,71,17,24,42]
 * 输出：88
 * 解释：
 * i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
 * i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
 * 可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：-1
 * 解释：不存在数对满足数位上最大的数字相等。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mp; //记录每个数位和对应的最大值
        int res = -1;

        for(int i = 0; i < nums.size(); i++){
            int sum = getMax(nums[i]);
            if(mp.count(sum)){  //如果左边存在和当前数的数位一致的数，则更新结果
                res = max(res,mp[sum]+nums[i]); //更新结果
                mp[sum] = max(mp[sum],nums[i]); //更新最大值
            }else{
                mp[sum] = nums[i]; //如果不存在，则直接存入
            }
        }
        return res;
    }
    int getMax(int n) {
        int maxDigit = -1;
        while (n > 0) {
            maxDigit = max(n % 10,maxDigit);
            n /= 10;
        }
        return maxDigit;
    }
};
// @lc code=end

