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

ll h, w, m;
ll t[int(2e5 + 5)], a[int(2e5 + 5)], x[int(2e5 + 5)];

bool visited_h[int(2e5 + 5)], visited_w[int(2e5 + 5)];
ll rest_h, rest_w;

ll cnt[int(2e5 + 5)];
vector<Pil> ans;

int main() {
  cin >> h >> w >> m;
  for (int i = 1; i <= m; i++) {
    cin >> t[i] >> a[i] >> x[i];
  }

  rest_h = h, rest_w = w;
  for (int i = m; i >= 1; i--) {
    if (t[i] == 1) {
      if (visited_h[a[i]]) {
        continue;
      }

      cnt[x[i]] += rest_w;
      visited_h[a[i]] = true;
      rest_h--;
    } else {
      if (visited_w[a[i]]) {
        continue;
      }

      cnt[x[i]] += rest_h;
      visited_w[a[i]] = true;
      rest_w--;
    }
  }

  cnt[0] += rest_h * rest_w;
  for (int i = 0; i <= int(2e5); i++) {
    if (cnt[i] > 0) {
      ans.push_back({i, cnt[i]});
    }
  }

  cout << ans.size() << endl;
  for (Pll p : ans) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
