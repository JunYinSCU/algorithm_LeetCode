/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-repair-cars/description/
 *
 * algorithms
 * Medium (50.38%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 66.1K
 * Testcase Example:  '[4,2,3,1]\n10'
 *
 * 给你一个整数数组 ranks ，表示一些机械工的 能力值 。ranksi 是第 i 位机械工的能力值。能力值为 r 的机械工可以在 r * n^2
 * 分钟内修好 n 辆车。
 * 
 * 同时给你一个整数 cars ，表示总共需要修理的汽车数目。
 * 
 * 请你返回修理所有汽车 最少 需要多少时间。
 * 
 * 注意：所有机械工可以同时修理汽车。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ranks = [4,2,3,1], cars = 10
 * 输出：16
 * 解释：
 * - 第一位机械工修 2 辆车，需要 4 * 2 * 2 = 16 分钟。
 * - 第二位机械工修 2 辆车，需要 2 * 2 * 2 = 8 分钟。
 * - 第三位机械工修 2 辆车，需要 3 * 2 * 2 = 12 分钟。
 * - 第四位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
 * 16 分钟是修理完所有车需要的最少时间。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ranks = [5,1,8], cars = 6
 * 输出：16
 * 解释：
 * - 第一位机械工修 1 辆车，需要 5 * 1 * 1 = 5 分钟。
 * - 第二位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
 * - 第三位机械工修 1 辆车，需要 8 * 1 * 1 = 8 分钟。
 * 16 分钟时修理完所有车需要的最少时间。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ranks.length <= 10^5
 * 1 <= ranks[i] <= 100
 * 1 <= cars <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度：O(n*log(maxRank*cars^2))
    //空间复杂度：O(1)
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 0;
        int maxRank = 0;
        for(int i = 0;i < ranks.size();i++){
            maxRank = max(maxRank, ranks[i]); // 最大时间不能超过所有人修完cars的时间
        }
        right = (long long)maxRank*cars*cars;

        while(left <= right){
            long long mid = (long long)(left + (right - left) / 2);
            if(check(ranks,cars,mid)){
                right = mid - 1; // 尝试更小的时间
            }else{
                left = mid + 1; // 时间不够，增加时间
            }
        }
        return left;
    }
    bool check(vector<int>& ranks,int cars,long long time){
        long long count = 0;
        for(int i = 0;i < ranks.size();i++){
            long long r = ranks[i];
            // 计算在time时间内，这个机械工能修几辆车
            count += (long long)sqrt(time / r);
        }
        return count >= cars;
    }
};
// @lc code=end

