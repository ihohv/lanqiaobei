// https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5
#include <iostream>
#include <unordered_map>

using namespace std;

// 注意类名必须为 Main, 并且代码应直接放在全局作用域中
const int N = 100001;
int arr[N];
int n, k;
unordered_map<int, int> map;

int compute() {
    map.clear();
    map[0] = -1;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (map.find(sum - k) != map.end()) {
            ans = max(ans, i - map[sum - k]);
        }
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout << compute() << endl;
    return 0;
}