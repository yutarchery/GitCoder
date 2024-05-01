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
string s;
Pii p[105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    p[i].second = n - i;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'o') {
        p[i].first++;
      }
    }
  }
  sort(p + 1, p + n + 1, greater<Pii>());

  for (int i = 1; i <= n; i++) {
    cout << n - p[i].second;
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
