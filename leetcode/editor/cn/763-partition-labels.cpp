#include "../../../stdc.h"

using namespace std;

//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。 
//
// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。 
//
// 返回一个表示每个字符串片段的长度的列表。 
//
// 
//示例 1：
//
// 
//输入：s = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
//
// 示例 2： 
//
// 
//输入：s = "eccbbbbdec"
//输出：[10]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 500 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 贪心 哈希表 双指针 字符串 👍 1193 👎 0


namespace solution763 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int a[26];
        for (int i = 0; i < s.size(); ++i) {
            a[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, a[s[i] - 'a']);
            if (i == end) {
                res.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution763;

int main() {
    Solution solution = Solution();
    return 0;
}
