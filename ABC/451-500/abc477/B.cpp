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

int n;
ll d, x[105];
Pli p[105];

vector<int> ans;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    p[i] = {x[i], i};
  }
  sort(p + 1, p + n + 1);
  p[0] = {-1e16, 0};
  p[n + 1] = {1e16, n + 1};

  for (int i = 1; i <= n; i++) {
    if (abs(p[i - 1].first - p[i].first) >= d &&
        abs(p[i].first - p[i + 1].first) >= d) {
      ans.emplace_back(p[i].second);
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
