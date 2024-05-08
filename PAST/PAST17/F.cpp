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

int n, p[int(2e5 + 5)];
vector<int> children[int(2e5 + 5)];
string s[int(2e5 + 5)];

queue<int> que;
int cnt[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    children[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] != "+" && s[i] != "x") {
      cnt[p[i]]++;
      if (cnt[p[i]] == 2) {
        que.push(p[i]);
      }

      for (int j = 0; j < s[i].length(); j++) {
        ans[i] *= 10;
        ans[i] += s[i][j] - '0';
      }
      ans[i] %= MOD2;
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    ans[q] = ans[children[q][0]];
    if (s[q] == "+") {
      ans[q] += ans[children[q][1]];
    } else {
      ans[q] *= ans[children[q][1]];
    }
    ans[q] %= MOD2;

    cnt[p[q]]++;
    if (cnt[p[q]] == 2) {
      que.push(p[q]);
    }
  }
  cout << ans[1] << endl;

  return 0;
}
