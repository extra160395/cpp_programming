// O(n)
// calculate sum of hamming distance between every pair of elements in array
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>a{2,4,6};
    long int n=a.size(),i,j,temp,odd,even,ans=0;
    vector<string>v;
    string s="";
    for(i=0;i<n;i++)
    {
        temp=a[i];
        s="";
        while(temp!=0)
        {
            s=to_string(temp%2)+s;
            temp/=2;
        }
        temp=32-s.size();
        while(temp--)
            s='0'+s;
        cout<<s<<endl;
        v.push_back(s);
    }
    for(i=0;i<32;i++)
    {
        odd=0,even=0;
        for(j=0;j<n;j++)
        {
            if(v[j][i]=='0')
                odd++;
            else
                even++;
        }
        ans+=odd*even;
    }
    cout<< ans;
}