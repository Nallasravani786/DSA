#### I M A G E
<img width="2853" height="1349" alt="image" src="https://github.com/user-attachments/assets/8ae16f6f-59c2-431a-8338-0fc40853f993" />

#### I N T U I T I O N
Here’s the intuition in few simple points:

Traverse tree T (root1) node by node

At each node, check:

👉 “Is subtree starting here equal to S (root2)?”

Use a helper to check if two trees are identical

If match found → return true

Else → recursively search in left and right subtree

👉 One-line:
“Check match at every node; if not, keep searching left and right” 🚀


```cpp
 bool isSame(Node*p,Node*q){
      if(!p && !q) return true;
      if(!p || !q) return false;
      
      return (p->data == q->data) && isSame(p->left,q->left) && isSame(p->right,q->right);
  }
  
 
  
    bool isSubTree(Node *root1, Node *root2) {
        if(!root1) return false;
        if(isSame(root1,root2)) return true;
        
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
        
    }

```



