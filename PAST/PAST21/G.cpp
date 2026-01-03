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
ll k, a[int(2e5 + 5)], b[int(2e5 + 5)];

Pli a_idx[int(2e5 + 5)];
vector<int> ans;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    a_idx[i] = {a[i], i};
  }
  sort(a_idx + 1, a_idx + n + 1, greater<Pli>());

  for (int i = 2; i <= n; i++) {
    int idx = a_idx[i].second;
    ll diff = a_idx[i - 1].first - a_idx[i].first;

    if (diff < b[idx] * k) {
      ans.push_back(idx);
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
