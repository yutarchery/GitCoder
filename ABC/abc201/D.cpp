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

int H, W;
char A[2005][2005];
bool visited[2005][2005];
int score[2005][2005];
int di[2] = {0, 1}, dj[2] = {1, 0};

int solve(int h, int w, bool turn){
  if (h == H - 1 && w == W - 1){
    return 0;
  }

  if (visited[h][w]) return score[h][w];
  visited[h][w] = true;
  if (turn){
    int ans = -1e9;
    if (h + 1 < H){
      if (A[h + 1][w] == '+') ans = max(ans, solve(h + 1, w, false) + 1);
      else ans = max(ans, solve(h + 1, w, false) - 1);
    }
    if (w + 1 < W){
      if (A[h][w + 1] == '+') ans = max(ans, solve(h, w + 1, false) + 1);
      else ans = max(ans, solve(h, w + 1, false) - 1);
    }
    return score[h][w] = ans;
  }else{
    int ans = 1e9;
    if (h + 1 < H){
      if (A[h + 1][w] == '+') ans = min(ans, solve(h + 1, w, true) - 1);
      else ans = min(ans, solve(h + 1, w, true) + 1);
    }
    if (w + 1 < W){
      if (A[h][w + 1] == '+') ans = min(ans, solve(h, w + 1, true) - 1);
      else ans = min(ans, solve(h, w + 1, true) + 1);
    }
    return score[h][w] = ans;
  }
}

int main(){
  cin >> H >> W;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
    }
  }
  
  int ans = solve(0, 0, 1);
  if (ans > 0) cout << "Takahashi" << endl;
  else if (ans == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;

  return 0;
}