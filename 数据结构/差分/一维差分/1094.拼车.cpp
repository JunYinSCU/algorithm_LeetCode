/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 *
 * https://leetcode.cn/problems/car-pooling/description/
 *
 * algorithms
 * Medium (53.39%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    120.5K
 * Total Submissions: 225.6K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * 车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
 * 
 * 给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i
 * 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
 * 
 * 当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：trips = [[2,1,5],[3,3,7]], capacity = 4
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：trips = [[2,1,5],[3,3,7]], capacity = 5
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengersi <= 100
 * 0 <= fromi < toi <= 1000
 * 1 <= capacity <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> d(10001,0);
        //隐式差分，直接在差分数组上进行操作
        for(int i = 0; i < trips.size(); i++){
            d[trips[i][1]] += trips[i][0];
            d[trips[i][2]] -= trips[i][0];
        }

        int sum = 0;
        for(int i = 0; i < d.size(); i++){
            sum += d[i];    //统计前缀和，得到当前时刻的乘客数量
            if(sum > capacity) return false;
        }

        return true;
    }
};
// @lc code=end

