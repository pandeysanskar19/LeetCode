/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
// TIME COMPLEXITY :O(N) ,SPACE COMPLEXITY: O(1).
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans ={-1,-1};

        if(head ==NULL|| head->next == NULL || head->next->next == NULL){
            return ans;
        }
        ListNode * prev = head;
        ListNode * temp = head->next;

        int index =1;
        int firstcritical =-1;
        int prevcritical = -1;
        int min_distance = INT_MAX;
        
        while(temp->next != NULL){
            if((temp->val > prev->val && temp->val > temp->next->val)||
            (temp->val < prev->val && temp->val <temp->next->val)){
                if(firstcritical == -1){
                    firstcritical = index;
                }
                else{
                    min_distance = min(min_distance , index -prevcritical);
                }
                prevcritical =index;
            }
            prev = temp;
            temp = temp->next;
            index++;
        }

        if(prevcritical == firstcritical) return ans;

        int max_distance = prevcritical - firstcritical;
        ans[0] =min_distance;
        ans[1] = max_distance;

        return ans;
        
    }
};
