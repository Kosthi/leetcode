#include "../../../stdc.h"

using namespace std;

//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,1,4,null,2], k = 1
//输出：1
// 
//
// 示例 2： 
// 
// 
//输入：root = [5,3,6,2,4,null,null,1], k = 3
//输出：3
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数为 n 。 
// 1 <= k <= n <= 10⁴ 
// 0 <= Node.val <= 10⁴ 
// 
//
// 
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？ 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 893 👎 0


namespace solution230 {
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
    void dfs(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }
        if (q.size() == k) {
            if (q.top() > root->val) {
                q.pop();
                q.emplace(root->val);
            }
        } else {
            q.emplace(root->val);
        }
        dfs(root->left, k);
        dfs(root->right, k);
    }

    void midDfs(TreeNode* root) {
        if (root == nullptr || k == 0) return;
        midDfs(root->left);
        if (--k == 0) {
            res = root->val;
            return;
        }
        midDfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        // dfs(root, k);
        // return q.top();
        this->k = k;
        midDfs(root);
        return res;
    }

private:
    int res = -1;
    int k = -1;
    std::priority_queue<int> q;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution230;

int main() {
    Solution solution = Solution();
    return 0;
}
