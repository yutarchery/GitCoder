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
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int H, W, A, B;
bool used[16][16];

int dfs(int h, int w, int a){
  if (h == H - 1 && w == W - 1){
    if (a == 0) return 1;
    else return 0;
  }

  if (w == W) return dfs(h + 1, 0, a);
  if (used[h][w]) return dfs(h, w + 1, a);

  int res = dfs(h, w + 1, a);
  if (!used[h][w + 1] && w + 1 < W && a > 0){
    used[h][w] = true; used[h][w + 1] = true;
    res += dfs(h, w + 1, a - 1);
    used[h][w] = false; used[h][w + 1] = false;
  }
  if (!used[h + 1][w] && h + 1 < H && a > 0){
    used[h][w] = true; used[h + 1][w] = true;
    res += dfs(h, w + 1, a - 1);
    used[h][w] = false; used[h + 1][w] = false;
  }

  return res;
}

int main(){
  cin >> H >> W >> A >> B;
  cout << dfs(0, 0, A) << endl;

  return 0;
}