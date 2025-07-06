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

int q, op;
ll c, x, k;
deque<Pll> que;

int main() {
  cin >> q;
  while (q--) {
    cin >> op;

    if (op == 1) {
      cin >> c >> x;
      que.push_back({x, c});
    } else {
      cin >> k;
      ll ans = 0;

      while (k > 0) {
        Pll now = que.front();
        que.pop_front();
        if (k < now.second) {
          ans += now.first * k;
          que.push_front({now.first, now.second - k});
          break;
        } else {
          ans += now.first * now.second;
          k -= now.second;
        }
      }

      cout << ans << endl;
    }
  }

  return 0;
}
