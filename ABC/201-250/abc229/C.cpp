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
ll w, a[int(3e5 + 5)], b[int(3e5 + 5)];
priority_queue<Pll> que;

int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    que.push({a[i], b[i]});
  }

  ll ans = 0, rest = w;
  while (!que.empty()) {
    Pll q = que.top();
    que.pop();

    if (q.second >= rest) {
      ans += q.first * rest;
      break;
    } else {
      ans += q.first * q.second;
      rest -= q.second;
    }
  }
  cout << ans << endl;

  return 0;
}
