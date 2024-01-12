#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    //Link List structure
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* head;

    // solutions;
    ListNode* reverseit(ListNode* root, int k){
        ListNode * current = root;
        ListNode* prev = nullptr;
        while(k){
            current = root;
            root = root->next;
            current->next = prev;
            prev =current;
        }
        return current->next;
    }
    void reversekelement(ListNode* head, int k){

        ListNode* temp = head;
        while(!temp) temp = reverseit(temp,k);
        temp = head;

        // printing the value;
        while(!temp->next){
            cout << temp->val << " " ;
            temp = temp->next;
        }

    }
    void removedublicate(ListNode* head){
        ListNode* temp = head;
        while(!temp->next && !temp->next->next){
            if(temp->next->val == temp->val) temp->next = temp->next->next;
            temp->next;
        }

        // printing the value;
        while(!temp->next){
            cout << temp->val << " " ;
            temp = temp->next;
        }
    }
    void insertintolinklist(vector<int>&arr, int k){
        ListNode* temp = head;
        head->val = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(temp->val < arr[i]){
                temp->next->val = arr[i];
            }
            else if (temp->val > arr[i]){
                // prev condition;
            }
            else{
                //something
            }
            
        }

        // printing the value;
        while(!temp->next){
            cout << temp->val << " " ;
            temp = temp->next;
        }
        removedublicate(head);
        reversekelement(head , k);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;

    int n , k;
    cin >> n >> k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sol.insertintolinklist(arr , k);
    return 0;
}