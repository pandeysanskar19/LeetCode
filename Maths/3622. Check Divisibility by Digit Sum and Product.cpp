class Solution {
public:
// TIME COMPLEXITY: O(LOG N).
    bool checkDivisibility(int n) {
        int sum=0;
        int product =1;
        int temp = n;
        //Extract the digit.
        while(temp>0){
            int r = temp%10;
            sum += r;  
            product *= r;
            temp /=10; 
        }
        int total =sum+product;
        // divisible
        if(n % total == 0) return true;
        return false;
    }
};
