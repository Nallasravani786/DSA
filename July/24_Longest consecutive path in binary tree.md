####   I M A G E
<img width="2834" height="1352" alt="image" src="https://github.com/user-attachments/assets/8171d01e-2ae6-4258-a9d4-437b7e394799" />

###### C O D E
```cpp
void dfs(Node*root,int expected,int &max_len,int len){
     if(root == NULL) return ;
     
     if(root->data == expected) len++;
     
     else len = 1;
     
     max_len = max(max_len,len);
     
     dfs(root->left,root->data +1,max_len,len);
     dfs(root->right,root->data +1,max_len,len);
   
 }

  
    int longestConsecutive(Node* root) {
        if(root == NULL) return -1;
       
        int max_len = 0,len = 0;
     
        dfs(root,root->data,max_len,len);
        return (max_len >= 2) ? max_len: -1;
    }


```
