/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 *
 * [3296] 移山所需的最少秒数
 *
 * https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/
 *
 * algorithms
 * Medium (41.08%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 16.6K
 * Testcase Example:  '4\n[2,1,1]'
 *
 * 给你一个整数 mountainHeight 表示山的高度。
 * 
 * 同时给你一个整数数组 workerTimes，表示工人们的工作时间（单位：秒）。
 * 
 * 工人们需要 同时 进行工作以 降低 山的高度。对于工人 i :
 * 
 * 
 * 山的高度降低 x，需要花费 workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x
 * 秒。例如：
 * 
 * 
 * 山的高度降低 1，需要 workerTimes[i] 秒。
 * 山的高度降低 2，需要 workerTimes[i] + workerTimes[i] * 2 秒，依此类推。
 * 
 * 
 * 
 * 
 * 返回一个整数，表示工人们使山的高度降低到 0 所需的 最少 秒数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： mountainHeight = 4, workerTimes = [2,1,1]
 * 
 * 输出： 3
 * 
 * 解释：
 * 
 * 将山的高度降低到 0 的一种方式是：
 * 
 * 
 * 工人 0 将高度降低 1，花费 workerTimes[0] = 2 秒。
 * 工人 1 将高度降低 2，花费 workerTimes[1] + workerTimes[1] * 2 = 3 秒。
 * 工人 2 将高度降低 1，花费 workerTimes[2] = 1 秒。
 * 
 * 
 * 因为工人同时工作，所需的最少时间为 max(2, 3, 1) = 3 秒。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： mountainHeight = 10, workerTimes = [3,2,2,4]
 * 
 * 输出： 12
 * 
 * 解释：
 * 
 * 
 * 工人 0 将高度降低 2，花费 workerTimes[0] + workerTimes[0] * 2 = 9 秒。
 * 工人 1 将高度降低 3，花费 workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 =
 * 12 秒。
 * 工人 2 将高度降低 3，花费 workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 =
 * 12 秒。
 * 工人 3 将高度降低 2，花费 workerTimes[3] + workerTimes[3] * 2 = 12 秒。
 * 
 * 
 * 所需的最少时间为 max(9, 12, 12, 12) = 12 秒。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入： mountainHeight = 5, workerTimes = [1]
 * 
 * 输出： 15
 * 
 * 解释：
 * 
 * 这个示例中只有一个工人，所以答案是 workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 +
 * workerTimes[0] * 4 + workerTimes[0] * 5 = 15 秒。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= mountainHeight <= 10^5
 * 1 <= workerTimes.length <= 10^4
 * 1 <= workerTimes[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        if( n == 1){
            return calcTime(mountainHeight, workerTimes[0]);
        }
        int maxWorkerTime = 0;
        for(int i = 0; i < n; i++){
            maxWorkerTime = max(maxWorkerTime, workerTimes[i]);
        }
        long long left = 1; // 最小时间，至少要 1 秒
        long long right = calcTime(mountainHeight, maxWorkerTime); // 最大时间，所有工人都用最大效率工作

        while (left <= right) {
            long long mid =(long long)(left + (right - left) / 2);
            if (check(mountainHeight, workerTimes, mid)) {
                right = mid - 1; // 可以在 mid 秒内完成，尝试更小的时间
            } else {
                left = mid + 1; // 不行，时间太短了
            }
        }
        return left; // 最终 left 和 right 会相等，返回即可
    }

    bool check(int mountainHeight, vector<int>& workerTimes, long long time) {
        // 检查在给定的时间内，是否可以将山的高度降低到 0
        int n = workerTimes.size();
        long long totalHeight = 0;

        for (int i = 0; i < n; ++i) {
            long long workerTime = workerTimes[i];
            long long x = 0;
            long long currTime = 0;

            // 计算当前工人能将山的高度降低多少
            while (true) {
                long long timeNeeded = calcTime(x + 1, workerTime);
                if (timeNeeded > time) {
                    break;
                }
                ++x;
            }
            totalHeight += x;
        }
        return totalHeight >= mountainHeight;
    }

    long long calcTime(int x, int workerTime) {
        // 计算将山的高度降低 x 所需的时间
        long long time = 0;
        for (int i = 1; i <= x; ++i) {
            time += (long long)workerTime * i;
        }
        return time;
    }
};
// @lc code=end

