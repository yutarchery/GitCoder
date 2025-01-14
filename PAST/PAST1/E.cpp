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

int n, q, num, a, b;
bool now[105][105];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> num;

    if (num == 1) {
      cin >> a >> b;
      now[a][b] = true;
    } else if (num == 2) {
      cin >> a;
      for (int j = 1; j <= n; j++) {
        if (now[j][a]) {
          now[a][j] = true;
        }
      }
    } else {
      cin >> a;
      queue<int> que;
      for (int j = 1; j <= n; j++) {
        if (now[a][j]) {
          que.push(j);
        }
      }

      while (!que.empty()) {
        int q = que.front();
        que.pop();
        for (int j = 1; j <= n; j++) {
          if (now[q][j] && a != j) {
            now[a][j] = true;
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (now[i][j]) {
        cout << 'Y';
      } else {
        cout << 'N';
      }
    }
    cout << endl;
  }

  return 0;
}
