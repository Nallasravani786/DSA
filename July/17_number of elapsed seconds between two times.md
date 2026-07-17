###### C O D E
```cpp
 int secondsBetweenTimes(string startTime, string endTime) {
        int shrs = stoi(startTime.substr(0,2));
        int smin = stoi(startTime.substr(3,2));
        int ssec = stoi(startTime.substr(6,2));

        int ehrs = stoi(endTime.substr(0,2));
        int emin = stoi(endTime.substr(3,2));
        int esec = stoi(endTime.substr(6,2));

        int first = shrs*3600 + smin*60 + ssec;
        int second = ehrs*3600 + emin*60 + esec;

        return second-first;
    }

```
