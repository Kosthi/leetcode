#include "../../../stdc.h"

using namespace std;

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2899 👎 0


namespace solution17 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(int k, std::string& s) {
        if (k == vec.size()) {
            res.emplace_back(s);
            return;
        }
        for (int i = 0; i < vec[k].size(); ++i) {
            s.push_back(vec[k][i]);
            dfs(k + 1, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string &digits) {
        if (digits.empty()) {
            return {};
        }
        std::unordered_map<char, std::vector<char>> map {
                {'2', std::vector<char>{'a', 'b', 'c'}},
                {'3', std::vector<char>{'d', 'e', 'f'}},
                {'4', std::vector<char>{'g', 'h', 'i'}},
                {'5', std::vector<char>{'j', 'k', 'l'}},
                {'6', std::vector<char>{'m', 'n', 'o'}},
                {'7', std::vector<char>{'p', 'q', 'r', 's'}},
                {'8', std::vector<char>{'t', 'u', 'v'}},
                {'9', std::vector<char>{'w', 'x', 'y', 'z'}},
            };
        for (auto &d : digits) {
            vec.emplace_back(map[d]);
        }
        std::string s;
        dfs(0, s);
        return res;
    }

private:
    std::vector<std::vector<char>> vec;
    std::vector<string> res;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution17;

int main() {
    Solution solution = Solution();
    return 0;
}
