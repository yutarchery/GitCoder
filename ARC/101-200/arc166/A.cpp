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
char x[int(2e5 + 5)], y[int(2e5 + 5)];

int s_a[int(2e5 + 5)], t_a[int(2e5 + 5)];

bool judge(string s, string t) {
  fill(s_a, s_a + int(s.length()), 0);
  fill(t_a, t_a + int(t.length()), 0);

  int cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'A') {
      cnt_a++;
      t_a[i]++;
    } else {
      cnt_b++;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      cnt_a--;
      s_a[i]++;
    } else if (s[i] == 'B') {
      cnt_b--;
    }
  }

  if (cnt_a < 0 || cnt_b < 0) {
    return false;
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'C') {
      if (cnt_a > 0) {
        cnt_a--;
        s[i] = 'A';
        s_a[i]++;
      } else {
        cnt_b--;
        s[i] = 'B';
      }
    }
  }

  for (int i = 1; i < s.length(); i++) {
    s_a[i] += s_a[i - 1];
  }
  for (int i = 1; i < t.length(); i++) {
    t_a[i] += t_a[i - 1];
  }

  for (int i = 0; i < s.length(); i++) {
    if (s_a[i] < t_a[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> y[i];
  }

  string s = "", t = "";
  for (int i = 1; i <= n; i++) {
    if (y[i] == 'C') {
      if (x[i] != 'C') {
        No();
        return;
      }

      if (!judge(s, t)) {
        No();
        return;
      }

      s = "";
      t = "";
    } else {
      s += x[i];
      t += y[i];
    }
  }

  judge(s, t) ? Yes() : No();
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
