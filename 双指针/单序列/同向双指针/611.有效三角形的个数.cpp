/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode.cn/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (54.40%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    122.3K
 * Total Submissions: 224.8K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,2,3,4]
 * 输出: 3
 * 解释:有效的组合是: 
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [4,2,3,4]
 * 输出: 4
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //时间复杂度O(n^2)
    //空间复杂度O(1)
    //方法一：排序+同向双指针
    // int triangleNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //     sort(nums.begin(), nums.end());

    //     for(int i = 0;i < n - 2;i++){
    //         int left = i + 1;
    //         int right = i + 2;

    //         if(nums[i] == 0) continue; //0不能作为三角形的边,由于已经排好序，所以0只会出现在nums[i]，直接跳过

    //         while(right < n){
    //             if(nums[i] + nums[left] > nums[right]){ //满足三角形的条件
    //                 ans += right - left; //如果此时right符合，那么left在left到right-1的数都符合，一共right-left个
    //                 right++;    //right右移
    //             }else{
    //                 left++; //如果不满足，left右移
    //                 if(left == right){  //如果left和right重合，right右移
    //                     right++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;

    // }

    //方法二：排序+相向双指针
    //时间复杂度O(n^2)
    //空间复杂度O(1)
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = n - 1;i >= 2;i--){
            int left = 0;
            int right = i - 1;
            while(nums[left] == 0) left++;

            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    ans += right - left;
                    right--;
                }else{
                    left++;
                }
            }
            
        }
        
        return ans;

    }
};
// @lc code=end

