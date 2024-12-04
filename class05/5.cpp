// https://www.lanqiao.cn/problems/3419/learning/?page=1&first_category_id=1&problem_id=3419
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N];

int prefix[N];

int main()
{
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]+(s[i]=='L'?1:-1);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(prefix[j]-prefix[i-1]==0)ans=max(ans,j-i+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}