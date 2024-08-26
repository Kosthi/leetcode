#include "../../../stdc.h"

using namespace std;

//给你一棵二叉树的根节点，返回该树的 直径 。 
//
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。 
//
// 两节点之间路径的 长度 由它们之间边数表示。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,4,5]
//输出：3
//解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 10⁴] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1585 👎 0


namespace solution543 {
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
    void getLength(TreeNode* root) {
        if (root == nullptr) return;
        length_ = 0;
        dfs(root->left, 1);
        auto left = length_;
        length_ = 0;
        dfs(root->right, 1);
        auto right = length_;
        max_length_ = max(max_length_, left + right);
    }

    void dfs(TreeNode* root, int step) {
        if (root == nullptr) return;
        dfs(root->left, step + 1);
        dfs(root->right, step + 1);
        length_ = max(length_, step);
    }

    void get(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        getLength(root);
        get(root->left);
        get(root->right);
    }

    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = depth(root->left);
        int r = depth(root->right);
        max_length_ = max(max_length_, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_length_;
    }

private:
    int length_ = 0;
    int max_length_ = 0;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution543;

int main() {
    Solution solution = Solution();
    return 0;
}
