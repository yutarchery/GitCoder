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

int n, s[int(2e5 + 5)], t[int(2e5 + 5)];

int cnt_in[int(2e5 + 5)], cnt_out[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    cnt_in[s[i]]++;
    cnt_out[t[i]]++;
  }

  for (int i = 1; i <= int(2e5); i++) {
    cnt_in[i] += cnt_in[i - 1];
    cnt_out[i] += cnt_out[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << (cnt_in[t[i]] - cnt_out[s[i] - 1]) - 1 << (i == n ? '\n' : ' ');
  }

  return 0;
}
