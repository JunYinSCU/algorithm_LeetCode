/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (44.95%)
 * Likes:    2966
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度O(log n)
    //空间复杂度O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums,target);
        int end = lower_bound(nums,target+1)-1;
        if(start == nums.size() || nums[start] != target) //如果start越界或者nums[start] != target，说明没有找到target
                                            //因为第一个大于等于target的元素不一定是target，就好比如果数组中没有target：6，返回的是7的位置
            return vector<int>{-1,-1};
        return vector<int>{start,end};
    }

    //寻找大于等于target的第一个位置
    int lower_bound(vector<int> nums,int target){
        //闭区间写法
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){   //相遇时的位置也要判断
            int mid = left + (right - left) / 2;
            
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;    //left是第一个大于等于target的元素的位置
        // return right + 1;  //right是最后一个小于target的元素的位置
        //如果全都小于target，left = 0, right = -1, left = 0
        //如果全都大于target，left = n, right = n - 1, left = n
    }
};
// @lc code=end

