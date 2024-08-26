#include "../../../stdc.h"

using namespace std;

//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 3250 👎 0


namespace solution146 {
    //leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            auto kv = *it->second;
            list_.erase(it->second);
            list_.emplace_front(kv);
            map_[key] = list_.begin();
            return kv.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
            list_.emplace_front(key, value);
            map_[key] = list_.begin();
        } else {
            if (capacity_ == list_.size()) {
                auto key_ = list_.back().first;
                map_.erase(key_);
                list_.pop_back();
            }
            list_.emplace_front(key, value);
            map_[key] = list_.begin();
        }
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_; // key -> it
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution146;

int main() {
    LRUCache lru_cache = LRUCache(2);
    lru_cache.put(1, 1);
    lru_cache.put(2, 2);
    std::cout << lru_cache.get(1) << std::endl;
    lru_cache.put(3, 3);
    return 0;
}
