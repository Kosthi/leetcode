//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回 滑动窗口中的最大值 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2818 👎 0

namespace solution239{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        // 存下标
        std::deque<int> q;

        // std::priority_queue<std::pair<int, int>> q;

        for (int i = 0; i < k; ++i) {
            // q.emplace(nums[i], i);
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }

        res.emplace_back(nums[q.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            res.emplace_back(nums[q.front()]);

            // q.emplace(nums[i], i);
            // while (q.top().second <= i - k) {
            //     q.pop();
            // }
            // res.emplace_back(q.top().first);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution239;

int main() {
    Solution solution = Solution();
    return 0;
}
