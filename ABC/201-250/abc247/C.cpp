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

bool visited[20];
string ans[20];

string solve(int n) {
  if (visited[n]) {
    return ans[n];
  }

  visited[n] = true;
  char now = '0' + n;
  if (n == 1) {
    return ans[n] = now;
  } else {
    return ans[n] = solve(n - 1) + now + solve(n - 1);
  }
}

int main() {
  int n;
  cin >> n;

  string res = solve(n);
  for (int i = 0; i < res.length(); i++) {
    cout << res[i] - '0' << (i == res.length() - 1 ? '\n' : ' ');
  }

  return 0;
}
