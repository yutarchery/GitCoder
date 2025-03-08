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

int n, a[int(1 << 16) + 5];

vector<int> winners[20];
int ans[int(1 << 16) + 5];

int main() {
  cin >> n;
  for (int i = 1; i <= (1 << n); i++) {
    cin >> a[i];
    winners[0].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < winners[i].size(); j += 2) {
      int u = winners[i][j], v = winners[i][j + 1];
      if (a[u] > a[v]) {
        swap(u, v);
      }

      ans[u]++;
      ans[v]++;
      winners[i + 1].push_back(v);
    }
  }

  for (int i = 1; i <= (1 << n); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
