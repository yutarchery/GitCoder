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

int n, m;
ll t, w, s, ans[int(2e5 + 5)];

priority_queue<Pii, vector<Pii>, greater<Pii>> waiting;
priority_queue<int, vector<int>, greater<int>> available;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    available.push(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> t >> w >> s;

    while (!waiting.empty()) {
      Pii q = waiting.top();
      if (q.first > t) {
        break;
      }
      waiting.pop();
      available.push(q.second);
    }

    if (available.empty()) {
      continue;
    }

    ans[available.top()] += w;
    waiting.push({t + s, available.top()});
    available.pop();
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}