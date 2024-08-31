//import universal *.h
#include "../../../stdc.h"

using namespace std;

//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 5221 👎 0

namespace solution42{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        typedef long long LL;
        // 左侧
        LL lh = 0;// 最大值
        LL h1 = 0;// 总面积

        // 右侧
        LL rh = 0;// 最大值
        LL h2 = 0;// 总面积
        // 围墙面积
        int stoneArea = 0;
        for (int i = 0; i < height.size(); i++) {
            lh = lh > height[i] ? lh : height[i];
            h1 += lh;
            stoneArea += height[i];
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            rh = rh > height[i] ? rh : height[i];
            h2 += rh;
        }
        // 雨水面积=h1+h2-整体面积-围墙面积
        return h1 + h2 - lh * height.size() - stoneArea;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution42;

int main() {
    Solution solution = Solution();
    return 0;
}
