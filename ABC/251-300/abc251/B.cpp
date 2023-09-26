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

int n, w, a[305], ans;
bool used[int(1e6 + 5)];

int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n + 2; i++) {
    for (int j = i + 1; j <= n + 2; j++) {
      for (int k = j + 1; k <= n + 2; k++) {
        int now = a[i] + a[j] + a[k];
        if (now <= w) {
          used[now] = true;
        }
      }
    }
  }

  for (int i = 0; i <= w; i++) {
    if (used[i]) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}