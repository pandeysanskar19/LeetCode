//T(n) : o(n) S(n) :O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int len = 1;
        int inc =1,dec =1;
        for(int i =1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec = 1;
            }
            else if (nums[i]<nums[i-1]){
                dec++;
                inc =1;
            }
            else{
                 inc = 1;
                 dec =1;
            }
            len = max({len,inc,dec});
        }
       return len ;
    }
};
