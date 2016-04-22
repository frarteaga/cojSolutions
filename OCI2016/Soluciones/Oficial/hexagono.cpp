#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;
ull s, p, q, n, m;

ull cn(ull n, ull f){ return (n*2 -1 -f)*f*3;}

void print_sum_of(ull a, ull b){
  ull c=1000000000, al=a%c+b%c;
  a=a/c+b/c+al/c;
  al%=c;
  if (a) {
    char fillchar=cout.fill('0');
    cout<<a<<setw(9)<<al<<endl;
    cout.fill(fillchar);
  }
  else cout<<al<<endl;
}

void taskA(ull n, ull row, ull pos){
  ull frames=row-1, cells=0, i;
  i = n*2 -1 -row;                          // To down
  if (i<frames) frames = i;
  i = pos-1;                                // To left
  if (i<frames) frames = i;
  i=(row<=n?(n-1+row-pos):(3*n-1-row-pos)); // To right
  if (i<frames) frames = i;

  cells=cn(n,frames);
  row-=frames;
  pos-=frames;
  n-=frames;

  if (row==1) cells += pos;
  else if (row==(n*2 -1)) cells += n*4 - 2 -pos;
  else if (pos>1) cells += n - 1 + row;
  else cells += 6*n-4-row;

  if (cells>m) cout<<"0\n";
  else print_sum_of(cells-1,s);
}


void taskB(ull n, ull m){
  ull hi_frames=n,lo_frames=0,c_frame,i,j;
  do {
    c_frame = (hi_frames+lo_frames)/2;
    i=cn(n,c_frame);
    if (i<m)lo_frames=c_frame+1 ;
    else hi_frames=c_frame;
  } while (lo_frames<hi_frames);

  i=m-cn(n,lo_frames-1);
  n-=lo_frames-1;
  j=--i%(--n);

  switch (i/n) {
    case 0: i=0;break;
    case 1: i=j;j+=n;break;
    case 2: i=n+j;j=2*n-j;break;
    case 3: i=2*n,j=n-j;break;
    case 4: n*=2;
    default:i=n-j;j=0;
  }
  cout<<lo_frames+i<<" "<<lo_frames+j<<endl;
}

int main(){

  freopen( "hexagono.in", "r", stdin );
  freopen( "hexagono.out", "w", stdout );

  cin>>n>>m>>s>>p>>q;
  taskA(n,p,q);
  taskB(n,m);

  return 0;
}
