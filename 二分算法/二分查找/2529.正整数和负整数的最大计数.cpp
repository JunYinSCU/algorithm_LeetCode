/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 *
 * https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/description/
 *
 * algorithms
 * Easy (70.32%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 80.5K
 * Testcase Example:  '[-2,-1,-1,1,2,3]'
 *
 * 给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。
 * 
 * 
 * 换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
 * 
 * 
 * 注意：0 既不是正整数也不是负整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,-1,-1,1,2,3]
 * 输出：3
 * 解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-3,-2,-1,0,0,1,2]
 * 输出：3
 * 解释：共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [5,20,66,1314]
 * 输出：4
 * 解释：共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2000
 * -2000 <= nums[i] <= 2000
 * nums 按 非递减顺序 排列。
 * 
 * 
 * 
 * 
 * 进阶：你可以设计并实现时间复杂度为 O(log(n)) 的算法解决此问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(log n)
    //空间复杂度O(1)
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int start = lower_bound(nums,0);    //寻找第一个大于等于0的数的位置
        int end = lower_bound(nums,1) - 1; //寻找最后一个大于等于0的位置

        if(start == n)  //如果返回的是数组长度，则说明全都小于0；直接返回数组长度
            return n;

        if(nums[start] == 0){   //如果start位置的数是0，则说明至少存在1个0，此时end位置也必定是0
            return max(start,n-end-1);
        }else{                  //如果start位置的数不是0,那么end其实和start都指向第一个整数
            return max(start,n-start);
        }
    }

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

    }
};
// @lc code=end

