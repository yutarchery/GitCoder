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
char a[int(4e5 + 5)], b[int(4e5 + 5)], c[int(4e5 + 5)];

vector<int> zero_a, zero_b, zero_c;
vector<int> zeros;

bool is_zero[int(4e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    if (a[i] == '0') {
      zero_a.emplace_back(i);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    cin >> b[i];
    if (b[i] == '0') {
      zero_b.emplace_back(i);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    cin >> c[i];
    if (c[i] == '0') {
      zero_c.emplace_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    int now[3] = {zero_a[i], zero_b[i], zero_c[i]};
    sort(now, now + 3);
    zeros.emplace_back(now[1]);
    is_zero[now[1]] = true;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(zeros[i] - zero_a[i]);
    ans += abs(zeros[i] - zero_b[i]);
    ans += abs(zeros[i] - zero_c[i]);
  }
  cout << ans << '\n';

  for (int i = 1; i <= 2 * n; i++) {
    cout << (is_zero[i] ? '0' : '1');
  }
  cout << '\n';

  return 0;
}
