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

int N;
vector <int> Graph[int(1e5 + 5)];

bool visited[int(1e5 + 5)];
int dist[int(1e5 + 5)];

int calcDist(int startEdge){
  fill(visited, visited + N + 1, false);
  fill(dist, dist + N + 1, 0); 
  visited[startEdge] = true;

  queue <int> que;
  que.push(startEdge);

  while (!que.empty()){
    int nowEdge = que.front(); que.pop();
    for (int nextEdge : Graph[nowEdge]){
      if (visited[nextEdge]) continue;
      visited[nextEdge] = true;
      dist[nextEdge] = dist[nowEdge] + 1;
      que.push(nextEdge);
    }
  }
  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N - 1; i++){
    int A, B; cin >> A >> B;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }

  calcDist(1);
  int startEdge = 0, maxDist = 0;
  for (int i = 1; i <= N; i++){
    if (maxDist <= dist[i]){
      startEdge = i;
      maxDist = dist[i];
    }
  }
  calcDist(startEdge);

  int ans = 0;
  for (int i = 1; i <= N; i++){
    ans = max(ans, dist[i]);
  }
  cout << ans + 1 << endl;

  return 0;
}