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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m;
int a[int(3e5 + 5)], d[int(3e5 + 5)], b[int(3e5 + 5)];

int ans = 0;
int cnt[int(3e5 + 5)];
priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> d[i] >> b[i];
    que.push({d[i], {a[i], b[i]}});

    if (cnt[a[i]] == 0) {
      ans++;
    }
    cnt[a[i]]++;
  }

  for (int i = 1; i <= m; i++) {
    while (!que.empty()) {
      pair<int, Pii> q = que.top();
      if (q.first != i) {
        break;
      }
      que.pop();

      cnt[q.second.first]--;
      if (cnt[q.second.first] == 0) {
        ans--;
      }
      if (cnt[q.second.second] == 0) {
        ans++;
      }
      cnt[q.second.second]++;
    }

    cout << ans << '\n';
  }

  return 0;
}
