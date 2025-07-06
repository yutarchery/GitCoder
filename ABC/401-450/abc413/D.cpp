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

int n;
ll a[int(2e5 + 5)];

vector<ll> p, m;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      p.push_back(a[i]);
    } else {
      m.push_back(a[i]);
    }
  }

  if (p.size() == 0 || m.size() == 0) {
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n - 1; i++) {
      if (a[i] * a[i] != a[i - 1] * a[i + 1]) {
        No();
        return;
      }
    }
    Yes();
    return;
  }

  if (abs(int(p.size() - m.size())) > 1) {
    No();
    return;
  }

  sort(p.begin(), p.end());
  sort(m.begin(), m.end(), greater<ll>());

  vector<ll> now;

  if (p.size() != m.size()) {
    if (p.size() > m.size()) {
      for (int i = 0; i < m.size(); i++) {
        now.push_back(p[i]);
        now.push_back(m[i]);
      }
      now.push_back(p[p.size() - 1]);
    } else if (p.size() < m.size()) {
      for (int i = 0; i < p.size(); i++) {
        now.push_back(m[i]);
        now.push_back(p[i]);
      }
      now.push_back(m[m.size() - 1]);
    }

    for (int i = 1; i + 1 <= n - 1; i++) {
      if (now[i] * now[i] != now[i - 1] * now[i + 1]) {
        No();
        return;
      }
    }

    Yes();
    return;
  }

  for (int i = 0; i < m.size(); i++) {
    now.push_back(p[i]);
    now.push_back(m[i]);
  }

  bool flag = true;
  for (int i = 1; i + 1 <= n - 1; i++) {
    if (now[i] * now[i] != now[i - 1] * now[i + 1]) {
      flag = false;
    }
  }

  if (flag) {
    Yes();
    return;
  }

  now.resize(0);
  for (int i = 0; i < m.size(); i++) {
    now.push_back(m[i]);
    now.push_back(p[i]);
  }
  for (int i = 1; i + 1 <= n - 1; i++) {
    if (now[i] * now[i] != now[i - 1] * now[i + 1]) {
      No();
      return;
    }
  }

  Yes();

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();

    p.resize(0);
    m.resize(0);
  }

  return 0;
}
