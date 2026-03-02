### I N T U I T I O N 
Pre-calculate Left Max: Array ni left nundi scan chesthu, prati point daggara appati varaku unna tallest building ni left[] array lo store cheyali.

Pre-calculate Right Max: Array ni right nundi scan chesthu, prati point daggara appati varaku unna tallest building ni right[] array lo store cheyali.

Final Calculation: Prati building daggara paina cheppina formula apply chesi, vachina values anni add chesthe total water trapped vachesthundhi.


###### C O D E 

```cpp
int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        
        left[0] = arr[0];
        for(int i=1;i<n;i++) {
            left[i] = max(left[i-1],arr[i]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        int res =0;
        for(int i=1;i<n-1;i++){
            int minof2 = min(left[i],right[i]);
            res+= minof2 -arr[i];
        }
        return res;
    }


```
