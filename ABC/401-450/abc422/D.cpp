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

int n, k, ans[(1 << 21)];
vector<int> order[21];
bool visited[(1 << 21)];

int main() {
  cin >> n >> k;
  fill(ans + 1, ans + (1 << n) + 1, k / (1 << n));

  order[1] = {1, 2};
  for (int i = 2; i <= n; i++) {
    for (int j : order[i - 1]) {
      order[i].push_back(j);
      order[i].push_back(j + (1 << (i - 1)));
    }
  }

  int rest = k % (1 << n);
  for (int j = 0; j < rest; j++) {
    ans[order[n][j]]++;
  }

  cout << (rest == 0 ? 0 : 1) << endl;
  for (int i = 1; i <= (1 << n); i++) {
    cout << ans[i] << (i == (1 << n) ? '\n' : ' ');
  }

  return 0;
}
