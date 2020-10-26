//to convert a number from radix ‘x’ to radix ‘y’ using concept of relative direct conversion where (x < y)
#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;
void print(ll x)
{
    if(x==10) cout<<"A";
    if(x==11) cout<<"B";
    if(x==12) cout<<"C";
    if(x==13) cout<<"D";
    if(x==14) cout<<"E";
    if(x==15) cout<<"F";
}
int main()
{ 
   fast;

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

string num;
int base1,base2,group=1,temp,p=0,x=0;
vector<int> ans;
cout<<"Enter the number and its base: "<<endl;
cin>>num>>base1;
cout<<"Enter base to which it is converted: "<<endl;
cin>>base2;

temp=base2;
while(temp!=base1)
{
    temp/=base1;
    group++;
}

for(int i=num.length()-1;i>=0;i--)
{
    x+=(int(num[i])-48)*pow(base1,p%group);
    
    p++;
    if(p%group==0)
        { 
            ans.push_back(x);
            x=0;
        }
} 
if(x!=0)
    ans.push_back(x);
cout<<num<<" base "<<base1<<" = ";
reverse(ans.begin(),ans.end());
for(auto x: ans)
    {
        if(x>=10)
            print(x);
        else
        cout<<x;}
cout<<" base "<<base2<<endl;
return 0;

}