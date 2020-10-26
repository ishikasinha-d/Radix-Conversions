//relative indirect conversion
#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;
vector <pair<int,int>> prime_factorization(int n)
{
    vector <pair<int,int>> v;
    for(int i=2;i*i<=n;i++)
  {int count=0;
    while(n%i==0)
    {
        count++;
        n/=i;
    }
    v.push_back({i,count});
  }
  if(n!=1)
  v.push_back({n,1});
  return v;

}
int alpha_to_num(char ch)
{
    if(ch=='A') return 10;
    if(ch=='B') return 11;
    if(ch=='C') return 12;
    if(ch=='D') return 13;
    if(ch=='E') return 14;
    if(ch=='F') return 15;
    
}
void print(ll x)
{
    if(x==10) cout<<"A";
    if(x==11) cout<<"B";
    if(x==12) cout<<"C";
    if(x==13) cout<<"D";
    if(x==14) cout<<"E";
    if(x==15) cout<<"F";
}
string Conversion1(string num,int base1, int base2, int group)
{
    string tempn,intermediate_value="";
    int temp,p=0;

vector<vector<int>> ans;
vector<int> v;

 tempn=num; 
for(int i =num.length()-1;i>=0;i--)
{   int count=group;
    if(!isalpha(num[i]))
        p=int(num[i])-48;
    else
        p=alpha_to_num(num[i]);
        
    while(p)
    {
        v.push_back(p%base2);
        p/=base2;
        count--;
    }
    while(count--)
        v.push_back(0);
    reverse(v.begin(),v.end());
    ans.push_back(v);
    v.clear();
   
}
reverse(ans.begin(),ans.end());

for(auto x: ans)
    for(auto y: x)
        {intermediate_value+=to_string(y);}
        
return intermediate_value;
}

void Conversion2(string num, int base1, int base2,int group)
{
   int temp,p=0,x=0;
vector<int> ans;

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

reverse(ans.begin(),ans.end());
for(auto x: ans)
    {
        if(x>=10)
            print(x);
        else
        cout<<x;}
cout<<" base "<<base2<<endl;
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
cout<<num<<" base "<<base1<<" = ";

//prime factorization of base1 and base2;
vector <pair<int,int>> b1=prime_factorization(base1);
vector <pair<int,int>> b2=prime_factorization(base2);

if(b1.size()!=1 || b2.size()!=1 || b2[0].first!=b1[0].first)
   { cout<<"Conversion not possible"<<endl;
    exit(0);}
string value=Conversion1(num,base1,b1[0].first,b1[0].second);

Conversion2( value,b1[0].first, base2,b2[0].second);

return 0;

}