#include "../../../stdc.h"

using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 每个右括号都有一个对应的相同类型的左括号。 
// 
//
// 
//
// 示例 1： 
//
// 
// 输入：s = "()" 
// 
//
// 输出：true 
//
// 示例 2： 
//
// 
// 输入：s = "()[]{}" 
// 
//
// 输出：true 
//
// 示例 3： 
//
// 
// 输入：s = "(]" 
// 
//
// 输出：false 
//
// 示例 4： 
//
// 
// 输入：s = "([])" 
// 
//
// 输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由括号 '()[]{}' 组成 
// 
//
// Related Topics 栈 字符串 👍 4521 👎 0


namespace solution20 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (auto &c : s) {
            if (c == '(') {
                stack.emplace(')');
            } else if (c == '{') {
                stack.emplace('}');
            } else if (c == '[') {
                stack.emplace(']');
            } else if (stack.empty() || c != stack.top()) {
                return false;
            } else {
                stack.pop();
            }
        }
        return stack.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution20;

int main() {
    Solution solution = Solution();
    return 0;
}
