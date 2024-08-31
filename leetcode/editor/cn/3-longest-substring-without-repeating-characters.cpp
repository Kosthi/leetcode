//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 10218 👎 0

namespace solution3 {
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            std::unordered_map<char, int> map;
            int max_len = 0;
            int l = 0, r = 0;
            while (r < s.size()) {
                if (map.count(s[r]) && map[s[r]] >= l) {
                    l = map[s[r]] + 1;
                }
                map[s[r]] = r;
                max_len = max(max_len, r - l + 1);
                ++r;
            }
            return max_len;
        }
    };

    //leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution3;

int main() {
    Solution solution = Solution();
    std::cout << solution.lengthOfLongestSubstring("abcabcbba");
    return 0;
}
