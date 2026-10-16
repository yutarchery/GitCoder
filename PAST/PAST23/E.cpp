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
ll a[1005], b[1005];

int ans[1005];

bool my_comp(int& i, int& j) {
  return __int128_t(a[i]) * __int128_t(b[j]) <
         __int128_t(a[j]) * __int128_t(b[i]);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    ans[i] = i;
  }
  sort(ans + 1, ans + n + 1, my_comp);

  for (int i = 1; i <= n; i++) {
    cout << a[ans[i]] << " " << b[ans[i]] << '\n';
  }

  return 0;
}
