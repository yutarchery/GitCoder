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

int n, p[405];

int cnt_a = 0;
bool is_ng[405];

vector<pair<char, int>> ans;

void align_ngs() {
  for (int i = 1; i <= n; i++) {
    if (is_ng[i] == false) {
      continue;
    }

    int now = i;
    while (true) {
      if (now - 2 >= 1 && is_ng[now] && !is_ng[now - 2]) {
        ans.push_back({'B', now - 2});
        swap(is_ng[now], is_ng[now - 2]);
        swap(p[now], p[now - 2]);
        now -= 2;
      } else {
        break;
      }
    }
  }

  for (int i = 1; i + 1 <= n; i++) {
    if (is_ng[i] && is_ng[i + 1]) {
      ans.push_back({'A', i});
      swap(p[i], p[i + 1]);
      is_ng[i] = false;
      is_ng[i + 1] = false;
    }
  }

  return;
}

void solve() {
  for (int k = 1; k <= n; k++) {
    int now;
    for (int i = 1; i <= n; i++) {
      if (p[i] == k) {
        now = i;
        break;
      }
    }

    while (k < now) {
      ans.push_back({'B', now - 2});
      swap(p[now - 2], p[now]);
      now -= 2;
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];

    if (i % 2 != p[i] % 2) {
      cnt_a++;
      is_ng[i] = true;
    }
  }

  align_ngs();
  solve();

  cout << ans.size() << '\n';
  for (pair<char, int> a : ans) {
    cout << a.first << " " << a.second << '\n';
  }

  return 0;
}
