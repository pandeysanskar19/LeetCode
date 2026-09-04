/*class Solution {
public:
// TIME COMPLEXITY : O(N^2) , SPACE COMPLEXITY : O(1).
    int findmax(vector<int>& arr ,int low,int high){
        int max_el = arr[low];
        for(int i =low;i<=high;i++){
            if(max_el < arr[i]){
                max_el = arr[i];
            }
        }
        return max_el;
    }
    int findmin(vector<int>& arr, int low , int high){
        int min_el = arr[low];
        for(int i=low;i<= high;i++){
            if(min_el > arr[i]){
                min_el = arr[i];
            }
        }
        return min_el;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int low =0, high=n-1;
        int small =INT_MAX;
        for(int i=0;i<n;i++){
            int mx =findmax(nums,low,i);
            int mn =findmin(nums,i,high);
            if(mx-mn<=k){
                small = min(i,small);
            }
        }
        if(small == INT_MAX) return -1;
        return small;
    }
};
*/
class Solution {
public:
// TIME COMPLEXITY: O(N), SPACE COMPLEXITY:O(N).
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int> prefixmax(n);
       vector<int> suffixmin(n);
       // PREFIX LIST.
       prefixmax[0] = nums[0];
       for(int i=1;i<n;i++){
           prefixmax[i] = max(prefixmax[i-1],nums[i]);
       }
       // SUFFIX LIST.
       suffixmin[n-1] = nums[n-1];
       for(int i=n-2;i>=0;i--){
          suffixmin[i] =min(suffixmin[i+1],nums[i]);
       }
       // FIND THE SMALLEST STABLE INDEX.
       for(int i=0;i<n;i++){
          if(prefixmax[i] - suffixmin[i]<=k){
            return i;
          }
       }
       return -1;
    }
};
