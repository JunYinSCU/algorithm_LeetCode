/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode.cn/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (54.67%)
 * Likes:    2715
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 
 * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 * 
 * 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m
 * 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 * 解释：需要合并 [1,2,3] 和 [2,5,6] 。
 * 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出：[1]
 * 解释：需要合并 [1] 和 [] 。
 * 合并结果是 [1] 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
 * 输出：[1]
 * 解释：需要合并的数组是 [] 和 [1] 。
 * 合并结果是 [1] 。
 * 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[j] <= 10^9
 * 
 * 
 * 
 * 
 * 进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度O(m+n)
    //空间复杂度O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i = m-1,j = n-1;
        if(m == 0){ //如果m为零，那么nums2就是我们要返回的数组
            nums1 = nums2;
            return;
        }
        if(n == 0){//如果n为零，直接返回nums1
            return;
        }
        //从后往前判断，选取最大的放在末尾
        while(i >= 0 && j >= 0 && k >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k] = nums2[j];
                k--;
                j--;
            }else{
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        //结束后，如果nums2先结束,此时j=-1，那么剩下的自然在nums1中，无需处理
        //如果nums1先结束，此时i=-1，那么剩下的元素应该在nums2中，替换到nums1
        while(k >= 0 && j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
    }
};
// @lc code=end

