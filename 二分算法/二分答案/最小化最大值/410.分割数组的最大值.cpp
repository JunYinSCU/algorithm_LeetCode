/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode.cn/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (60.65%)
 * Likes:    1043
 * Dislikes: 0
 * Total Accepted:    102.1K
 * Total Submissions: 168.3K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组，使得这 k 个子数组各自和的最大值 最小。
 * 
 * 返回分割后最小的和的最大值。
 * 
 * 子数组 是数组中连续的部份。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [7,2,5,10,8], k = 2
 * 输出：18
 * 解释：
 * 一共有四种方法将 nums 分割为 2 个子数组。 
 * 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4,5], k = 2
 * 输出：9
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,4,4], k = 3
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= min(50, nums.length)
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    二分答案，顾名思义就是对答案二分，注意到：非负整数，连续等字眼，可以考虑是否具有单调性。
    如果最小和越小，那么就说明划分的段数越多。反之则段数越少。这符合单调性。
    我们就可以通过判断当前最小和的划分段数是否小于给定的k即可进行二分。
    */
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxNum = 0; 

        for(int i = 0; i < nums.size(); i++){
            maxNum = max(maxNum,nums[i]);
            sum += nums[i];
        }

        int right = sum;
        int left = maxNum;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(nums,mid,k)){  //如果当前最小和满足要求，说明此时划分段数还没超过k，还可以继续缩小最小和，来增大段数
                right = mid - 1;    //所以需要右指针左移，染为红色
            }else{
                left = mid + 1;     //反之，左边染为蓝色
            }
        }

        return left;    //最后蓝色为要求的答案，所以返回left
    }

    bool check(vector<int> nums, int minSum,int k){
        int cnt = 1;    //段数，初始为1
        int curSum = 0; //当前段的和
        for(int i = 0; i < nums.size(); i++){
            if(curSum + nums[i] > minSum){  //如果加上下个数超过了给定的最小和，就要单开一段，并把这个数分到下一个段中
                curSum = nums[i];
                cnt++;
            }else{
                curSum += nums[i];  //否则加入当前段中
            }
        }
        return cnt <= k;    //判断是否小于给定的段数k
    }
};
// @lc code=end

