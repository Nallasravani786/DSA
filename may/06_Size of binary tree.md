#### I M A G E 
<img width="2822" height="1338" alt="image" src="https://github.com/user-attachments/assets/ab78d4e1-5eab-4c5e-a9be-4766013f0faa" />


###### C O D E
```cpp
int getSize(Node* root) {
        if(root == NULL) return 0;
        
        return getSize(root->left)+getSize(root->right)+1;
        
    }

```
