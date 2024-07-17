//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 1465 👎 0

namespace solution438 {
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            if (s.size() < p.size()) {
                return {};
            }

            std::vector<int> res;
            std::vector<int> count(26);

            for (int i = 0; i < p.size(); ++i) {
                ++count[s[i] - 'a'];
                --count[p[i] - 'a'];
            }

            int diff = 0;
            for (int i = 0; i < 26; ++i) {
                if (count[i]) {
                    ++diff;
                }
            }

            if (diff == 0) {
                res.emplace_back(0);
            }

            for (int i = 0; i < s.size() - p.size(); ++i) {
                --count[s[i] - 'a'];
                if (count[s[i] - 'a'] == 0) {
                    --diff;
                } else if (count[s[i] - 'a'] == -1) {
                    // 只考虑在 0 附近的 diff，相同字符增减如果没有落到 0 附近，不考虑
                    ++diff;
                }

                ++count[s[i + p.size()] - 'a'];
                if (count[s[i + p.size()] - 'a'] == 0) {
                    --diff;
                } else if (count[s[i + p.size()] - 'a'] == 1) {
                    ++diff;
                }

                if (diff == 0) {
                    res.emplace_back(i + 1);
                }
            }
            return res;
        }
    };

    //leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution438;

int main() {
    Solution solution = Solution();
    solution.findAnagrams("cbaebabacd", "abc");
    return 0;
}
