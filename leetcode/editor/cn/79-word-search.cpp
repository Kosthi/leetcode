#include "../../../stdc.h"

using namespace std;

// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//  单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//
//
//  示例 1：
//
//
// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"ABCCED"
// 输出：true
//
//
//  示例 2：
//
//
// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"SEE"
// 输出：true
//
//
//  示例 3：
//
//
// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"ABCB"
// 输出：false
//
//
//
//
//  提示：
//
//
//  m == board.length
//  n = board[i].length
//  1 <= m, n <= 6
//  1 <= word.length <= 15
//  board 和 word 仅由大小写英文字母组成
//
//
//
//
//  进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
//
//  Related Topics 数组 字符串 回溯 矩阵 👍 1876 👎 0


namespace solution79 {
    // leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        // 这题用不了广搜，因为可能要走重复的字符，同一层的节点，之后还要走，不能直接标记走过了，但是不标记又会走回去。
        // 所以直接深搜，在某种特定情况一直搜下去。
        // bool bfs(int i, int j) {
        // st = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
        // std::queue<std::pair<int, int>> q;
        // q.emplace(i, j);
        // st[i][j] = true;
        // int idx = 1, level_cnt = 1, ru = 0;
        // while (!q.empty()) {
        //     auto [x, y] = q.front();
        //     q.pop();
        //     for (int k = 0; k < 4; ++k) {
        //         int xx = x + dx[k];
        //         int yy = y + dy[k];
        //         if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
        //         // 注意走过的要标记，不能走回去了。。。
        //         if (st[xx][yy]) continue;
        //         if (board[xx][yy] == word[idx]) {
        //             st[xx][yy] = true;
        //             q.emplace(xx, yy);
        //             ++ru;
        //         }
        //     }
        //     if (--level_cnt == 0) {
        //         ++idx;
        //         level_cnt = ru;
        //         ru = 0;
        //     }
        // }
        // std::cout << "idx: " << idx << std::endl;
        // return idx == word.size() + 1;
        // }

        void dfs(vector<vector<char>> &board, string &word, int x, int y, int idx) {
            if (idx == word.size()) {
                is_find = true;
                return;
            }

            for (int k = 0; k < 4 && !is_find; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                    continue;
                // 注意走过的要标记，不能走回去了。。。
                if (st[xx][yy])
                    continue;
                if (board[xx][yy] == word[idx]) {
                    st[xx][yy] = true;
                    if (idx == word.size() - 1) {
                        st[xx][yy] = false;
                        is_find = true;
                        return;
                    }
                    dfs(board, word, xx, yy, idx + 1);
                    st[xx][yy] = false;
                }
            }
        }

        bool exist(vector<vector<char>> &board, string word) {
            m = board.size();
            n = board[0].size();
            int map[59] = {};
            for (auto &b: board) {
                for (auto &c: b) {
                    ++map[c - 'A'];
                }
            }
            for (auto &w: word) {
                --map[w - 'A'];
                if (map[w - 'A'] < 0) {
                    return false;
                }
            }

            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == word[0]) {
                        st[i][j] = true;
                        dfs(board, word, i, j, 1);
                        if (is_find) {
                            return true;
                        }
                        st[i][j] = false;
                    }
                }
            }
            return false;
        }

private:
    int m, n;
    bool is_find = false;
    bool st[6][6] = {};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution79;

int main() {
    Solution solution = Solution();
    return 0;
}
