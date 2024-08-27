#include "../../../stdc.h"

using namespace std;

//给你二叉树的根结点 root ，请你将它展开为一个单链表： 
//
// 
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。 
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,5,3,4,null,6]
//输出：[1,null,2,null,3,null,4,null,5,null,6]
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
//输入：root = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？ 
//
// Related Topics 栈 树 深度优先搜索 链表 二叉树 👍 1721 👎 0


namespace solution114 {
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
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        vec.emplace_back(root);
        dfs(root->left);
        dfs(root->right);
    }

    void myFlatten(TreeNode* root) {
        if (root == nullptr) return;
        myFlatten(root->left);
        myFlatten(root->right);
        if (root->left) {
            auto cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }

    void flatten(TreeNode* root) {
        myFlatten(root);
        // if (root == nullptr) return;
        // dfs(root);
        // for (int i = 0; i + 1 < vec.size(); ++i) {
        //     vec[i]->left = nullptr;
        //     vec[i]->right = vec[i + 1];
        // }
        // vec[vec.size() - 1]->left = vec[vec.size() - 1]->right = nullptr;
    }

private:
    std::vector<TreeNode* > vec;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution114;

int main() {
    Solution solution = Solution();
    auto node = stringToTreeNode("[]");
    solution.flatten(node);
    return 0;
}
