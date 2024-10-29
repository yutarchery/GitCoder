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

int n, m, t[int(2e5 + 5)];
ll x[int(2e5 + 5)];

priority_queue<ll> can, opener;
priority_queue<ll, vector<ll>, greater<ll>> que;

int main() {
  cin >> n >> m;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
    if (t[i] == 0) {
      que.push(x[i]);
      sum += x[i];
    } else if (t[i] == 1) {
      can.push(x[i]);
    } else {
      opener.push(x[i]);
    }
  }

  while (que.size() > m) {
    sum -= que.top();
    que.pop();
  }
  ll ans = sum;

  while (m--) {
    if (!opener.empty()) {
      ll o = opener.top();
      opener.pop();

      while (o--) {
        if (can.empty()) {
          break;
        }

        ll c = can.top();
        can.pop();
        sum += c;
        que.push(c);
      }
    }

    while (que.size() > m) {
      sum -= que.top();
      que.pop();
    }

    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
