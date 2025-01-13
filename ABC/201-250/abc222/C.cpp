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

int n, m;
char a[105][105];

int wins[105];
Pii now[105];

bool judge(char a1, char a2) {
  if (a1 == 'G' && a2 == 'C') {
    return true;
  } else if (a1 == 'C' && a2 == 'P') {
    return true;
  } else if (a1 == 'P' && a2 == 'G') {
    return true;
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
    now[i] = {0, -1 * i};
  }

  for (int j = 1; j <= m; j++) {
    sort(now + 1, now + 2 * n + 1);
    for (int i = 1; i <= 2 * n; i += 2) {
      int f = -1 * now[i].second, s = -1 * now[i + 1].second;
      if (a[f][j] == a[s][j]) {
        continue;
      }
      if (judge(a[f][j], a[s][j])) {
        wins[f]++;
      } else {
        wins[s]++;
      }
    }

    for (int i = 1; i <= 2 * n; i++) {
      now[i] = {wins[i], -1 * i};
    }
  }

  sort(now + 1, now + 2 * n + 1, greater<Pii>());
  for (int i = 1; i <= 2 * n; i++) {
    cout << -1 * now[i].second << endl;
  }

  return 0;
}
