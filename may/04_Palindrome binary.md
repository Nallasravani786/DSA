#### I M A G E 
<img width="2879" height="1454" alt="image" src="https://github.com/user-attachments/assets/0e10a749-396b-421e-bdcb-6e222b0db1cc" />

#### I N T U I T I O N 
Convert the number into its binary representation (string)
Use two pointers: one at start (i), one at end (j)
Compare characters at both ends (temp[i] and temp[j])
If any pair doesn’t match → not a palindrome (return false)
If all pairs match while moving inward → it’s a palindrome (return true)

👉 In short: Binary conversion + two-pointer palindrome check

```cpp
 string tobinary(int n){
      if(n == 0) return "0";
      string res = "";
      while(n>0){
          res = char('0' + n%2) + res;
          n /=2;
      }
      return res;
  }
  
  
    bool isBinaryPalindrome(int n) {
       if(n == 0 || n==1) return true;
       string temp = tobinary(n);
       int i=0,j = temp.size()-1;
       
       while(i<j){
           if(temp[i]!=temp[j]) return false;
           i++;
           j--;
       }
       return true;
        
    }

```
