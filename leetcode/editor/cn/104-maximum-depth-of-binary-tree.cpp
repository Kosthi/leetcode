#include "../../../stdc.h"

using namespace std;

//给定一个二叉树 root ，返回其最大深度。 
//
// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：root = [1,null,2]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数量在 [0, 10⁴] 区间内。 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1862 👎 0


namespace solution104 {
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
    void dfs(TreeNode* root, int step) {
        if (root->left) {
            dfs(root->left, step + 1);
        }
        if (root->right) {
            dfs(root->right, step + 1);
        }
        max_depth_ = max(max_depth_, step);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, 1);
        return max_depth_;
    }

private:
    int max_depth_ = 0;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution104;

int main() {
    Solution solution = Solution();
    return 0;
}
