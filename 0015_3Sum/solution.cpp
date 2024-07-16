#include <vector>
#include <iostream>

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;

    for (int i = 0; i < nums.size() - 2; i++) {
        // skip all duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int j = i + 1;
        int k = nums.size() - 1;

        // solve two-sum problem for given target
        while (j < k) {
            int sum = nums[j] + nums[k];

            if (sum == target) {
                triplets.push_back({nums[i], nums[j], nums[k]});

                // skip all duplicates
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++;
                k--;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }
    return triplets;
}
