#include "../../../stdc.h"

using namespace std;

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
//
// Related Topics 数组 二分查找 分治 👍 7208 👎 0


namespace solution4 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return nums2.size() % 2 ? nums2[nums2.size() / 2] : (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2;
        }
        if (nums2.empty()) {
            return nums1.size() % 2 ? nums1[nums2.size() / 2] : (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
        }
        int low = max(nums1[0], nums2[0]);
        int l = 0, r = nums1.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums1[mid] < low)
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution4;

int main() {
    Solution solution = Solution();
    return 0;
}
