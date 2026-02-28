###### C O D E
```cpp

    int concatenatedBinary(int n) {
        long long ans = 0;
        int MOD = 1e9 + 7;
        int bits = 0; // Prati number ki enni bits unnayo track cheyadaniki

        for (int i = 1; i <= n; i++) {
            // Ikkada logic: i anedi 2 power (2, 4, 8, 16...) ayinappudu
            // bit length okkati perugutundi. 
            // Udaharanaki: 3 (11) nundi 4 (100) ki vellinappudu bits 2 nundi 3 ki marutayi.
            if ((i & (i - 1)) == 0) {
                bits++;
            }
            
            // Ans ni left ki shift chesi, i ni add chestunnam.
            // Ans = (Ans * 2^bits + i) % MOD
            ans = ((ans << bits) | i) % MOD;
        }

        return (int)ans;
    }

```
