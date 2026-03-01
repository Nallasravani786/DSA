### C O D E (Brute) 

```cpp
void pushZerosToEnd(vector<int>& arr) {
        
         vector<int>temp;
         for(int i=0;i<arr.size();i++){
            if(arr[i]!=0) temp.push_back(arr[i]);
         }
        
        for(int i=0;i<temp.size();i++){
            arr[i] = temp[i];
         }
         for(int i=temp.size();i<arr.size();i++){
            arr[i] = 0;
         }
    
    }

```

### C O D E ( Optimal) 
```cpp

void pushZerosToEnd(vector<int>& arr) {
        
        int n = arr.size();
        int j =-1;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) {
                j = i;
                break;
            }
        }
        if(j==-1) return ;
        for(int i=j+1;i<n;i++){
            if(arr[i]!=0)  {
                swap(arr[j],arr[i]); 
                j +=1;
                
            }
        }
        
    }
```
