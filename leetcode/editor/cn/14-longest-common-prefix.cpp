// import universal *.h
#include "../../../stdc.h"

using namespace std;


// 编写一个函数来查找字符串数组中的最长公共前缀。
//
//  如果不存在公共前缀，返回空字符串 ""。
//
//
//
//  示例 1：
//
//
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
//
//
//  示例 2：
//
//
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。
//
//
//
//  提示：
//
//
//  1 <= strs.length <= 200
//  0 <= strs[i].length <= 200
//  strs[i] 如果非空，则仅由小写英文字母组成
//
//
//  Related Topics 字典树 字符串 👍 3262 👎 0


namespace solution14 {
    // leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty())
                return "";
            string res = strs[0];
            int minLen = INT32_MAX;
            for (int i = 1; i < strs.size(); ++i) {
                int j = 0;
                for (; j < strs[i].length(); ++j) {
                    if (strs[i][j] != strs[0][j]) {
                        break;
                    }
                }
                if (j < minLen) {
                    minLen = j;
                }
            }
            return res.substr(0, minLen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution14;

int main() {
    Solution solution = Solution();
    return 0;
}
