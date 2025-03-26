/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.95%)
 * Likes:    1092
 * Dislikes: 0
 * Total Accepted:    825.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;

        while(left <= right){
            //选取平方后最大的数插入到数组尾部
            if(-nums[left] >= nums[right]){
                res[index] = pow(nums[left], 2);
                index--;
                left++;
            }else{
                res[index] = pow(nums[right], 2);
                index--;
                right--;
            }
        }

        return res;
    }
};
// @lc code=end

