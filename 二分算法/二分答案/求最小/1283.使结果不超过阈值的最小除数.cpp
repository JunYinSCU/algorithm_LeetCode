/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 *
 * [1283] 使结果不超过阈值的最小除数
 *
 * https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 * algorithms
 * Medium (54.90%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 49.1K
 * Testcase Example:  '[1,2,5,9]\n6'
 *
 * 给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
 * 
 * 请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
 * 
 * 每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
 * 
 * 题目保证一定有解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,5,9], threshold = 6
 * 输出：5
 * 解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
 * 如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,3,5,7,11], threshold = 11
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [19], threshold = 5
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 1 <= nums[i] <= 10^6
 * nums.length <= threshold <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
    public:
        //时间复杂度：O(n * log(max(nums)))，n为数组长度，max(nums)为数组中的最大值
        /*
            二分查找的思路是：我们可以在1到max(nums)之间二分查找一个除数d，来使得所有元素除以d后求和不超过threshold
        */
        int smallestDivisor(vector<int>& nums, int threshold) {
            //二分查找闭区间写法
            int left = 1;   // 除数最小为1
            int right = 0;
            // 找到数组中的最大值，作为二分查找的右边界，因为除数如果大于数组中的最大值，那么每个数除以它都为1
            for(int i = 0; i < nums.size(); i++){
                right = max(nums[i],right);
            }
    
            while(left <= right){
                int mid = left + (right - left) / 2;
    
                if(check(nums,mid,threshold)){//如果满足，那么比mid更大的数，结果也满足，由于求最小，所以染为红色
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
    
            return left;    //因为左边是蓝色，返回指向蓝色的指针，即left
    
        }
    
        //check函数用来判断当前除数d是否可以使得所有元素除以d后求和不超过threshold
        bool check(vector<int>& nums,int d,int threshold){  
            int sum  = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += upDivision(nums[i],d);
            }
    
            return sum <= threshold;
        }
    
        int upDivision(int num,int div){
            return (num - 1) / div + 1;
        }
    };
// @lc code=end

