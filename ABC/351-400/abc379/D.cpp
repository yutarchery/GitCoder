#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int q, num;
ll t, h, height[int(2e5 + 5)];
queue<int> que;

int main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> num;
    if (num == 1) {
      height[i] = height[i - 1];
      que.push(i);
    } else if (num == 2) {
      cin >> t;
      height[i] = height[i - 1] + t;
    } else {
      cin >> h;
      height[i] = height[i - 1];
      int ans = 0;
      while (!que.empty()) {
        if (height[i] - height[que.front()] >= h) {
          ans++;
          que.pop();
        } else {
          break;
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}
