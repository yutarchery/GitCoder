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
Pii a[int(3e5 + 5)];
int b[int(3e5 + 5)];

int lis[int(3e5 + 5)];
void make_lis(int c) {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (lis[mid] < c) {
      l = mid;
    } else {
      r = mid;
    }
  }

  lis[r] = c;
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  fill(lis + 1, lis + n + 2, 1e9);
  for (int i = 0; i < n; i++) {
    make_lis(b[a[i].second]);
  }

  for (int i = 1; i <= n; i++) {
    if (lis[i + 1] == int(1e9)) {
      cout << n + i << endl;
      break;
    }
  }

  return 0;
}