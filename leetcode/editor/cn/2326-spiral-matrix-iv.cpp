// import universal *.h
#include "../../../stdc.h"

using namespace std;


// 给你两个整数：m 和 n ，表示矩阵的维数。
//
//  另给你一个整数链表的头节点 head 。
//
//  请你生成一个大小为 m x n 的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 左上角 开始、顺时针 按 螺旋
//  顺序填充。如果还存在剩余的空格，
// 则用 -1 填充。
//
//  返回生成的矩阵。
//
//
//
//  示例 1：
//  输入：m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// 输出：[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// 解释：上图展示了链表中的整数在矩阵中是如何排布的。
// 注意，矩阵中剩下的空格用 -1 填充。
//
//
//  示例 2：
//  输入：m = 1, n = 4, head = [0,1,2]
// 输出：[[0,1,2,-1]]
// 解释：上图展示了链表中的整数在矩阵中是如何从左到右排布的。
// 注意，矩阵中剩下的空格用 -1 填充。
//
//
//
//  提示：
//
//
//  1 <= m, n <= 10⁵
//  1 <= m * n <= 10⁵
//  链表中节点数目在范围 [1, m * n] 内
//  0 <= Node.val <= 1000
//
//
//  Related Topics 数组 链表 矩阵 模拟 👍 34 👎 0


namespace solution2326 {
    // leetcode submit region begin(Prohibit modification and deletion)
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
    class Solution {
    public:
        vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
            std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));
            auto cur = head;
            int l = 0, r = n - 1, t = 0, b = m - 1;
            while (cur != nullptr) {
                for (int i = l; cur && i <= r; ++i) {
                    res[t][i] = cur->val;
                    cur = cur->next;
                }
                ++t;
                for (int i = t; cur && i <= b; ++i) {
                    res[i][r] = cur->val;
                    cur = cur->next;
                }
                --r;
                for (int i = r; cur && i >= l; --i) {
                    res[b][i] = cur->val;
                    cur = cur->next;
                }
                --b;
                for (int i = b; cur && i >= t; --i) {
                    res[i][l] = cur->val;
                    cur = cur->next;
                }
                ++l;
            }
            return res;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution2326;

int main() {
    Solution solution = Solution();
    return 0;
}
