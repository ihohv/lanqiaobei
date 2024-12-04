// https://www.lanqiao.cn/problems/3291/learning/?page=1&first_category_id=1&problem_id=3291
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N],diff[N];
int n, m, x, y, z;

// 法一
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int d[N] = {0};
        while (m--) {
            cin >> x >> y >> z;
            d[x] += z;
            d[y + 1] -= z;
        }

        for (int i = 1; i <= n; i++)
            d[i] += d[i - 1];

        for (int i = 1; i <= n; i++)
            cout << a[i] + d[i] << " ";
        cout << endl;
    }

    return 0;
}

// 法二
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
      for(int i=1;i<=n;i++)
        cin>>a[i];
      for(int i=1;i<=n;i++)
        diff[i] = a[i] - a[i-1];
      while(m--){
        cin>>x>>y>>z;
        diff[x] += z;
        diff[y+1] -=z;
      }
      for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];
        cout<<diff[i]<<" ";
      }
      cout<<endl;
    }

    return 0;
}