#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* head = new ListNode();

    ListNode* reversekelement(ListNode* head, int k){
        ListNode* temp=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int n=0;
        while(temp!=0) n++,temp=temp->next;
        if(n<k)return head;
        int count=0;
        while(curr!=0 && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(curr!=NULL)head->next=reversekelement(curr,k);
        return prev;
    }

    void removedublicate(ListNode* head){
        ListNode* temp = head;
        while(temp->next && temp->next->next){
            if(temp->next->val == temp->val) {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
         printlinklist(head);
    }

    void insertintolinklist(vector<int>&arr, int k){
        ListNode* temp = head;
        sort(arr.begin(),arr.end());
        head->val = arr[0];
        for(int i=1;i<arr.size();i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        printlinklist(head);
        removedublicate(head);
        ListNode* some = reversekelement(head , k);
        printlinklist(some);
    }

    void printlinklist(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout << temp->val << " " ;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    int n , k;
    cout << "Enter number of element in the array: ";
    cin >> n;
    cout << "Enter K: ";
    cin >> k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sol.insertintolinklist(arr , k);
    return 0;
}