
#### I M A G E
<img width="2843" height="1433" alt="image" src="https://github.com/user-attachments/assets/163022c4-64e5-475d-a336-3d4345d862dd" />

#### I N T U I T I O N 

Traverse the linked list once and store all node values in a vector.

Vector allows:  direct indexing  , easy random access.

Generate a random index between:  0 to size-1

Return the element at that random index.

Since every index has equal probability,

every linked list node also gets equal probability

###### C O D E

```cpp
 vector<int>arr;

    Solution(ListNode* head) {

        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int index = rand()%arr.size();
        return arr[index];
        
    }
```
