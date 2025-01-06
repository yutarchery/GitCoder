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

int n, m, order[15];
string s[15], t;
map<string, bool> visited;

vector<vector<int>> underscores;
string ans = "";

void prepare(int sz, int rest, int mx = 1, vector<int> now = {}) {
  if (int(now.size()) == sz) {
    if (rest >= 0) {
      underscores.push_back(now);
    }
    return;
  }

  for (int i = mx; i <= rest; i++) {
    vector<int> next = now;
    next.push_back(i);
    prepare(sz, rest - i, max(i, mx), next);
  }
  return;
}

void solve() {
  for (vector<int> v : underscores) {
    do {
      string now = "";
      for (int i = 0; i < n; i++) {
        now += s[order[i]];
        if (i < n - 1) {
          for (int j = 0; j < v[i]; j++) {
            now += "_";
          }
        }
      }

      if (!visited[now] && 3 <= now.length() && now.length() <= 16 &&
          now.back() != '_') {
        ans = now;
        return;
      }
    } while (next_permutation(v.begin(), v.end()));
  }

  return;
}

int main() {
  cin >> n >> m;
  int rest = 16;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    order[i] = i;
    rest -= int(s[i].length());
  }
  prepare(n - 1, rest);

  for (int i = 0; i < m; i++) {
    cin >> t;
    visited[t] = true;
  }

  do {
    solve();
    if (ans != "") {
      cout << ans << endl;
      return 0;
    }
  } while (next_permutation(order, order + n));

  cout << -1 << endl;
  return 0;
}
