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

int n;
Pll p[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].second += p[i].first;
  }
  sort(p + 1, p + n + 1);

  int ans = 0, idx = 1;
  ll now = 1;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  while (idx <= n) {
    if (que.empty()) {
      now = p[idx].first;
    }

    for (int i = idx; i <= n; i++) {
      if (p[i].first <= now) {
        que.push(p[i].second);
        idx++;
      } else {
        break;
      }
    }

    bool flag = false;
    while (!que.empty()) {
      ll q = que.top();
      que.pop();
      if (now <= q) {
        flag = true;
        break;
      }
    }
    if (flag) {
      ans++;
      now++;
    }
  }

  while (!que.empty()) {
    ll q = que.top();
    que.pop();

    if (now <= q) {
      now++;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
