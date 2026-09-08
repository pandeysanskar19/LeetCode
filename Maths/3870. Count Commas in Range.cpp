class Solution {
public:
// TIME COMPLEXITY : O(LOGN) , SPACE COMPLEXITY :O(1).
    int countCommas(int n) {
        long long ans = 0;
        // when  we get 10^3, 10^6 ...  , we add commad
        for(long long threshold = 1000 ; threshold <= n ; threshold *=1000){
            ans +=(n - threshold +1);
        }
        return (int) ans;
    }
};
