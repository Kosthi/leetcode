#include "../../../stdc.h"

using namespace std;

//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2781 👎 0


namespace solution101 {
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
    bool bfs(TreeNode *root) {
        std::queue<TreeNode*> q;
        q.emplace(root);

        std::vector<int> vec;
        int level_cnt = 1;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            --level_cnt;

            if (node) {
                q.emplace(node->left ? node->left : nullptr);
                vec.emplace_back(node->left ? node->left->val : 101);
                q.emplace(node->right ? node->right : nullptr);
                vec.emplace_back(node->right ? node->right->val : 101);
            }

            if (!vec.empty() && level_cnt == 0) {
                // check
                for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
                    if (vec[i] != vec[j]) {
                        return false;
                    }
                }
                level_cnt = vec.size();
                vec.clear();
            }
        }
        return true;
    }

    bool myBfs(TreeNode *root) {
        std::queue<TreeNode*> q;
        q.emplace(root->left);
        q.emplace(root->right);

        while (!q.empty()) {
            auto n1 = q.front();
            q.pop();
            auto n2 = q.front();
            q.pop();

            if (n1 == nullptr && n2 == nullptr) continue;
            if (n1 == nullptr || n2 == nullptr || n1->val != n2->val) return false;

            q.emplace(n1->left);
            q.emplace(n2->right);
            q.emplace(n1->right);
            q.emplace(n2->left);
        }

        return true;
    }

    bool cur(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;
        return cur(left->left, right->right) && cur(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        // return root == nullptr || cur(root->left, root->right);
        return myBfs(root);
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution101;

int main() {
    Solution solution = Solution();
    auto node = stringToTreeNode("[3,4,4,5,null,null,5,6,null,null,6");
    solution.isSymmetric(node);
    return 0;
}
