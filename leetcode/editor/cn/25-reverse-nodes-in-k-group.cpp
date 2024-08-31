#include "../../../stdc.h"

using namespace std;

//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
//
// Related Topics 递归 链表 👍 2381 👎 0


namespace solution25 {
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
    bool check_k(int k, ListNode* head) {
        for (int i = 0; i < k; ++i) {
            if (head == nullptr) {
                return false;
            }
            head = head->next;
        }
        return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!check_k(k, head)) {
            return head;
        }

        auto cur = head;
        std::stack<ListNode*> stack;
        for (int i = 0; i < k; ++i) {
            stack.push(cur);
            cur = cur->next;
        }

        auto new_head = stack.top();
        while (!stack.empty()) {
            auto node1 = stack.top();
            stack.pop();
            if (!stack.empty()) {
                auto node2 = stack.top();
                node1->next = node2;
            }
        }
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution25;

int main() {
    Solution solution = Solution();
    return 0;
}
