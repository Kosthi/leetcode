#include "../../../stdc.h"

using namespace std;

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2364 👎 0


namespace solution105 {
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
    TreeNode *build(int root, int l, int r) {
        // 通过 l r 判定是否还有元素可以加入二叉树
        if (l > r) return nullptr;
        auto node = new TreeNode(preorder[root]);
        auto idx = map_[preorder[root]];
        node->left = build(root + 1, l, idx - 1);
        // root 加上左子树的大小 + 1，才是右子树
        node->right = build(root + idx - l + 1, idx + 1, r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i) {
            map_[inorder[i]] = i;
        }
        return build(0, 0, inorder.size() - 1);
    }

private:
    vector<int> preorder;
    std::unordered_map<int, int> map_;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution105;

int main() {
    Solution solution = Solution();
    return 0;
}
