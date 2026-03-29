#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 计算给定高度数组能容纳的最大水量
    int maxArea(vector<int>& height) {
        int low = 0, high = (int)height.size() - 1, max_area = 0;
        while (low < high) {
            int area = min(height[low], height[high]) * (high - low);
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
            max_area = max(max_area, area);
        }
        return max_area;
    }
};

// 方便你在 VSCode 点“运行当前 cpp 文件”时能直接看到结果。
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << "maxArea = " << s.maxArea(height) << '\n';
    return 0;
}
