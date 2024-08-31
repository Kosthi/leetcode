#include "../../../stdc.h"

using namespace std;

// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//  实现 MinStack 类:
//
//
//  MinStack() 初始化堆栈对象。
//  void push(int val) 将元素val推入堆栈。
//  void pop() 删除堆栈顶部的元素。
//  int top() 获取堆栈顶部的元素。
//  int getMin() 获取堆栈中的最小元素。
//
//
//
//
//  示例 1:
//
//
// 输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
// 输出：
//[null,null,null,null,-3,null,0,-2]
//
// 解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.
//
//
//
//
//  提示：
//
//
//  -2³¹ <= val <= 2³¹ - 1
//  pop、top 和 getMin 操作总是在 非空栈 上调用
//  push, pop, top, and getMin最多被调用 3 * 10⁴ 次
//
//
//  Related Topics 栈 设计 👍 1810 👎 0


namespace solution155 {
    // leetcode submit region begin(Prohibit modification and deletion)
    class MinStack {
    public:
        // MinStack() {
        //     min_stack_.emplace(INT32_MAX);
        // }
        //
        // void push(int val) {
        //     stack_.emplace(val);
        //     min_stack_.emplace(min(min_stack_.top(), val));
        // }
        //
        // void pop() {
        //     stack_.pop();
        //     min_stack_.pop();
        // }
        //
        // int top() {
        //     return stack_.top();
        // }
        //
        // int getMin() {
        //     return min_stack_.top();
        // }

        MinStack() = default;

        void push(int val) {
            if (stack_.empty()) {
                stack_.emplace(0);
                min_val_ = val;
            } else {
                long long diff = val - min_val_;
                stack_.emplace(diff);
                min_val_ = diff < 0 ? val : min_val_;
            }
        }

        void pop() {
            long long diff = stack_.top();
            stack_.pop();
            if (diff < 0) {
                min_val_ = min_val_ - diff;
            }
        }

        int top() {
            // min_val 不发生更新才能直接 min_val_ + stack_.top()
            return stack_.top() < 0 ? min_val_ : min_val_ + stack_.top();
        }

        int getMin() { return min_val_; }

    private:
        // 存差值
        std::stack<long long> stack_;
        // std::stack<int> min_stack_;
        long long min_val_;
    };

    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->getMin();
   */
    //leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution155;

int main() {
    MinStack solution = MinStack();
    return 0;
}
