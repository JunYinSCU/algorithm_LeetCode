/*
 * @lc app=leetcode.cn id=3281 lang=cpp
 *
 * [3281] 范围内整数的最大得分
 *
 * https://leetcode.cn/problems/maximize-score-of-numbers-in-ranges/description/
 *
 * algorithms
 * Medium (36.46%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 15.1K
 * Testcase Example:  '[6,0,3]\n2'
 *
 * 给你一个整数数组 start 和一个整数 d，代表 n 个区间 [start[i], start[i] + d]。
 * 
 * 你需要选择 n 个整数，其中第 i 个整数必须属于第 i 个区间。所选整数的 得分 定义为所选整数两两之间的 最小 绝对差。
 * 
 * 返回所选整数的 最大可能得分 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： start = [6,0,3], d = 2
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 可以选择整数 8, 0 和 4 获得最大可能得分，得分为 min(|8 - 0|, |8 - 4|, |0 - 4|)，等于 4。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： start = [2,6,13,13], d = 5
 * 
 * 输出： 5
 * 
 * 解释：
 * 
 * 可以选择整数 2, 7, 13 和 18 获得最大可能得分，得分为 min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|,
 * |7 - 18|, |13 - 18|)，等于 5。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= start.length <= 10^5
 * 0 <= start[i] <= 10^9
 * 0 <= d <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
/*
先将数组进行排序，如果绝对差越大，那么下一个数就越可能超出范围，则具有单调性，可以二分
*/
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int l = 0;
        int r = (start.back() + d - start[0]) / (start.size() - 1) + 1;;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(start, d, mid)){   //如果满足条件，说明可以选择更大的数，l左边染红
                l = mid+1;
            }else{
                r = mid-1;  //r右边染蓝
            }
        }
        return r;
    }

    bool check(vector<int>& start,int d,int score){
        int n = start.size();
        long long x = LLONG_MIN;//x为选择的上一个数
        for(int i = 0;i < n;i++){
            x = max(x+score,(long long)start[i]);   //选择下一个数，如果x+score小于start[i]，那么就选择start[i]，因为必须要在区间内
            if(x > start[i]+d) return false;    //如果x大于start[i]+d，说明选择的数超出范围了，返回false       
        }
        return true;
    }
};
// @lc code=end

