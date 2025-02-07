// import universal *.h
#include "../../../stdc.h"

using namespace std;


// 给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//
//
//  示例 1：
//
//
// 输入：n = 3
// 输出：[[1,2,3],[8,9,4],[7,6,5]]
//
//
//  示例 2：
//
//
// 输入：n = 1
// 输出：[[1]]
//
//
//
//
//  提示：
//
//
//  1 <= n <= 20
//
//
//  Related Topics 数组 矩阵 模拟 👍 1375 👎 0


namespace solution59 {
    // leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n, vector<int>(n, 0));
            int l = 0, r = n - 1;
            int t = 0, b = n - 1;
            int k = 1;
            while (k <= n * n) {
                // 右
                for (int i = l; i <= r; ++i) {
                    res[t][i] = k++;
                }
                ++t;
                // 下
                for (int i = t; i <= b; ++i) {
                    res[i][r] = k++;
                }
                --r;
                // 左
                for (int i = r; i >= l; --i) {
                    res[b][i] = k++;
                }
                --b;
                // 上
                for (int i = b; i >= t; --i) {
                    res[i][l] = k++;
                }
                ++l;
            }
            return res;
        }
    };
    // leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution59;

int main() {
    Solution solution = Solution();
    return 0;
}
