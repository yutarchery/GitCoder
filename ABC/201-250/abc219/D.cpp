#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int n, x, y, a[305], b[305], ans[305][305][305];
bool visited[305][305][305];

int main(){
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  fill((int*)ans, (int*)(ans + n + 1), 1e9);

  ans[0][0][0] = 0;
  visited[0][0][0] = true;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= x; j++){
      for (int k = 0; k <= y; k++){
        if (visited[i - 1][j][k]){
          visited[i][j][k] = true;
          ans[i][j][k] = min(ans[i][j][k], ans[i - 1][j][k]);

          visited[i][min(j + a[i], x)][min(k + b[i], y)] = true;
          ans[i][min(j + a[i], x)][min(k + b[i], y)] = min(ans[i][min(j + a[i], x)][min(k + b[i], y)], ans[i - 1][j][k] + 1);
        }
      }
    }
  }

  if (ans[n][x][y] == 1e9) {
    cout << -1 << endl;
  }else{
    cout << ans[n][x][y] << endl;
  }
  
  return 0;
}