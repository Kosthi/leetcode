#include "../../../stdc.h"

using namespace std;

//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。 
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,1000] 
// 
// -10⁹ <= Node.val <= 10⁹ 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1904 👎 0


namespace solution437 {
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
    void dfs(TreeNode* root, long long sum) {
        if (root == nullptr) return;
        sum += root->val;
        if (map_.count(sum - targetSum_)) {
            cnt += map_[sum - targetSum_];
        }
        ++map_[sum];
        dfs(root->left, sum);
        dfs(root->right, sum);
        --map_[sum];
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        sum += root->val;
        if (map_.count(sum - targetSum_)) {
            cnt += map_[sum - targetSum_];
        }
        ++map_[sum];
        dfs(root->left, sum);
        dfs(root->right, sum);
        --map_[sum];
        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        map_[0] = 1;
        this->targetSum_ = targetSum;
        dfs(root);
        return cnt;
    }

private:
    long long sum = 0;
    long long cnt = 0;
    long long targetSum_ = 0;
    std::unordered_map<long long, long long> map_;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution437;

int main() {
    Solution solution = Solution();
    return 0;
}
