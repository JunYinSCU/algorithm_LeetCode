/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.96%)
 * Likes:    2605
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 2.7M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [0]
 * 输出: [0]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你能尽量减少完成的操作次数吗？
 * 
 */

// @lc code=start
class Solution {
public:
    //方法一：直接判断，类似与栈
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                swap(nums[k] , nums[i]);
                k++;
            }
        }
    }

    //方法二：双指针
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size();
    //     int left = 0;
    //     int right = 0;
    //     //同向双指针
    //     //左指针指向0，右指针指向非0元素
    //     //当右指针指向非0元素时，交换左右指针指向的元素
    //     //左指针右移，右指针右移
    //     while(right < n){
    //         while(left < n && nums[left] != 0){
    //             left++;
    //         }
    //         if(left >= n){
    //             break;
    //         }
    //         while(right < n && nums[right] == 0){
    //             right++;
    //         }
    //         if(left < right && right < n){  //只有当零在非零的左边时才交换
    //             swap(nums[left],nums[right]);
    //         }
    //         right++; 
    //     }
        
    // }
};
// @lc code=end

