#include "../../../stdc.h"

using namespace std;

//给你一个满足下述两条属性的 m x n 整数矩阵： 
//
// 
// 每行中的整数从左到右按非严格递增顺序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -10⁴ <= matrix[i][j], target <= 10⁴ 
// 
//
// Related Topics 数组 二分查找 矩阵 👍 961 👎 0


namespace solution74 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int get_num(int idx) {
        int r = idx / n;
        int c = idx % n;
        return matrix[r][c];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // std::vector<int> flat;
        // for (auto &r : matrix) {
        //     for (auto &c : r) {
        //         flat.emplace_back(c);
        //     }
        // }

        this->matrix = matrix;

        m = matrix.size();
        n = matrix[0].size();

        int l = 0, r = m * n - 1;

        while (l < r) {
            int mid = l + r >> 1;
            if (get_num(mid) >= target) r = mid;
            else l = mid + 1;
        }

        return get_num(l) == target;
    }
private:
    int m, n;
    vector<vector<int>> matrix;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution74;

int main() {
    Solution solution = Solution();
    return 0;
}
