#include "../../../stdc.h"

using namespace std;

// 不使用任何库函数，设计一个 跳表 。
//
//  跳表 是在 O(log(n))
//  时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思
// 想与链表相似。
//
//  例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作：
//
//
//
//  跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过
//  O(n)。跳表的每一个操作的平均时间复杂度是 O(log(
// n))，空间复杂度是 O(n)。
//
//  了解更多 : https://oi-wiki.org/ds/skiplist/
//
//  在本题中，你的设计应该要包含这些函数：
//
//
//  bool search(int target) : 返回target是否存在于跳表中。
//  void add(int num): 插入一个元素到跳表。
//  bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。
//
//
//
//  注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
//
//
//
//  示例 1:
//
//
// 输入
//["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase",
//  "search"]
//[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
// 输出
//[null, null, null, null, false, null, true, false, true, false]
//
// 解释
// Skiplist skiplist = new Skiplist();
// skiplist.add(1);
// skiplist.add(2);
// skiplist.add(3);
// skiplist.search(0);   // 返回 false
// skiplist.add(4);
// skiplist.search(1);   // 返回 true
// skiplist.erase(0);    // 返回 false，0 不在跳表中
// skiplist.erase(1);    // 返回 true
// skiplist.search(1);   // 返回 false，1 已被擦除
//
//
//
//
//  提示:
//
//
//  0 <= num, target <= 2 * 10⁴
//  调用search, add, erase操作次数不大于 5 * 10⁴
//
//
//  Related Topics 设计 链表 👍 281 👎 0


namespace solution1206 {
    // leetcode submit region begin(Prohibit modification and deletion)
    constexpr int MAX_LEVEL = 32;
    constexpr double P_FACTOR = 0.25;

    struct SkiplistNode {
        int val;
        vector<SkiplistNode *> next;
        SkiplistNode(int val_, int maxLevel_ = 32) : val(val_), next(maxLevel_, nullptr) {}
    };

    class Skiplist {
    public:
        Skiplist() : head(new SkiplistNode(-1)), level(0), dis(0, 1) {}

        void find(int target, std::vector<SkiplistNode *> &pre) {
            auto p = head;
            for (int i = level - 1; i >= 0; --i) {
                while (p->next[i] && p->next[i]->val < target) {
                    p = p->next[i];
                }
                pre[i] = p;
            }
        }

        bool search(int target) {
            std::vector<SkiplistNode *> pre(level);
            find(target, pre);
            auto cur = pre[0]->next[0];
            return cur && cur->val == target;
        }

        void add(int num) {
            std::vector<SkiplistNode *> pre(MAX_LEVEL, head);
            find(num, pre);
            int lv = randomLevel();
            level = max(level, lv);
            auto *new_node = new SkiplistNode(num, lv);
            for (int i = 0; i < lv; ++i) {
                new_node->next[i] = pre[i]->next[i];
                pre[i]->next[i] = new_node;
            }
        }

        bool erase(int num) {
            std::vector<SkiplistNode *> pre(level, nullptr);
            find(num, pre);
            auto cur = pre[0]->next[0];
            // 未找到
            if (cur == nullptr || cur->val != num) {
                return false;
            }
            // 找到并删除
            for (int i = 0; i < level && pre[i]->next[i] == cur; ++i) {
                pre[i]->next[i] = cur->next[i];
            }
            delete cur;
            while (level > 1 && head->next[level - 1] == nullptr) {
                --level;
            }
            return true;
        }

        int randomLevel() {
            int lv = 1;
            while (dis(gen) < P_FACTOR && lv < MAX_LEVEL) {
                ++lv;
            }
            return lv;
        }

    private:
        SkiplistNode *head;
        int level;
        mt19937 gen{random_device{}()};
        uniform_real_distribution<double> dis;
    };

    /**
     * Your Skiplist object will be instantiated and called as such:
     * Skiplist* obj = new Skiplist();
     * bool param_1 = obj->search(target);
     * obj->add(num);
     * bool param_3 = obj->erase(num);
     */
    //leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution1206;

int main() {
    Skiplist solution = Skiplist();
    return 0;
}
