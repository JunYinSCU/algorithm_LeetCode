/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.91%)
 * Likes:    2804
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 3.4M
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
//双指针
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size();
    //     //左指针指向0元素，右指针指向非零元素
    //     int left = 0, right = 0;

    //     while(left <= right && right < n){
    //         //右指针找到非零元素后，和left处元素交换
    //         //最开始left并没有指向非0元素时，和right同步增长，此时交换不会影响元素顺序
    //         //遇到0元素后，left会停留在此，而right会继续寻找非零元素
    //         if(nums[right] != 0){
    //             swap(nums[left],nums[right]);
    //             left++;
    //         }
    //         right++;
    //     }        
    // }

    //栈
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int stackSize = 0;
        //遇到非零元素直接前移到目标位置
        for(int x : nums){
            if(x){
                nums[stackSize++] = x;
            }
        }
        //最后补0
        fill(nums.begin()+stackSize,nums.end(),0);
    }
};
// @lc code=end

