#include "two_sum.hpp"
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> idxes;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        int diff = target - num;
        if (idxes.find(diff) != idxes.end()) {
            return {i, idxes[diff]};
        }
        idxes[num] = i;
    }
    return {};
}
