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
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
int cnt[int(2e5 + 5)];

priority_queue<Pli, vector<Pli>, greater<Pli>> que;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<ll>());

  for (int i = 1; i <= m; i++) {
    que.push({0, i});
  }
  for (int i = 1; i <= n; i++) {
    Pli q = que.top();
    que.pop();
    b[q.second] += a[i];
    cnt[q.second]++;

    if (cnt[q.second] <= 1) {
      que.push({a[i], q.second});
    }
  }

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += b[i] * b[i];
  }
  cout << ans << endl;

  return 0;
}
