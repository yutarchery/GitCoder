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

ll a[2], b[2], c[2], d[2];
ll dist1[2], dist2[2];

bool paralell(int idx = 0) {
  ll num1 = (b[idx] - d[idx]) * a[1 - idx] + (c[idx] - a[idx]) * b[1 - idx] +
            (a[idx] * d[idx] - b[idx] * c[idx]);
  ll num2 = (b[idx] - d[idx]) * c[1 - idx] + (c[idx] - a[idx]) * d[1 - idx] +
            (a[idx] * d[idx] - b[idx] * c[idx]);

  return num1 == 0 && num2 == 0;
}

bool judge(int idx) {
  ll num1 = (b[idx] - d[idx]) * a[1 - idx] + (c[idx] - a[idx]) * b[1 - idx] +
            (a[idx] * d[idx] - b[idx] * c[idx]);
  ll num2 = (b[idx] - d[idx]) * c[1 - idx] + (c[idx] - a[idx]) * d[1 - idx] +
            (a[idx] * d[idx] - b[idx] * c[idx]);

  return num1 * num2 <= 0;
}

int main() {
  for (int i = 0; i < 2; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];

    dist1[i] = (a[i] + 1000) + (b[i] + 1000);
    dist2[i] = (c[i] + 1000) + (d[i] + 1000);

    if (dist1[i] >= dist2[i]) {
      swap(dist1[i], dist2[i]);
      swap(a[i], c[i]);
      swap(b[i], d[i]);
    }
  }

  if (paralell()) {
    if (dist1[0] <= dist1[1] && dist1[1] <= dist2[0]) {
      Yes();
    } else if (dist1[1] <= dist1[0] && dist1[0] <= dist2[1]) {
      Yes();
    } else {
      No();
    }
  } else if (judge(0) && judge(1)) {
    Yes();
  } else {
    No();
  }

  return 0;
}
