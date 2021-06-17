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

int H, W, Q;
bool used[2005][2005];

vector <int> Graph[int(5e6 + 5)];
int Group[int(5e6 + 5)];

int di[4] = {0, 1, 0, -1}, dj[4] = {-1, 0, 1, 0};

int find(int num){
  if (num == Group[num]) return num;
  else return Group[num] = find(Group[num]);
}

int add(){
  int R, C; 
  cin >> R >> C;
  used[R][C] = true;

  int num = (R - 1) * W + C;
  for (int k = 0; k < 4; k++){
    int I = R + di[k], J = C + dj[k];
    if (used[I][J]){
      num = min(num, find((I - 1) * W + J));
    }
  }

  Group[(R - 1) * W + C] = num;
  for (int k = 0; k < 4; k++){
    int I = R + di[k], J = C + dj[k];
    if (used[I][J]){
      Group[(I - 1) * W + J] = num;
    }
  }
  return 0;
}

bool check(){
  int Ra, Ca, Rb, Cb;
  cin >> Ra >> Ca >> Rb >> Cb;

  if (!used[Ra][Ca] || !used[Rb][Cb]) return false;

  int A = (Ra - 1) * W + Ca, B = (Rb - 1) * W + Cb;
  return find(A) == find(B);
}

int main(){
  cin >> H >> W >> Q;

  for (int i = 1; i <= H * W; i++){
    Group[i] = i;
  }

  for (int i = 0; i < Q; i++){
    int q; cin >> q;
    if (q == 1) add();
    else {
      if (check()) Yes();
      else No();
    }
  }

  return 0;
}