/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 *
 * https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/description/
 *
 * algorithms
 * Easy (66.12%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    54.7K
 * Total Submissions: 82.8K
 * Testcase Example:  '[4,5,8]\n[10,9,1,8]\n2'
 *
 * 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
 * 
 * 「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <=
 * d 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * 输出：2
 * 解释：
 * 对于 arr1[0]=4 我们有：
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * 所以 arr1[0]=4 符合距离要求
 * 
 * 对于 arr1[1]=5 我们有：
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * 所以 arr1[1]=5 也符合距离要求
 * 
 * 对于 arr1[2]=8 我们有：
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 存在距离小于等于 2 的情况，不符合距离要求 
 * 
 * 故而只有 arr1[0]=4 和 arr1[1]=5 两个符合距离要求，距离值为 2
 * 
 * 示例 2：
 * 
 * 输入：arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 500
 * -10^3 <= arr1[i], arr2[j] <= 10^3
 * 0 <= d <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(NlogN)
    //空间复杂度O(1)
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        int n = arr2.size();
        sort(arr2.begin(),arr2.end());

        for(int i = 0; i < arr1.size(); i++){
            bool valid = true;
            int GE = lowerBound(arr2,arr1[i]);  //获取第一个大于等于arr1的值

            if (GE < n && arr2[GE] - arr1[i] <= d) {  //如果大于等于arr1的值存在且距离小于d，则不符合
                valid = false;
            }
    
            if (GE > 0 && arr1[i] - arr2[GE - 1] <= d) {    //如果GE>0，说明存在小于arr1的值，判断距离是否小于d，如果是则不符合
                valid = false;
            }

            if(valid)
                res++;
         
        }
        return res;

    }

    int lowerBound(vector<int>& arr,int target){
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};
// @lc code=end

