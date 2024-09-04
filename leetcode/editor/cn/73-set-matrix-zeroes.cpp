#include "../../../stdc.h"

using namespace std;

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
//输出：[[1,0,1],[0,0,0],[1,0,1]]
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[0].length 
// 1 <= m, n <= 200 
// -2³¹ <= matrix[i][j] <= 2³¹ - 1 
// 
//
// 
//
// 进阶： 
//
// 
// 一个直观的解决方案是使用 O(mn) 的额外空间，但这并不是一个好的解决方案。 
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。 
// 你能想出一个仅使用常量空间的解决方案吗？ 
// 
//
// Related Topics 数组 哈希表 矩阵 👍 1097 👎 0


namespace solution73 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;

        // 检查第 0 行上是否有 0
        for (auto &num : matrix[0]) {
            if (num == 0) {
                row = true;
                break;
            }
        }
        // 检查第 0 列上是否有 0
        for (auto &num : matrix) {
            if (num[0] == 0) {
                col = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row) {
            for (auto &num : matrix[0]) {
                num = 0;
            }
        }
        if (col) {
            for (auto &num : matrix) {
                num[0] = 0;
            }
        }
        // std::vector<bool> row(matrix.size(), false);
        // std::vector<bool> col(matrix[0].size(), false);
        //
        // for (int i = 0; i < matrix.size(); ++i) {
        //     for (int j = 0; j < matrix[i].size(); ++j) {
        //         if (matrix[i][j] == 0) {
        //             row[i] = col[i] = true;
        //         }
        //     }
        // }
        //
        // for (int i = 0; i < matrix.size(); ++i) {
        //     for (int j = 0; j < matrix[i].size(); ++j) {
        //         if (row[i] || col[i]) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution73;

int main() {
    Solution solution = Solution();
    return 0;
}
