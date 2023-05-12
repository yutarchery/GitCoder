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

int n, k, c[int(1e5 + 5)];
ll ans, p[int(1e5 + 5)];
map<int, bool> used;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  for (int i = 1; i <= n; i++) {
    que.push({p[i], c[i]});
  }

  int cnt = 0;
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (used[q.second]) {
      continue;
    }

    used[q.second] = true;
    ans += q.first;
    cnt++;

    if (cnt == k) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}