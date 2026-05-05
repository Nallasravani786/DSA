#### I M A G E 
<img width="2863" height="1427" alt="image" src="https://github.com/user-attachments/assets/94b9bb0c-3bd3-4cf9-9319-c9a6020ff523" />

#### I N T U I T I O N 

XOR of two numbers gives 1 at a bit only if bits are different (0 & 1)
So instead of checking all pairs, we count how many numbers have 0 and 1 at each bit
For each bit, valid pairs = count0 × count1
Each such pair contributes value 2^bit to the answer
Add contributions of all bits to get the final sum

👉 In short: Count 0–1 pairs per bit instead of checking every pair 🚀

```cpp
long long sumXOR(vector<int> &arr) {
       
        int n = arr.size();
        long long sum = 0;
        
       for(int bit = 0; bit<32;bit++){
           long long count1 = 0;
           
           for(int i=0;i<n;i++) {
               if(arr[i] & (1<<bit)) count1++;
           }
           
           long long count0 = n-count1 ;
           sum += count0*count1*(1LL << bit);
           
       }
       return sum;
    }

```
