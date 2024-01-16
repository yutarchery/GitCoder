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

int n;
ll k;
Mat a;

Mat mat_time(Mat a, Mat b) {
  Mat c;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    c[i].resize(n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mod;
      }
    }
  }

  return c;
}

Mat mat_pow(Mat a, ll num) {
  if (num == 0) {
    Mat c;
    c.resize(n);
    for (int i = 0; i < n; i++) {
      c[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          c[i][j] = 1;
        } else {
          c[i][j] = 0;
        }
      }
    }
    return c;
  }

  if (num % 2 == 0) {
    return mat_pow(mat_time(a, a), num / 2);
  } else {
    return mat_time(a, mat_pow(a, num - 1));
  }
}

int main() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  ll res = 0;
  Mat ans = mat_pow(a, k);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res += ans[i][j];
      res %= mod;
    }
  }
  cout << res << endl;

  return 0;
}
