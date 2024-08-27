#include "../../../stdc.h"

using namespace std;

//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2: 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3: 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1107 👎 0


namespace solution199 {
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root) {
        if (root == nullptr) return;
        q.emplace(root);
        int level_cnt = 1;
        int incr = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            --level_cnt;
            if (p->left) {
                ++incr;
                q.emplace(p->left);
            }
            if (p->right) {
                ++incr;
                q.emplace(p->right);
            }
            if (level_cnt == 0) {
                vec.emplace_back(p->val);
                level_cnt = incr;
                incr = 0;
            }
        }
    }

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (vec.size() == depth) {
            vec.emplace_back(root->val);
        }
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return vec;
    }

private:
    std::vector<int> vec;
    std::queue<TreeNode *> q;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution199;

int main() {
    Solution solution = Solution();
    return 0;
}
