#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        long long low = 0, high = nums.size() - 1;
        if (nums.size() == 0) {
            return {-1, -1};
        }
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                int start = mid, end = mid;
                while (start > 0 && nums[start - 1] == target) {
                    start--;
                }
                while (end < nums.size() - 1 && nums[end + 1] == target) {
                    end++;
                }
                return {start, end};
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main(){
    Solution solution;
    int n; 
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector <int> nums(n);
    cout << "Enter the elements of the sorted array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    vector <int> result = solution.searchRange(nums, target);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}