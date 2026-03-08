### I M A G E
<img width="2829" height="1252" alt="image" src="https://github.com/user-attachments/assets/b41b03d3-383d-40e5-86be-14b093d6077c" />

### I N T U I T I O N
![WhatsApp Image 2026-03-08 at 11 38 19 AM](https://github.com/user-attachments/assets/fb14b464-0be6-4a01-b088-2f90bf7f1a8c)


###### C O D E 
```cpp
bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>present(1001,0);
        for(int i=0;i<n;i++) present[arr[i]] =1;
        
        for(int i=1;i<=1000;i++){
            if(!present[i]) continue;
            
            for(int j=i+1;j<=1000;j++){
                if(!present[j]) continue;
                
                int sumofsq = i*i + j*j;
                int c = sqrt(sumofsq);
                
                if(c*c == sumofsq && c<=1000 && present[c]==1) return true;
                
            }
        }
        
            return false;
    }

```


