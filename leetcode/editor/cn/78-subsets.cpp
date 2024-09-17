#include "../../../stdc.h"

using namespace std;

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
//
// Related Topics 位运算 数组 回溯 👍 2357 👎 0


namespace solution78 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(int k, std::vector<int> &con) {
        if (k == nums.size()) {
            res.emplace_back(con);
            return;
        }
        con.emplace_back(nums[k]);
        dfs(k + 1, con);
        con.pop_back();
        dfs(k + 1, con);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        std::vector<int> con;
        dfs(0, con);
        return res;
    }

private:
    vector<int> nums;
    vector<vector<int>> res;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution78;

int main() {
    Solution solution = Solution();
    return 0;
}
