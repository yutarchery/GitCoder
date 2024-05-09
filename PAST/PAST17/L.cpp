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

int n, a[305][305], b[305][305], ans[605][605];

int main() {
  cin >> n;

  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      ans[i][j] = 1e9;
    }

    ans[i][i] = 0;
    ans[i][i + n] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
      ans[i][j] = a[i][j];
      ans[j][i] = a[i][j];
      ans[i + n][j + n] = a[i][j];
      ans[j + n][i + n] = a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> b[i][j];
      ans[i][j + n] = b[i][j];
      ans[j][i + n] = b[i][j];
    }
  }

  for (int k = 1; k <= 2 * n; k++) {
    for (int i = 1; i <= 2 * n; i++) {
      for (int j = 1; j <= 2 * n; j++) {
        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << min(ans[i][j], ans[i][j + n]);

      if (j == n) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] = a[i][j];
    }
  }

  return 0;
}
