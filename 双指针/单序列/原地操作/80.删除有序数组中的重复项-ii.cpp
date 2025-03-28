/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (63.31%)
 * Likes:    1247
 * Dislikes: 0
 * Total Accepted:    569.4K
 * Total Submissions: 899.2K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
 * 
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 * 
 * 
 * 
 * 说明：
 * 
 * 为什么返回数值是整数，但输出的答案是数组呢？
 * 
 * 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 * 
 * 你可以想象内部操作如下:
 * 
 * 
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 * 
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,2,2,3]
 * 输出：5, nums = [1,1,2,2,3]
 * 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,1,1,1,1,2,3,3]
 * 输出：7, nums = [0,0,1,1,2,3,3]
 * 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3,
 * 3。不需要考虑数组中超出新长度后面的元素。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 已按升序排列
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    //方法一：直接判断
    //时间复杂度O(n)
    //空间复杂度O(1)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     int cnt = 1;    //记录重复次数，初始化为1，因为如果出现重复元素，则至少有两个，所以初始化为1
    //     int k = 1;
    //     if (n <= 2) {
    //         return n;
    //     }

    //     for(int i = 1;i < n;i++){
    //         if(nums[i] == nums[i-1] && cnt<2){
    //             cnt++;
    //             nums[k] = nums[i];
    //             k++;
    //         }else if(nums[i] != nums[i-1]){
    //             cnt = 1;
    //             nums[k] = nums[i];
    //             k++;
    //         }
    //     }
    //     return k;

    // }


    //方法二：栈
    int removeDuplicates(vector<int>& nums) {
        //利用原数组是不严格递增的特点，如果当前元素和栈顶元素的前一个元素不相等，则说明当前元素个数一定不超过2，入栈
        int n = nums.size();
        int stack_size = 2;//当前栈的大小，默认前两个元素入栈

        for(int i = 2;i < n;i++){
            if(nums[i] != nums[stack_size-2]){ //如果当前元素和栈顶元素的前一个元素不相等，则入栈
                nums[stack_size] = nums[i];
                stack_size++;
            }
        }
        return min(stack_size,n);

    }
};
// @lc code=end

