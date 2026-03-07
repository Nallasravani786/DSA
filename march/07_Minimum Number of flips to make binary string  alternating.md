<img width="2819" height="1372" alt="image" src="https://github.com/user-attachments/assets/11e932cf-516f-4706-92cb-6f6bb2e734f6" />

### I N T U I T I O N 
![WhatsApp Image 2026-03-07 at 4 13 31 PM](https://github.com/user-attachments/assets/7182a94d-b3be-4f07-9265-3826069d8eb3)


###### C O D E

```cpp
int minFlips(string s) {
        int n = s.length();
        string concatenate = s+s;
       string p1="",p2="";
       for(int i=0;i<2*n;i++){
        p1+= (i%2==1) ? '0':'1';
        p2+= (i%2==1) ? '1': '0';
       }
      int cnt1 =0,cnt2=0,mini = INT_MAX;
      for(int i=0;i<2*n;i++){
        if(concatenate[i]!= p1[i]) cnt1++;
        if(concatenate[i]!=p2[i]) cnt2++;
        if(i>=n){
             if(concatenate[i-n]!= p1[i-n]) cnt1--;
             if(concatenate[i-n]!=p2[i-n]) cnt2--;
        }
        if(i>=n-1) mini  = min({cnt1,cnt2,mini});
        
      }
      
      return mini;
    }

```
