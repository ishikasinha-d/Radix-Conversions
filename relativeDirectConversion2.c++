//to convert a number from radix ‘x’ to radix ‘y’ using concept of relative direct conversion where (x > y)
#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

int alpha_to_num(char ch)
{
    if(ch=='A') return 10;
    if(ch=='B') return 11;
    if(ch=='C') return 12;
    if(ch=='D') return 13;
    if(ch=='E') return 14;
    if(ch=='F') return 15;
    return 0;
}

int main()
{ 
   fast;

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int  base1,base2,group=1,temp,p=0;
string num,tempn;
vector<vector<int>> ans;
vector<int> v;
cout<<"Enter the number and its base: "<<endl;
cin>>num>>base1;
cout<<"Enter base to which it is converted: "<<endl;
cin>>base2;

temp=base1;
while(temp!=base2)
{
    temp/=base2;
    group++; 
}
tempn=num; 
for(int i =num.length()-1;i>=0;i--)
{   int count=group;
    if(!isalpha(num[i]))
        p=int(num[i])-48;
    else
        p=alpha_to_num(num[i]);
    
    //cout<<p<<" ";
    while(p)
    {
        v.push_back(p%base2);
        p/=base2;
        count--;
    }
    while(count--)
        v.push_back(0);
    reverse(v.begin(),v.end());
    // for(auto j:v)
    //     cout<<j;
    // cout<<endl;
    ans.push_back(v);
    v.clear();
   
}
reverse(ans.begin(),ans.end());
for(auto x: ans)
    for(auto y: x)
        cout<<y;
return 0;

}