//to convert from base 1 to base 2
#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

using namespace std;
void base_to_decimal(char s[],int radix)
{
    int count=0,r,digit,i,n=0,b=1;
    for(i=strlen(s)-1;i>=0;i--)     //traversing the string starting from lsb
        {
         if(s[i]>='A'&&s[i]<='Z')
            {
             digit=s[i]-'0'-7;  
            }
         else
            {
             digit=s[i]-'0';
            }
        n=digit*b+n;
        b=b*radix;
        }
    while(n!=0)
    {
        r=n%10;
        digit='0'+r;
        if(digit>'9')
        {
            digit+=7;
        }
         s[count]=digit;
         count++;
         n=n/10;
    }
for(i=count-1;i>=0;i--)
    {
     cout<<s[i];
    }
 cout<<endl;

}
int main()
{ 
   fast;

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);     //opening input.txt file to read input
freopen("output.txt","w",stdout);       //opening output.txt file to write input
#endif
   char s[20];
   //taking inputs
    ll base;
    cout<<"Enter the number and base\n";
    cin>>s>>base;
    base_to_decimal(s,base);      //function call
return 0;

}


