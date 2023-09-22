#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef long double ld;
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

int n, m;
ll p[int(2e5 + 5)];
Pll ld[int(2e5 + 5)];

priority_queue<ll> rest;
priority_queue<Pll, vector<Pll>, greater<Pll>> que;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    rest.push(p[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> ld[i].first;
  }
  for (int i = 0; i < m; i++) {
    cin >> ld[i].second;
  }
  sort(ld, ld + m, greater<Pll>());

  for (int i = 0; i < m; i++) {
    while (!rest.empty()) {
      ll r = rest.top();
      if (r >= ld[i].first) {
        rest.pop();
        que.push({0, r});
      } else {
        break;
      }
    }

    if (que.empty()) {
      continue;
    }

    Pll q = que.top();
    if (q.first <= ld[i].second) {
      que.pop();
      que.push({ld[i].second, q.second});
    }
  }

  ll ans = 0;
  while (!rest.empty()) {
    ll r = rest.top();
    rest.pop();
    ans += r;
  }

  while (!que.empty()) {
    Pll q = que.top();
    que.pop();
    ans += q.second - q.first;
  }

  cout << ans << endl;

  return 0;
}