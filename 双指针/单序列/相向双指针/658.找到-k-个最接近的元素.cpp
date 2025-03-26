/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (48.28%)
 * Likes:    608
 * Dislikes: 0
 * Total Accepted:    117.5K
 * Total Submissions: 243.5K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 * 
 * 整数 a 比整数 b 更接近 x 需要满足：
 * 
 * 
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [1,1,2,3,4,5], k = 4, x = -1
 * 输出：[1,1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //方法一：二分查找+背向双指针
    //时间复杂度：O(logn + k)
    //空间复杂度：O(1)
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     int index = lowerBound(arr,x);
    //     int n = arr.size();
    //     vector<int> res;

    //     if (index == n) { // `x` 大于所有元素
    //         for (int i = n - k; i < n; i++) {
    //             res.push_back(arr[i]);
    //         }
    //     } else if (index == 0) { // `x` 小于所有元素
    //         for (int i = 0; i < k; i++) {
    //             res.push_back(arr[i]);
    //         }
    //     } else { // `x` 在数组中间，使用双指针选择最接近的 `k` 个元素
    //         int left = index - 1, right = index;

    //         while (k--) {
    //             if (left >= 0 && (right >= n || abs(arr[left] - x) <= abs(arr[right] - x))) {
    //                 res.push_back(arr[left--]);
    //             } else {
    //                 res.push_back(arr[right++]);
    //             }
    //         }
    //         sort(res.begin(), res.end()); // 排序
    //     }

    //     return res;
    // }

    // int lowerBound(vector<int>& arr, int x) {
    //     int left = 0;
    //     int right = arr.size() - 1;
    //     while(left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if(arr[mid] >= x){
    //             right = mid - 1;
    //         }else{
    //             left = mid + 1;
    //         }
    //     }
    //     return left;
            
    // }

    //方法二：相向双指针+逆向思维
    //时间复杂度O(k)
    //空间复杂度O(1)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<int> res;
        int left = 0, right = n - 1;

        while(right - left + 1 > k){ //保证剩余区间长度为k
            if(abs(arr[left] - x) <= abs(arr[right] - x)){ //去掉差距最大的
                right--;
            }else{
                left++;
            }
        }
        res = vector<int>(arr.begin()+left,arr.begin()+right+1); //由于原数组是排好序的，所以直接取区间即可

        return res;
    }
};
// @lc code=end

