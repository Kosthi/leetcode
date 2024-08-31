#include "../../../stdc.h"

using namespace std;

//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 2129 👎 0


namespace solution94 {
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
    void doTraversal(TreeNode* root) {
        if (root->left) {
            inorderTraversal(root->left);
        }
        vec.emplace_back(root->val);
        if (root->right) {
            inorderTraversal(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        doTraversal(root);
        return vec;
    }

private:
    std::vector<int> vec;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution94;

int main() {
    Solution solution = Solution();
    return 0;
}
