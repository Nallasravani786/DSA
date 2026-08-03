void processStrings(string str1, int n)
{
    while (!str1.empty() &&
          (str1.back()=='\r' || str1.back()==' '))
        str1.pop_back();

    int dictSize = sizeof(str)/sizeof(str[0]);

    string cur = str1;

    for(int i=0;i<n;i++)
    {
        int idx = (cur.length()-1)/2;
        char mid = cur[idx];

        string next="";

        for(int j=0;j<dictSize;j++)
        {
            if(str[j][0]==mid)
            {
                next=str[j];
                break;
            }
        }

        if(next=="") break;

        cout<<next;

        if(i!=n-1)
            cout<<" ";

        cur=next;
    }
}
