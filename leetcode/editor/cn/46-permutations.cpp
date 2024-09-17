#include "../../../stdc.h"

using namespace std;

//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
//
// Related Topics 数组 回溯 👍 2960 👎 0


namespace solution46 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(int k, std::vector<int>& con) {
        if (k == nums.size()) {
            res.emplace_back(con);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!st[i]) {
                st[i] = true;
                con.emplace_back(nums[i]);
                dfs(k + 1, con);
                con.pop_back();
                st[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        st = std::vector<bool>(nums.size(), false);
        std::vector<int> con;
        dfs(0, con);
        return res;
    }

private:
    vector<int> nums;
    vector<vector<int>> res;
    vector<bool> st;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution46;

int main() {
    Solution solution = Solution();
    return 0;
}
