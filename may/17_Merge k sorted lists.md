
#### I M A G E

<img width="2851" height="1465" alt="image" src="https://github.com/user-attachments/assets/5c43bc8a-1e34-4942-9b58-0de142691a6b" />

#### I N T U I T I O N

Start with first linked list as answer.

Merge it with second list.

Merge resulting list with third list.

Continue until all lists are merged


###### C O D E

```cpp
ListNode*merge(ListNode*a,ListNode*b){
    ListNode*temp = new ListNode(-1);
    ListNode*dummy = temp;

    while(a!=NULL && b!=NULL){
        if(a->val < b->val){
            temp->next = a;
            a = a->next;
        }
        else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    if(a!=NULL) temp->next = a;
    if(b!=NULL) temp->next = b;
    return dummy->next;
 }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;

        ListNode*ans = lists[0];
        
        for(int i=1;i<n;i++){
            ans = merge(ans,lists[i]);
        }
        return ans;
    }

```
