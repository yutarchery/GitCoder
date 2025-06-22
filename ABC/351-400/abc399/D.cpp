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

int n, a[int(4e5 + 5)];

void solve() {
  cin >> n;

  map<int, int> not_used;
  Pii p[n + 1];

  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    if (a[i] == a[i - 1]) {
      not_used[a[i]] = true;
    }

    if (p[a[i]].first == 0) {
      p[a[i]].first = i;
    } else {
      p[a[i]].second = i;
    }
  }

  int ans = 0;
  map<Pii, bool> visited;
  for (int i = 1; i + 1 <= 2 * n; i++) {
    if (!not_used[a[i]] && !not_used[a[i + 1]]) {
      Pii now = {min(a[i], a[i + 1]), max(a[i], a[i + 1])};
      if (visited[now]) {
        continue;
      }

      visited[now] = true;
      vector<int> v;
      v.push_back(p[a[i]].first);
      v.push_back(p[a[i]].second);
      v.push_back(p[a[i + 1]].first);
      v.push_back(p[a[i + 1]].second);
      sort(v.begin(), v.end());

      if (v[1] - v[0] == 1 && v[3] - v[2] == 1) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
