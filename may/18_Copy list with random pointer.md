
#### I M A G E
<img width="2844" height="1421" alt="image" src="https://github.com/user-attachments/assets/2c468d59-32fd-4530-8eca-71c2e475ea24" />

####   I N T U I T I O N

Each node has: next pointer  , random pointer

We must create completely new nodes with the same connections.

Main challenge:

copied random pointers should point to copied nodes,  not original nodes.

Use a hashmap to store:  original node -> copied node

First pass:   create all copied nodes.

Second pass:  connect next , connect random using hashmap.

Hashmap helps us instantly find:  copy of any original node

###### C O D E
```cpp
 Node* copyRandomList(Node* head) {
        Node*temp = head;
        unordered_map<Node*,Node*>mp;

        while(temp!=NULL){
            
            Node*newnode = new Node(temp->val);
            mp[temp] = newnode;
            temp = temp->next;
        }

        temp = head;
        while(temp!=NULL){
        
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }

```
