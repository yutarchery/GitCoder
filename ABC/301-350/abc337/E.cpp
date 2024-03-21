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

vector<int> juice[100];

int main() {
  cin >> n;

  int m = 0, num = 1;
  while (num < n) {
    for (int i = 1; i <= n; i++) {
      if ((num & i) != 0) {
        juice[m].push_back(i);
      }
    }
    num *= 2;
    m++;
  }

  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << juice[i].size();
    for (int j : juice[i]) {
      cout << " " << j;
    }
    cout << endl;
  }

  cin >> s;
  int ans = 0;
  num = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      ans += num;
    }
    num *= 2;
  }
  if (ans == 0) {
    cout << num << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
