/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode.cn/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (38.53%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    170.1K
 * Total Submissions: 441.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：c = 3
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <cmath>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    bool judgeSquareSum(int c) {
        int maxSqrt = sqrt(c);
 
        vector<long long> num(maxSqrt + 1); //根据c的大小确定平方数组的大小
        for(int i = 0; i < maxSqrt + 1;i++)
        {
            num[i] = i*i;
        }

        for(int left = 0,right = maxSqrt;left <= right;){
            //寻找符合的元素对
            if(num[left] + num[right] == c){
                return true;
            }else if(num[left] + num[right] > c){
                right--;
            }else{
                left++;
            }
        }

        return false;
    }
};
// @lc code=end

