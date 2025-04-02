# 二分算法

## 二分查找
1. 对于需要知道相同数字出现的次数和下标时，可以用
   ```
   unordered_map<int, vector<int>> pos;#key用于存储值，value用于存储下标
   ```
   由于在插入时是按照下标的顺序插入的，所以后续可以不用再对value的vector进行排序  
   **例题** :2080、3488

## 二分答案
* 对于二分答案题，最重要的就是check函数，用于判断当前答案是否满足条件，通过check函数来进行二分
* 其次，确定二分的区间也很重要，即确定left和right的取值

### 求最小值
1. 求最小：check(mid) == true 时更新 right = mid - 1，反之更新 left = mid + 1，最后返回 left。
   

### 求最大值
1. 求最大：check(mid) == true 时更新 left = mid + 1，反之更新 right = mid - 1，最后返回 left。

