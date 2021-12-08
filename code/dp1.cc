#include <iostream>
#include <vector>

class Solution {
public:
    int rob_easy(std::vector<int>& nums, bool& use_first, int start, int end) {
        if (end == start) {
            use_first = true;
            return nums[start];
        } else if (end == start + 1) {
            if (nums[start] > nums[end]) {
                use_first = true;
            } else {
                use_first = false;
            }
            return std::max(nums[start], nums[end]);
        } else if (end < start) {
            return 0;
        }

        // 3个或3个以上
        // 第一个选了
        // 第一个没有选
        // std::vector<int> tmp(nums.begin(), nums.end()-1);
        // std::vector<int> tmp1(nums.begin(), nums.end()-2);

        // std::cout << tmp.size() << " " << tmp1.size() << std::endl;
        // for (auto i : tmp1) {
        //     // std::cout << i;
        // }
        // std::cout << std::endl;

        bool tmp_flag = false;
        int tmp_rtn = 0;
        // std::cout << "cal k1 " << std::endl;
        int k1 = rob_easy(nums, tmp_flag, start, end - 1);
        // std::cout << "cal k2 " << std::endl;
        int k2 = rob_easy(nums, tmp_flag, start, end - 2)  + nums[end];

        if (k1 > k2) {
            // std::cout << "use k1" << std::endl;
            use_first = tmp_flag;
            return k1;
        } else {
            // std::cout << "use k2 "  << k2 << std::endl;

            use_first = tmp_flag;
            return k2;   
        }
        return -99; 
    }

    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        } else if (nums.size() == 3) {
            return std::max(std::max(nums[0], nums[1]), nums[2]);

        }
        bool tmp_flag = false;
        int tmp_rtn = 0;
        int k1 = rob_easy(nums, tmp_flag, 0, nums.size()-2);
        int k2 = rob_easy(nums, tmp_flag,  1, nums.size()-3)  + nums.back();

        if (k1 > k2) {
            // std::cout << "use k1" << std::endl;
            return k1;
        } else {
            // std::cout << "use k2 "  << k2 << std::endl;
            return k2;   
        }
        return -99;
    }
};

int main() {
    std::vector<int> input = {104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
    Solution s;
    std::cout << s.rob(input);
    return 1;
}