/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    2694
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.7M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,0,1,2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;

        //先排序
        sort(nums.begin(),nums.end());

        int res = 1;
        int current_len = 1;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            //遍历,如果当前数字和前一个数字相同,则跳过计数
            if(nums[i] == nums[i-1])
            {
                continue;
            }else if(nums[i] == nums[i-1] + 1){
                //如果比前一个数大1,则可构成连续序列
                current_len++;
            }else{
                //如果当前数不能和前一个数构成连续序列,则更新结果,重置当前长度
                res = max(res,current_len);
                current_len = 1;
            }
        }
        //循环结束后，处理最后一个序列的长度
        res = max(res,current_len);

        return res;
    }
};
// @lc code=end

