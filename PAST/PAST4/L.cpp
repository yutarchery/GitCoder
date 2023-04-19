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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, q;
ll h[int(2e5 + 5)];
map<ll, int> cnt;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  for (int i = 1; i + 1 <= n; i++) {
    if (i % 2 == 0) {
      cnt[h[i + 1] - h[i]]++;
    } else {
      cnt[h[i] - h[i + 1]]++;
    }
  }

  ll now = 0;
  for (int i = 0; i < q; i++) {
    int num;
    cin >> num;

    if (num == 1) {
      ll v;
      cin >> v;
      now -= v;
      cout << cnt[now] << endl;
    } else if (num == 2) {
      ll v;
      cin >> v;
      now += v;
      cout << cnt[now] << endl;
    } else {
      ll u, v;
      cin >> u >> v;

      if (u % 2 == 0) {
        if (u + 1 <= n) {
          cnt[h[u + 1] - h[u]]--;
          cnt[h[u + 1] - (h[u] + v)]++;
        }
        if (u >= 1) {
          cnt[h[u - 1] - h[u]]--;
          cnt[h[u - 1] - (h[u] + v)]++;
        }
      } else {
        if (u + 1 <= n) {
          cnt[h[u] - h[u + 1]]--;
          cnt[(h[u] + v) - h[u + 1]]++;
        }
        if (u >= 1) {
          cnt[h[u] - h[u - 1]]--;
          cnt[(h[u] + v) - h[u - 1]]++;
        }
      }

      h[u] += v;
      cout << cnt[now] << endl;
    }
  }

  return 0;
}