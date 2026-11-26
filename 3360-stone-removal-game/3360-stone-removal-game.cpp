class Solution {
public:
    bool canAliceWin(int n) {
        bool isalice = true;
        int alice = 10;
        
        while(n >= alice){
            n = n-alice;
            isalice = !isalice ;
            alice--;
        }
        return !isalice;
    }
};