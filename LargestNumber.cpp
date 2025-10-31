#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    int compareTwoNumbers(int x, int y) {
        string sx = to_string(x);
        string sy = to_string(y);

        if (sx + sy > sy + sx) 
            return 1; 
        if (sx + sy < sy + sx) 
            return -1; 
        return 0;
    }

    void sortVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (compareTwoNumbers(nums[i], nums[j]) == -1) {
                    swap(nums, i, j);
                }
            }
        }
    }

    string largestNumber(vector<int>& nums) {
        string output = "";
        sortVector(nums);
        for (int i = 0; i < nums.size(); i++)
            output += to_string(nums[i]);
        if (!output.empty() && output[0] == '0')
            output = "0";
        return output + "\0";
    }
};

int main() {
    vector<int> nums = {0,0};
    Solution leetCode;
    cout << leetCode.largestNumber(nums) << endl;
    return 1;
}