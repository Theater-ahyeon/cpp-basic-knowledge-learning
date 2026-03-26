#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 计算给定高度数组能容纳的最大水量
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1,max_area=0;
        while(low<high){
            int area=min(height[low],height[high])*(high-low);
            if(height[low]<height[high]){
                low++;
            }else{
                high--;
            }
            max_area=max(max_area,area);
        }
        return max_area;
         
    }
};



