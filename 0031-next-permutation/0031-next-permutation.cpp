class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //stl function gor next permutation
        //next permutation is next badha number kya hoga that comprise of same number as nums
        // next_permutation(nums.begin() , nums.end());
        //we will traverse from right side to find the number which is smaller than it's next number 
        //once the number is found swap it with number with just grater than it as we need just grater perutation

        int n=nums.size();
        int number_to_be_swapped=-1;
        // Find the first number from the right which is smaller than its next number
        for(int i=n-1; i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                number_to_be_swapped=i-1;
                break;
            }
        }
        if(number_to_be_swapped!=-1)
        {
            // Find the smallest number on the right side of 'number_to_be_swapped'
            // which is larger than nums[number_to_be_swapped] and swap them
            for(int j=n-1;j>number_to_be_swapped;j--)
            {
                if(nums[j]>nums[number_to_be_swapped])
                {
                    swap(nums[j] , nums[number_to_be_swapped]);
                    break;
                }
            }
        }
        // Reverse the numbers after the 'number_to_be_swapped' index
        reverse(nums.begin()+number_to_be_swapped+1, nums.end());
        
        
        
    }
};