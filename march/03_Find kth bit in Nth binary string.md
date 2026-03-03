### I N T U I T I O N 
<img width="1341" height="579" alt="image" src="https://github.com/user-attachments/assets/2dc366ff-8403-4ea2-8587-1f21d5eaeea8" />


###### C O D E
```cpp
 char findKthBit(int n, int k) {
        if(n==1) return '0';

        int length = (1<<n)-1;
        int mid = length/2 +1;

        if(k==mid){
            return '1';
        }
        else if(k<mid){
            return findKthBit(n-1,k);
        }
        else {
            int mirroredk = length -k+1;

            char bit =  findKthBit(n-1,mirroredk);
            return (bit =='0') ? '1' : '0';
        }
    }

```






