#include "../../../stdc.h"

using namespace std;

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 
//
// 示例 2: 
//
// 
//输入: numRows = 1
//输出: [[1]]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= numRows <= 30 
// 
//
// Related Topics 数组 动态规划 👍 1185 👎 0


namespace solution118 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.reserve(numRows);
        for (int i = 1; i <= numRows; ++i) {
            std::vector<int> v(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                v[j] = res.back()[j] + res.back()[j - 1];
            }
            v[i - 1] = 1;
            res.emplace_back(v);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution118;

int main() {
    Solution solution = Solution();
    return 0;
}
