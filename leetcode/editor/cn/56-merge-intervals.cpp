#include "../../../stdc.h"

using namespace std;

//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
//
// Related Topics 数组 排序 👍 2410 👎 0


namespace solution56 {
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if (intervals.empty()) {
        //     return {};
        // }
        std::sort(intervals.begin(), intervals.end(), [&](const vector<int> &lval, const vector<int> &rval) {
            return lval[0] < rval[0];
        });
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto &lval = res.back();
            auto &rval = intervals[i];
            if (lval[0] <= rval[1] && lval[1] >= rval[0]) {
                res.back()[0] = min(lval[0], rval[0]);
                res.back()[1] = max(lval[1], rval[1]);
            } else {
                res.emplace_back(intervals[i]);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution56;

int main() {
    Solution solution = Solution();
    return 0;
}
