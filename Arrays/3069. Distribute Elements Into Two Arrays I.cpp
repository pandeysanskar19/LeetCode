class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2; // vector to store conditional element   
        int n=nums.size();
        arr1.reserve(n);
        arr2.reserve(n);
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            // compare the last element of arr1 and arr2.
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        // insert arr2 element to arr1 to change it to result array.
        for(int y:arr2){
            arr1.push_back(y);
        }
    return arr1;

    }
};
