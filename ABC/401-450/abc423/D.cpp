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
ll k, a[int(3e5 + 5)], b[int(3e5 + 5)], c[int(3e5 + 5)];

ll ans[int(3e5 + 5)];
priority_queue<Pll, vector<Pll>, greater<Pll>> togo;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  ll now_time = 0, now_visitor = 0;
  for (int i = 1; i <= n; i++) {
    while (now_visitor + c[i] > k) {
      Pll q = togo.top();
      togo.pop();

      now_time = q.first;
      now_visitor -= q.second;
    }

    now_time = max(now_time, a[i]);
    ans[i] = now_time;
    togo.push({now_time + b[i], c[i]});
    now_visitor += c[i];

    while (!togo.empty()) {
      Pll q = togo.top();
      if (q.first <= now_time) {
        now_visitor -= q.second;
        togo.pop();
      } else {
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
