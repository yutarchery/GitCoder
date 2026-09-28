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

int q;
string s, t;
int l[int(2e5 + 5)], r[int(2e5 + 5)];

set<int> starts;

void search() {
  for (int i = 0; i + (t.length() - 1) < s.length(); i++) {
    bool flag = true;
    for (int j = 0; j < t.length(); j++) {
      if (s[i + j] != t[j]) {
        flag = false;
      }
    }

    if (flag) {
      starts.insert(i + 1);
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> q;
  cin >> s;
  cin >> t;
  search();

  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];

    if (r[i] - (l[i] - 1) < t.length()) {
      No();
      continue;
    }

    auto iter = starts.lower_bound(l[i]);
    if (iter == starts.end()) {
      No();
      continue;
    }

    int now_start = *iter;
    int now_end = now_start + t.length() - 1;
    if (now_end <= r[i]) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}
