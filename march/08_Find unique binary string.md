<img width="2811" height="1389" alt="image" src="https://github.com/user-attachments/assets/67559112-cc46-4f39-a22f-ccc4330ab0bc" />

### I N T U I T I O N

![WhatsApp Image 2026-03-08 at 10 24 12 AM](https://github.com/user-attachments/assets/f107b693-87c4-49df-8ead-0ea7dc74e429)

###### C O D E

```cpp
string findDifferentBinaryString(vector<string>& nums) {
        string ans ="";
        for(int i=0;i<nums.size();i++){

        if(nums[i][i] == '0') ans+= '1';

        else ans+= '0';
        }
        return ans;
    }

```
