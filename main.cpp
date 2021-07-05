#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool visited[1000] ={false};
map<int,vector<int>>vi;
int counter = 0;
void dfs(int node)
{
    visited[node] = true;

    for(int child : vi[node])
    {
        if(!visited[child])
        {   counter++;
            dfs(child);
        }
    }

}
void read()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        vi[x].push_back(y);
        vi[y].push_back(x);

    }
    if(m==0){cout<<1<<endl;}
    else {

    for(int i=1;i<=n;i++)
    {
       if(!visited[i])
       {
           dfs(i);
       }
    }
    long long res = pow(2,counter);
        cout<<res;

    }
}


long long my_pow(long long n,long long p,long long a)
{
     if(p==0) return 1;
      long long x = my_pow(n,p/2,a);
      x=((x)*(x));
      if(p%2==1)
      {
          x=(x*n);

      }
      return x%a;

      // x = (x* x * (x*n)->(if odd) )% a -> (x%a * x%a * (x*n)%a)%a
}

long long factorial(long long n,long long stop =0)
{

    if(stop==0)return 1;
    n = n*factorial(n-1,stop-1);
    return  n;
}
long long factorial2(long long n)
{

    if(n==1)return 1;
    n = n*factorial2(n-1);
    return  n;
}
long long combination(long long num , long long r)
{

    long long res = factorial(num,num-max(num-r,r)) / (factorial2(min(num-r,r)));
    return res;
}
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
