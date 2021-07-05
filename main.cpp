#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 string a,b;

    int length,start_print = 0, end_print = 0, numbers;
    cin>>numbers;
    while(numbers--)
    {
        vector<int>s(250,0);
        cin>>a>>b;
        length= max(a.size(),b.size());

        // to convert a char by subtract it from '0'
        for(int i=0;i<a.size();i++)
        {
            s[i] += (a[i] - '0');
        }
        for(int i=0;i<b.size();i++)
        {
            s[i] += (b[i] - '0');
        }

        // we use this like ( 12 --> 1 stay by % and 2 go to the next digit by division )
        for(int i=0;i<length;i++)
        {
            if(s[i]>=10)
            {
                s[i+1] = s[i+1] + s[i]/10;
                s[i] = s[i]%10;
            }
        }

        // to get the start point
      for(int i=length+1;i>=0;i--)
      {
          if(s[i]!=0){end_print=i;break;}
      }

      // to get the end point
      for(int i=0;i<=length+1;i++)
      {
          if(s[i]!=0){start_print=i;break;}
      }

      // print from start point to the end point
      for(int i= start_print; i<=end_print;i++)
      {
         cout<<s[i];
      }



cout<<endl;
    }



    return 0;
}
