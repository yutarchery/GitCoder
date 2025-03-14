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

ll n, q, num, a, b;
int row[int(1e5 + 5)], column[int(1e5 + 5)];
bool t = false;

ll solve(ll r, ll c) { return n * (r - 1) + c - 1; }

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    row[i] = i;
    column[i] = i;
  }

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> a >> b;
      if (t) {
        swap(column[a], column[b]);

      } else {
        swap(row[a], row[b]);
      }
    } else if (num == 2) {
      cin >> a >> b;
      if (t) {
        swap(row[a], row[b]);
      } else {
        swap(column[a], column[b]);
      }
    } else if (num == 3) {
      t = !t;
    } else {
      cin >> a >> b;
      if (t) {
        cout << solve(row[b], column[a]) << endl;
      } else {
        cout << solve(row[a], column[b]) << endl;
      }
    }
  }

  return 0;
}
