//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。 
//
// 子数组是数组中元素的连续非空序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1], k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3], k = 3
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -1000 <= nums[i] <= 1000 
// -10⁷ <= k <= 10⁷ 
// 
//
// Related Topics 数组 哈希表 前缀和 👍 2405 👎 0

namespace solution560{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        std::unordered_map<int, int> map;
        // 因为在累积和为 k 的情况下，我们需要考虑到从数组开头开始的子数组。
        // 如果没有这个初始插入，那么当累积和正好等于 k 时，我们会漏掉这种情况，因为在遍历数组时，我们是从第一个元素开始计算累积和的。
        map.emplace(0, 1);
        for (auto &num : nums) {
            sum += num;
            if (map.count(sum - k)) {
                cnt += map[sum - k];
            }
            ++map[sum];
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution560;

int main() {
    Solution solution = Solution();
    auto v = std::vector<int>{6, 4, 3, 1};
    std::cout << solution.subarraySum(v, 10);
    return 0;
}
