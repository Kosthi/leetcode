#include "../../../stdc.h"

using namespace std;

//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 2006 👎 0


namespace solution102 {
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
    void doOrder(TreeNode* root) {
        q.emplace(root);
        res.emplace_back(std::vector<int>{q.front()->val});

        int level_num = 1;
        std::vector<int> v;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            --level_num;
            if (cur->left) {
                q.emplace(cur->left);
                v.emplace_back(cur->left->val);
            }
            if (cur->right) {
                q.emplace(cur->right);
                v.emplace_back(cur->right->val);
            }
            if (!v.empty() && level_num == 0) {
                res.emplace_back(v);
                level_num += v.size();
                v.clear();
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        doOrder(root);
        return res;
    }

private:
    std::queue<TreeNode*> q;
    std::vector<std::vector<int>> res;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution102;

int main() {
    Solution solution = Solution();
    return 0;
}
