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
ll x;
string s;
char c[int(1e6 + 5)];

int main() {
  cin >> n >> x;
  cin >> s;

  int now_idx = 0;
  for (int i = 0; i < n; i++) {
    if (now_idx == 0) {
      c[now_idx] = s[i];
      now_idx++;
      continue;
    }

    if (s[i] == 'U' && c[now_idx - 1] != 'U') {
      now_idx--;
      c[now_idx] = 0;
    } else {
      c[now_idx] = s[i];
      now_idx++;
    }
  }

  for (int i = 0; i < now_idx; i++) {
    if (c[i] == 'U') {
      x /= 2;
    } else if (c[i] == 'L') {
      x = x * 2;
    } else if (c[i] == 'R') {
      x = x * 2 + 1;
    }
  }
  cout << x << endl;

  return 0;
}
