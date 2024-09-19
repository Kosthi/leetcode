#include "../../../stdc.h"

using namespace std;

//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 3681 👎 0


namespace solution22 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(std::string s, int l, int r) {
        if (l == 0 && r == 0) {
            res.emplace_back(s);
            return;
        }
        if (l > 0) {
            dfs(s + '(', l - 1, r + 1);
        }
        // 搜索过程中动态判断是否已经满足（）匹配，前面的如果都满足了，则不用搜索，直接回溯。
        if (r > 0) {
            dfs(s + ')', l, r - 1);
        }
        // if (l == r) {
        //     dfs(s + '(', l - 1, r);
        // } else {
        //     if (l > 0) {
        //         dfs(s + '(', l - 1, r);
        //     }
        //     dfs(s + ')', l, r - 1);
        // }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, n, 0);
        return res;
    }

private:
    std::vector<std::string> res;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution22;

int main() {
    Solution solution = Solution();
    return 0;
}
