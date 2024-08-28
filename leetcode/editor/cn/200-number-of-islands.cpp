#include "../../../stdc.h"

using namespace std;

//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2561 👎 0


namespace solution200 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void bfs(int i, int j) {
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (grid_[xx][yy] == '0') continue;
                grid_[xx][yy] = '0';
                q.emplace(xx, yy);
            }
        }
    }

    void dfs(int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
            if (grid_[xx][yy] == '0') continue;
            grid_[xx][yy] = '0';
            dfs(xx, yy);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        grid_ = std::move(grid);
        m = grid_.size();
        n = grid_[0].size();
        for (int i = 0; i < grid_.size(); ++i) {
            for (int j = 0; j < grid_[i].size(); ++j) {
                if (grid_[i][j] == '1') {
                    // dfs(i, j);
                    bfs(i, j);
                    ++res;
                }
            }
        }
        return res;
    }

private:
    int res = 0;
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<char>> grid_;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution200;

int main() {
    Solution solution = Solution();
    return 0;
}
