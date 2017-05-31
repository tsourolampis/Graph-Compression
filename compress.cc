#include <cstdio>
#include <cstring>
#include "IO.h"
#include <algorithm>
using namespace std;

// Graph compression
// 


typedef long long ll;
typedef double T;

const int MAXV =            20000000;
const int MAXE =           220000000;

int *eList0 = new(int[MAXE]);
int *eList1 = new(int[MAXE]);
int eTotal;

int nextE[MAXE];
int E, V;
int eStart[MAXV];
const int NOEDGE = -1;
char seen[MAXV];
int degree[MAXV];
char countAfter[MAXV];

int answer;

void clearEdge() {
  eTotal = 0;
  for(int i = 0; i < V; ++i) {
    eStart[i] = NOEDGE;
  }
}
 
inline void addEdge(int u, int v) {
  if(! (u!=v && 0 <= u && u < V && 0 <= v && v < V) ) return;
  if(u > v) swap(u, v);
  eList0[eTotal] = u;
  eList1[eTotal] = v;
  nextE[eTotal] = eStart[u];
  eStart[u] = eTotal;
  eTotal++; 
}

void datain() {
  int u, v;
  IO::read(V);
  IO::read(E);
  clearEdge();
  for(int i = 0; i < E; ++i) {
    IO::read(u);
    IO::read(v);
    addEdge(u, v);
  }
  E = eTotal;
}

int neighbor[MAXV], t;

int main(){
  datain();
  printf("%d\n", V);
  for(int u = 0; u < V; ++u) {
    t = 0;
    for(int p = eStart[u]; p != NOEDGE; p = nextE[p]) {
      neighbor[t++] = eList1[p];
    }
    sort(neighbor, neighbor+t);

    printf("%d\n", t);
    for(int i = 0; i < t; ++i)
      printf("%d\n", neighbor[i]);
  }
  return 0;
}

