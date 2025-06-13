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
string s, x;

bool visited[int(2e5 + 5)][7], res[int(2e5 + 5)][7];

bool solve(int idx, int num) {
  if (idx == n) {
    return num % 7 == 0;
  }

  if (visited[idx][num]) {
    return res[idx][num];
  }

  visited[idx][num] = true;

  if (x[idx] == 'A') {
    bool ans = true;
    ans &= solve(idx + 1, num * 10 % 7);
    ans &= solve(idx + 1, (num * 10 + s[idx] - '0') % 7);
    return res[idx][num] = ans;
  } else {
    bool ans = false;
    ans |= solve(idx + 1, num * 10 % 7);
    ans |= solve(idx + 1, (num * 10 + s[idx] - '0') % 7);
    return res[idx][num] = ans;
  }
}

int main() {
  cin >> n;
  cin >> s;
  cin >> x;

  cout << (solve(0, 0) ? "Takahashi\n" : "Aoki\n");

  return 0;
}
