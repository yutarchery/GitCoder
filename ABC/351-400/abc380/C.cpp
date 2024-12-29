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

int n, k, cnt;
char s[int(5e5 + 5)];
vector<char> ans[int(5e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int idx = 0;
  ans[idx].push_back(s[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      idx++;
    }
    ans[idx].push_back(s[i]);
  }

  int cnt = 0;
  for (int i = 0; i <= idx; i++) {
    if (ans[i][0] == '1') {
      cnt++;
      if (cnt == k) {
        swap(ans[i], ans[i - 1]);
        break;
      }
    }
  }

  for (int i = 0; i <= idx; i++) {
    for (char c : ans[i]) {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}
