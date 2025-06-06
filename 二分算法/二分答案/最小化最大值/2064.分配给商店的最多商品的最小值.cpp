/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 *
 * [2064] 分配给商店的最多商品的最小值
 *
 * https://leetcode.cn/problems/minimized-maximum-of-products-distributed-to-any-store/description/
 *
 * algorithms
 * Medium (51.13%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 22.8K
 * Testcase Example:  '6\n[11,6]'
 *
 * 给你一个整数 n ，表示有 n 间零售商店。总共有 m 种产品，每种产品的数目用一个下标从 0 开始的整数数组 quantities 表示，其中
 * quantities[i] 表示第 i 种商品的数目。
 * 
 * 你需要将 所有商品 分配到零售商店，并遵守这些规则：
 * 
 * 
 * 一间商店 至多 只能有 一种商品 ，但一间商店拥有的商品数目可以为 任意 件。
 * 分配后，每间商店都会被分配一定数目的商品（可能为 0 件）。用 x 表示所有商店中分配商品数目的最大值，你希望 x 越小越好。也就是说，你想 最小化
 * 分配给任意商店商品数目的 最大值 。
 * 
 * 
 * 请你返回最小的可能的 x 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 6, quantities = [11,6]
 * 输出：3
 * 解释： 一种最优方案为：
 * - 11 件种类为 0 的商品被分配到前 4 间商店，分配数目分别为：2，3，3，3 。
 * - 6 件种类为 1 的商品被分配到另外 2 间商店，分配数目分别为：3，3 。
 * 分配给所有商店的最大商品数目为 max(2, 3, 3, 3, 3, 3) = 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 7, quantities = [15,10,10]
 * 输出：5
 * 解释：一种最优方案为：
 * - 15 件种类为 0 的商品被分配到前 3 间商店，分配数目为：5，5，5 。
 * - 10 件种类为 1 的商品被分配到接下来 2 间商店，数目为：5，5 。
 * - 10 件种类为 2 的商品被分配到最后 2 间商店，数目为：5，5 。
 * 分配给所有商店的最大商品数目为 max(5, 5, 5, 5, 5, 5, 5) = 5 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 1, quantities = [100000]
 * 输出：100000
 * 解释：唯一一种最优方案为：
 * - 所有 100000 件商品 0 都分配到唯一的商店中。
 * 分配给所有商店的最大商品数目为 max(100000) = 100000 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == quantities.length
 * 1 <= m <= n <= 10^5
 * 1 <= quantities[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(mlog(max(quantities)))，m是quantities的长度
    //空间复杂度O(1)
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = 0;
        for(int i = 0;i < quantities.size();i++){
            right = max(right,quantities[i]); 
        }
        while(left <= right){
            int mid =(left + (right - left) / 2); // 二分中点
            if(check(n,quantities,mid)){ // 如果当前mid可以满足n个商店
                right = mid - 1; // 尝试更小的值
            }else{
                left = mid + 1; // 否则增大值
            }
        }
        return left; // 最终left就是最小的可能的x
    }

    bool check(int n,vector<int>& quantities,int maxNum){
        int cnt = 0;
        int m = quantities.size();
        //每个商店只能有一种商品，那么就计算每种商品能够分给多少个商店
        //需要向上去整，因为每件商品都要分配完
        for(int i = 0;i < m;i++){
            // 每种商品需要的商店数目，向上取整
            cnt += (quantities[i] - 1) / maxNum + 1; 
            if(cnt > n){ // 如果商店数目已经超过n了，直接返回false
                return false;
            }
        }
        return true; // 如果商店数目没有超过n，返回true
    }
};
// @lc code=end

