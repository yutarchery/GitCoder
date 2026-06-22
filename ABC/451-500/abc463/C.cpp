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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, h[int(3e5 + 5)], l[int(3e5 + 5)];
int q, t[int(3e5 + 5)];

priority_queue<Pii> h_l;
priority_queue<Pii, vector<Pii>, greater<Pii>> t_idx;
int ans[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> l[i];
    h_l.push({h[i], l[i]});
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i];
    t_idx.push({t[i], i});
  }

  while (!t_idx.empty()) {
    Pii now = t_idx.top();
    t_idx.pop();

    while (!h_l.empty()) {
      int now_l = h_l.top().second;
      if (now.first < now_l) {
        ans[now.second] = h_l.top().first;
        break;
      }
      h_l.pop();
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
