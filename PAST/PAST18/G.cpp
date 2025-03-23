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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
int cnt_a[int(2e5 + 5)], cnt_b[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt_a[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    cnt_b[b[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt_a[i] != cnt_b[i]) {
      No();
      return 0;
    }
  }

  int min_i = n + 1, max_i = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      min_i = min(min_i, i);
      max_i = max(max_i, i);
    }
  }

  if (min_i == n + 1) {
    Yes();
    return 0;
  }

  if (min_i + 1 == max_i) {
    for (int i = 1; i + 1 <= n; i++) {
      if (a[i] == a[i + 1]) {
        Yes();
        return 0;
      }
    }
    swap(a[min_i], a[min_i + 1]);
    for (int i = 1; i + 1 <= n; i++) {
      if (a[i] == a[i + 1]) {
        Yes();
        return 0;
      }
    }
    No();
    return 0;
  }

  if (min_i + 2 == max_i) {
    swap(a[min_i], a[min_i + 1]);
    swap(a[max_i - 1], a[max_i]);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        flag = false;
      }
    }
    if (flag) {
      Yes();
      return 0;
    }

    swap(a[max_i - 1], a[max_i]);
    swap(a[min_i], a[min_i + 1]);
    swap(a[max_i - 1], a[max_i]);
    swap(a[min_i], a[min_i + 1]);
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        No();
        return 0;
      }
    }
    Yes();
    return 0;
  }

  swap(a[min_i], a[min_i + 1]);
  swap(a[max_i - 1], a[max_i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
