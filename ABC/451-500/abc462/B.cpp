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

int n, k[105];
vector<int> a[105], b[105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    a[i].resize(k[i]);
    for (int j = 0; j < k[i]; j++) {
      cin >> a[i][j];
      b[a[i][j]].emplace_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    sort(b[i].begin(), b[i].end());
    cout << b[i].size();
    for (int j = 0; j < b[i].size(); j++) {
      cout << ' ' << b[i][j];
    }
    cout << '\n';
  }

  return 0;
}
