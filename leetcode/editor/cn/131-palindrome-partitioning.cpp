#include "../../../stdc.h"

using namespace std;

// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
//
//
//  示例 1：
//
//
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
//
//
//  示例 2：
//
//
// 输入：s = "a"
// 输出：[["a"]]
//
//
//
//
//  提示：
//
//
//  1 <= s.length <= 16
//  s 仅由小写英文字母组成
//
//
//  Related Topics 字符串 动态规划 回溯 👍 1853 👎 0


namespace solution131 {
    // leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        bool check(string &s, int i, int j) {
            while (i < j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }
            return true;
        }

        void dfs(string &s, std::vector<string> &path, int start, int i) {
            if (i == s.size()) {
                res.emplace_back(path);
                return;
            }
            // 不选
            // 最后一个字符一定要选，如果能构成回文串，加入结果，否则回溯
            if (i < s.size() - 1) {
                dfs(s, path, start, i + 1);
            }
            // 选但是前提满足回文
            if (check(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                dfs(s, path, i + 1, i + 1);
                path.pop_back();
            }
        }

        vector<vector<string>> partition(string s) {
            std::vector<string> path;
            dfs(s, path, 0, 0);
        return res;
    }

private:
    vector<vector<string>> res;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution131;

int main() {
    Solution solution = Solution();
    return 0;
}
