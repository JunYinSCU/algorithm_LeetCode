/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 *
 * https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (63.04%)
 * Likes:    647
 * Dislikes: 0
 * Total Accepted:    115.7K
 * Total Submissions: 183.5K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * 传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。
 * 
 * 传送带上的第 i 个包裹的重量为
 * weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
 * 
 * 返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * 输出：15
 * 解释：
 * 船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
 * 第 1 天：1, 2, 3, 4, 5
 * 第 2 天：6, 7
 * 第 3 天：8
 * 第 4 天：9
 * 第 5 天：10
 * 
 * 请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9),
 * (10) 是不允许的。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：weights = [3,2,2,4,1,4], days = 3
 * 输出：6
 * 解释：
 * 船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
 * 第 1 天：3, 2
 * 第 2 天：2, 4
 * 第 3 天：1, 4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：weights = [1,2,3,1,1], days = 4
 * 输出：3
 * 解释：
 * 第 1 天：1
 * 第 2 天：2
 * 第 3 天：3
 * 第 4 天：1, 1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= days <= weights.length <= 5 * 10^4
 * 1 <= weights[i] <= 500
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度O(n * log(sum(weights))) 空间复杂度O(1)
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            maxWeight = max(maxWeight,weights[i]);
            sum += weights[i];
        }

        int left = maxWeight;   //最小为当前最大重量，因为船的载重至少要能装下最重的包裹
        int right = sum;    //最大为所有包裹的重量之和，因为船的载重不能超过所有包裹的总重量

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(weights,mid,days)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return left;

    }

    bool check(vector<int>& weights, int capacity, int days) {
        int dayCount = 1; // 从第1天开始
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                // 超出当前船的载重，换天
                dayCount++;
                currentWeight = weight; // 新的一天，当前重量为当前包裹
                if (dayCount > days) {
                    return false; // 超出天数限制
                }
            } else {
                currentWeight += weight;
            }
        }
        return true;
    }
};
// @lc code=end

