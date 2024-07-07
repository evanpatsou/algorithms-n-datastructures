class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> comp;
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (comp.find(complement) != comp.end()) {
                return std::vector<int> {comp[complement], i};
            }
            comp[nums[i]] = i;
        }
        return {};
    }
};