/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-complete-trips/description/
 *
 * algorithms
 * Medium (37.86%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    40.7K
 * Total Submissions: 107.4K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个数组 time ，其中 time[i] 表示第 i 辆公交车完成 一趟旅途 所需要花费的时间。
 * 
 * 每辆公交车可以 连续 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 立马开始 下一趟旅途。每辆公交车 独立
 * 运行，也就是说可以同时有多辆公交车在运行且互不影响。
 * 
 * 给你一个整数 totalTrips ，表示所有公交车 总共 需要完成的旅途数目。请你返回完成 至少 totalTrips 趟旅途需要花费的 最少
 * 时间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：time = [1,2,3], totalTrips = 5
 * 输出：3
 * 解释：
 * - 时刻 t = 1 ，每辆公交车完成的旅途数分别为 [1,0,0] 。
 * ⁠ 已完成的总旅途数为 1 + 0 + 0 = 1 。
 * - 时刻 t = 2 ，每辆公交车完成的旅途数分别为 [2,1,0] 。
 * ⁠ 已完成的总旅途数为 2 + 1 + 0 = 3 。
 * - 时刻 t = 3 ，每辆公交车完成的旅途数分别为 [3,1,1] 。
 * ⁠ 已完成的总旅途数为 3 + 1 + 1 = 5 。
 * 所以总共完成至少 5 趟旅途的最少时间为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：time = [2], totalTrips = 1
 * 输出：2
 * 解释：
 * 只有一辆公交车，它将在时刻 t = 2 完成第一趟旅途。
 * 所以完成 1 趟旅途的最少时间为 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 10^5
 * 1 <= time[i], totalTrips <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度O(n * log(min(time) * totalTrips)) 空间复杂度O(1)
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(),time.end());
        long long left = time[0];
        long long right = (long long)time[0] * totalTrips;  //若不加强转，则测试案例10000*10000000会超出int范围

        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(check(time,totalTrips,mid)){ ///mid满足条件，求最小，则右侧染红色
                right =  mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(vector<int>& time, int totalTrips,long long T){
        long long sum = 0;
        for(int i = 0; i < time.size(); i++){
            sum += T / time[i];           
        }
        return sum >= totalTrips;
    }

};
// @lc code=end

