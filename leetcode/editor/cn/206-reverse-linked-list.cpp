//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
// 
//
// 示例 2： 
// 
// 
//输入：head = [1,2]
//输出：[2,1]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围是 [0, 5000] 
// -5000 <= Node.val <= 5000 
// 
//
// 
//
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
//
// Related Topics 递归 链表 👍 3625 👎 0

namespace solution206 {
    //leetcode submit region begin(Prohibit modification and deletion)
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
        ListNode *reverseList(ListNode *head) {
            if (head == nullptr) {
                return nullptr;
            }

            auto *res = new ListNode();
            auto tmp = head;
            res->val = tmp->val;
            res->next = nullptr;

            while (tmp->next) {
                tmp = tmp->next;
                auto *tt = new ListNode();
                tt->val = tmp->val;
                tt->next = res;
                res = tt;
            }

            return res;
        }
    };

    //leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution206;

int main() {
    Solution solution = Solution();
    // solution.reverseList(new ListNode(2));
    return 0;
}
