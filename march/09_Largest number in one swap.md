<img width="2822" height="1148" alt="image" src="https://github.com/user-attachments/assets/59eeb617-13c2-44d2-a138-d8df5b354d41" />


### I N T U I T I O N 

![WhatsApp Image 2026-03-09 at 6 47 27 PM](https://github.com/user-attachments/assets/bbe99624-14c0-4113-9282-532712365b07)


###### C O D E

```cpp
string largestSwap(string &s) {
        int  n = s.length();
        vector<int>last_pos(10,-1);
       for(int i=0;i<n;i++) last_pos[s[i]-'0'] = i;
       for(int i=0;i<n;i++){
           int curr_dig = s[i]-'0';
           
           for(int dig = 9 ; dig >curr_dig ; dig--){
               if(last_pos[dig]>i) {
                   swap(s[i],s[last_pos[dig]]);
                   return s;
               }
           }
       }
       
       
       return s; 
    }

```
