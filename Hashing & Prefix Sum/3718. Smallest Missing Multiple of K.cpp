class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n =nums.size();
        int present =0;
        int mul=0;
        for(int i=1;i<=n+1;i++){
            mul = i*k;
            present =0;
            for(int j=0;j<n;j++){
                if(nums[j]==mul){
                    present =1;
                    break;
                }
            }
            if(present == 0) return mul;
        }
        return -1;
    }
};


class Solution2 {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_set<int> check;
        for(int x : nums){
            check.insert(x);
        }
        for(int i=1;i<=n;i++){
            int mul =i*k;
            if(check.find(mul) == check.end()){
                return mul;
            }
        }
        return -1;
    }
};
