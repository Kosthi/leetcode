#include "../../../stdc.h"

using namespace std;

//在给定的 m x n 网格
// grid 中，每个单元格可以有以下三个值之一： 
//
// 
// 值 0 代表空单元格； 
// 值 1 代表新鲜橘子； 
// 值 2 代表腐烂的橘子。 
// 
//
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。 
//
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
//输出：-1
//解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
// 
//
// 示例 3： 
//
// 
//输入：grid = [[0,2]]
//输出：0
//解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 10 
// grid[i][j] 仅为 0、1 或 2 
// 
//
// Related Topics 广度优先搜索 数组 矩阵 👍 918 👎 0


namespace solution994 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void bfs() {
        while (!q.empty()) {
            ++ans;
            std::queue<std::pair<int, int>> tmp;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                    if (grid_[xx][yy] == 1) {
                        --fresh;
                        grid_[xx][yy] = 2;
                        tmp.emplace(xx, yy);
                    }
                }
            }
            q = std::move(tmp);
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        this->grid_ = grid;
        m = grid_.size();
        n = grid_[0].size();

        for (int i = 0; i < grid_.size(); ++i) {
            for (int j = 0; j < grid_[i].size(); ++j) {
                if (grid_[i][j] == 1) {
                    ++fresh;
                } else if (grid_[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }
        bfs();

        return fresh ? -1 : max(ans, 0);
    }

private:
    int m, n;
    int fresh = 0;
    int ans = -1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> grid_;
    std::queue<std::pair<int, int>> q;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution994;

int main() {
    Solution solution = Solution();
    return 0;
}
