### I N T U I T I O N
  Core Intuition: Digit-by-Digit MultiplicationOkkasari ee points choodu:
  
  The Container: Rendu numbers $n1$ and $n2$ length lo unte, avi multiply chesinappudu 
  vachhe max length $n1 + n2$ untundhi.
  
  Anduke manam oka res vector ni aa size tho start chestham.Reverse Engineering: 
  Strings ni reverse nundi (n-1 to 0) loop chestham. 
  
  Endukante multiplication eppudu units place nundi start avvali kabatti.
  The "i + j + 1" Trick: 
  
  Ide main logic thammudu. num1[i] and num2[j] multiply chesinappudu:
  
  Vachhe product ni i + j + 1 index (current position) daggara unna 
  value ki add chestham.Aa total sum lo 
  
  vachhe Carry ni ventane daanikante mundu unna position i + j ki 
  transfer chestham.Cleaning Up: 
  
  Last ki aa vector lo unna zeros ni (leading zeros) remove chesi
  string ga marchithe mana answer ready!


  ###### C O D E

  ```cpp
string multiply(string num1, string num2) {
     int n1 = num1.size();
     int n2 = num2.size();

     vector<int>res(n1+n2,0);

     for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            int mul = (num1[i]-'0')*(num2[j]-'0');
            int sum = mul + res[i+j+1];
            res[i+j+1] = sum%10;
            res[i+j] += sum/10;
        }

     }

     string result ="";
    
     for(int p : res){
        if(!(result.empty()  && p==0)){
            result += to_string(p);
        }
     }

       return result.empty() ? "0" : result;  
    }
  ```
