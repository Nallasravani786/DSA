<img width="2780" height="1212" alt="image" src="https://github.com/user-attachments/assets/a66e541e-735b-4590-a4ca-9f267c12e57a" />

### I N T U I T I O N 
The Masking Strategy: To target only the relevant bits, we build a bitmask of all 1s that has the same bit-length as the input $n$.

Example: If $n = 5$ ($101_2$), we generate a mask of $7$ ($111_2$).

The XOR Property: Using the XOR (^) operator between $n$ and the mask effectively flips every bit of $n$ ($0 \to 1$ and $1 \to 0$) within that specific range, as $X \oplus 1 = \neg X$.

Implementation: We traverse the bits of $n$ using a while loop to shift the mask and populate it with 1s until we cover the entire magnitude of the number

###### C O D E 

```cpp
int bitwiseComplement(int n) {
        if(n==0) return 1;
        int temp =n;
        int mask =0;
        while(temp!=0){
            mask = (mask<<1) | 1;
            temp = temp>>1;
        }
        return n^mask;
    }

```
