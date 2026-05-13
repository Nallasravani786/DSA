#### I M A G E
<img width="2861" height="1353" alt="image" src="https://github.com/user-attachments/assets/5fc82613-4c79-4332-bc07-e303a63f39b5" />

#### I N T U I T I O N
Use two pointers:
slow moves 1 step
fast moves 2 steps
If there is a cycle, both pointers will eventually meet inside the loop.
Once they meet:
keep one pointer fixed
move another pointer forward until it reaches the same node again
Count how many steps are taken during this traversal.
That count is the length of the loop.

###### C O D E

```cpp
 int lengthOfLoop(Node *head) {
        Node*slow = head;
        Node*fast = head;
       
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
        if(slow == fast){
            
            int len =1;
            
            Node*temp = slow->next;
            
            while(temp!=slow){
                temp = temp->next;
                len++;
            }
            
            return len;}
        }
        return 0;
    }
```
