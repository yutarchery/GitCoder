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

int n, q, x[int(2e5 + 5)];

bool used[int(2e5 + 5)];
ll cnt[int(2e5 + 5)], sum[int(2e5 + 5)], ans[int(2e5 + 5)];
vector<int> queried[int(2e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
    queried[x[i]].push_back(i);
  }

  for (int i = 1; i <= q; i++) {
    cnt[i] = cnt[i - 1];
    if (used[x[i]]) {
      used[x[i]] = false;
      cnt[i]--;
    } else {
      used[x[i]] = true;
      cnt[i]++;
    }
    sum[i] = sum[i - 1] + cnt[i];
  }

  for (int i = 1; i <= n; i++) {
    if (queried[i].size() % 2 == 1) {
      queried[i].push_back(q + 1);
    }

    for (int j = 0; j < queried[i].size(); j += 2) {
      ans[i] += sum[queried[i][j + 1] - 1] - sum[queried[i][j] - 1];
    }

    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
