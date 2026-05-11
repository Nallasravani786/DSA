#### I M A G E
<img width="2858" height="1379" alt="image" src="https://github.com/user-attachments/assets/a2235711-3940-47af-beb6-d8eb77ddb300" />

###### c o d e

```cpp
vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        string temp = "";

        for(int i=0;i<n;i++){
        temp += to_string(nums[i]);
        }
        vector<int>ans;
      for(auto &c : temp){
        ans.push_back(c-'0');
      }
      return ans;
    }

```
