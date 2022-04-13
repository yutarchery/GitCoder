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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, a[205], b[205], c[205];
int minIndex = -1;

int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    if (minIndex == -1 && a[i] != 0) {
      minIndex = i;
    }
  }

  for (int i = 0; i <= n + m; i++) {
    cin >> c[i];
  }

  for (int k = minIndex; k <= m + minIndex; k++) {
    int rest = c[k];

    for (int i = 0; i <= k; i++) {
      rest -= a[i] * b[k - i];
    }
    b[k - minIndex] = rest / a[minIndex];
  }

  for (int i = 0; i < m; i++)
    cout << b[i] << " ";
  cout << b[m] << endl;

  return 0;
}