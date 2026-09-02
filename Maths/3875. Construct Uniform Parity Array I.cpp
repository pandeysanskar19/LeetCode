class Solution {
public:
    bool uniformArray(vector<int>& nums1){ 
        int n=nums1.size();
        bool hasodd = false;
        // chech if there is atleast anyone odd number.
        for(int i=0;i<n;i++){
            if(nums1[i] % 2==0){
            hasodd = true;
            break;
            }
        }
        // odd numbers keep them 
        // even numbers = even - odd = odd;
        if(hasodd == true){
            return true;
        }
        return true;
    }
};
