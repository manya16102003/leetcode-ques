class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
          int j = 0; // Initialize a pointer to track the position for even integers

    // Iterate through the vector
    for (int i = 0; i < nums.size(); i++) {
        // If the current element is even, swap it with the element at index j
        if (nums[i] % 2 == 0) {
            std::swap(nums[i], nums[j]);
            j++; // Increment the pointer to the next position for even integers
        }
    }

    // The vector is now rearranged with even integers at the beginning and odd integers at the end
    return nums;
    }
};