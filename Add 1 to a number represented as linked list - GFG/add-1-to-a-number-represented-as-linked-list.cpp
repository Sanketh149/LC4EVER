//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node* head) {
        if(!head or !head->next) return head;
        Node *rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    Node* addOne(Node *p) 
    {
        Node *head = reverseList(p);
        if(!head)
        {
            Node *curr = new Node(1);
            return curr;
        }
        Node *curr = head;
        int carry = 0;
        while(curr)
        {
            if(carry == 1)
            {
                if(curr->data+1<=9)
                {
                    curr->data += 1;
                    return reverseList(head);
                }
                else{
                    curr->data = 0;
                    carry = 1;
                }
            }
            else if(carry == 0 and curr->data+1<=9) 
            {
                curr->data += 1;
                return reverseList(head);
            }
            else{
                carry = 1;
                curr->data = 0;
            }
            curr = curr->next;
        }
        Node *one = new Node(1);
        one->next = head;
        return one;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends