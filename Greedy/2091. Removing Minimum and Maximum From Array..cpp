class Solution {
public:

// TIME COMPLEXITY : O(N), SPACE COMPLEXITY : O(1).
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int max_el = INT_MIN;
        int min_el = INT_MAX;
        int maxfront =1;int minfront =1;
        int maxback =1;int minback =1;
        // max element and min element.
        for(int x : nums){
            max_el = max(x,max_el);
            min_el = min(x,min_el);
        }
        // find max element from front.
        for(int i=0;i<n;i++){
            if(nums[i]==max_el){
                break;
            }
            maxfront++;
        }
        // find min element from front.
        for(int i=0;i<n;i++){
            if(nums[i]==min_el){
               break;
            }
            minfront++;
        }
        // find max element from back.
        for(int i=n-1;i>=0;i--){
            if(nums[i] == max_el) {
                break;
            }
            maxback++;
        }
        // find min element from back
        for(int i=n-1;i>=0;i--){
            if(nums[i] == min_el) {
                break;
            }
            minback++;
        }
        
        int bothfront = max(maxfront,minfront);
        int bothback = max(maxback,minback);
        int maxfrontminback = maxfront +minback;
        int minfrontmaxback = minfront + maxback;

        return min({bothfront,bothback,maxfrontminback,minfrontmaxback});

    }
};
