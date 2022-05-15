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

int n, a[int(2e5 + 5)], q, l, r, x;
vector<int> idx[int(2e5 + 5)];

int indexSearch(int place) {

  int left = 0, right = idx[x].size();

  while (right - left > 1) {
    int mid = (left + right) / 2;

    if (idx[x][mid] <= place) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return left;
}

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    idx[i].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    idx[i].push_back(mod);
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r >> x;
    cout << indexSearch(r) - indexSearch(l - 1) << endl;
  }

  return 0;
}