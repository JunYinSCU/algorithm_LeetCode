/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 *
 * https://leetcode.cn/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.96%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    177.4K
 * Total Submissions: 355.1K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
 * 
 * 珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k
 * 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 * 
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 * 
 * 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：piles = [3,6,7,11], h = 8
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：piles = [30,11,23,4,20], h = 5
 * 输出：30
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：piles = [30,11,23,4,20], h = 6
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n * log(max(piles))) 空间复杂度O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxNum = 0;

        for(int i = 0; i < n; i++){
            maxNum = max(maxNum,piles[i]);
        }

        int left = 1;
        int right = maxNum;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(piles,mid,h)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(vector<int>& piles, int k, int h) {
        long long hour = 0;
        for (int i = 0; i < piles.size(); ++i) {
            // 向上取整
            hour += (piles[i] - 1) / k + 1; 
        }
        return hour <= h;
    }
};
// @lc code=end

