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
ll r[int(3e5 + 5)];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    que.push({r[i], i});
  }

  ll ans = 0;
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (r[q.second] < q.first) {
      continue;
    }

    ans += r[q.second] - q.first;
    r[q.second] = q.first;
    ll v = q.first;

    for (int i = 1; i + q.second <= n; i++) {
      if (r[i + q.second] <= v + i) {
        break;
      }
      ans += (r[i + q.second] - (v + i));
      r[i + q.second] = v + i;
    }

    for (int i = 1; q.second - i >= 1; i++) {
      if (r[q.second - i] <= v + i) {
        break;
      }
      ans += (r[q.second - i] - (v + i));
      r[q.second - i] = v + i;
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
