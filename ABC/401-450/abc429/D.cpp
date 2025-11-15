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

ll n, m, c, a[int(5e5 + 5)];
vector<ll> val;

map<ll, bool> visited;
map<ll, int> idx;

int sz;
ll cnt[int(2e6 + 5)];

int main() {
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    if (!visited[a[i]]) {
      visited[a[i]] = true;
      val.push_back(a[i]);
    }
  }

  sz = val.size();
  sort(val.begin(), val.end());

  for (int i = 0; i < sz; i++) {
    idx[val[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cnt[idx[a[i]]]++;
  }
  for (int i = 0; i < sz; i++) {
    cnt[i + sz] = cnt[i];
  }

  ll sum = 0;
  int r_idx = 0;
  for (int i = 0; i < 2 * sz; i++) {
    sum += cnt[i];
    if (sum >= c) {
      r_idx = i;
      break;
    }
  }

  ll ans = (val[0] + m - val[sz - 1]) * sum;
  for (int i = 1; i < sz; i++) {
    sum -= cnt[i - 1];
    while (sum < c) {
      r_idx++;
      sum += cnt[r_idx];
    }
    ans += (val[i] - val[i - 1]) * sum;
  }
  cout << ans << endl;

  return 0;
}
