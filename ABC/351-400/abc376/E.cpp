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

int n, k;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
Pll p[int(2e5 + 5)];

ll solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    p[i] = {a[i], b[i]};
  }
  sort(p + 1, p + n + 1);

  ll sum = 0;
  priority_queue<ll> que;
  for (int i = 1; i <= k; i++) {
    sum += p[i].second;
    que.push(p[i].second);
  }
  ll ans = sum * p[k].first;

  for (int i = k + 1; i <= n; i++) {
    ll q = que.top();
    que.pop();
    sum -= q;

    sum += p[i].second;
    que.push(p[i].second);
    ans = min(ans, sum * p[i].first);
  }

  return ans;
}

void reset() {
  fill(a + 1, a + n + 1, 0);
  fill(b + 1, b + n + 1, 0);
  fill(p + 1, p + n + 1, make_pair(0, 0));
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
