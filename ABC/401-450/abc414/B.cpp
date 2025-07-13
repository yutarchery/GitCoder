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
char c[105];
ll now = 0, l[105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> l[i];

    if (now < 100) {
      now += l[i];
    }
  }

  if (now > 100) {
    cout << "Too Long" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < l[i]; j++) {
      cout << c[i];
    }
  }
  cout << endl;

  return 0;
}
