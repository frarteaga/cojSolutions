/*alurquiza*/
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10;
bool Mk[SIZE][SIZE][3];
int SOL[SIZE][SIZE];
string basura;

int ident_cuad(int f,int c){
    if(f % 3 == 0)
        f--;
    if(c % 3 == 0)
        c--;
    return f / 3 * 3 + c / 3;
}

void lect2(int ini,int fin,int fila){
    for(int j = ini;j <= fin;j++){
        char ent;
        cin >> ent;
        if(ent == '*')
            SOL[fila][j] = 0;
        else{
            int aux = ent - '0';
            SOL[fila][j] = aux;
            Mk[aux][fila][0] = Mk[aux][j][1] = Mk[aux][ident_cuad(fila,j)][2] = 1;
        }
    }
}

void lect(int ini,int fin){
    for(int i = ini;i <= fin;i++){
        lect2(1,3,i);
        cin >> basura;
        lect2(4,6,i);
        cin >> basura;
        lect2(7,9,i);
    }
}

void imp2(int ini,int fin,int fila){
    cout << SOL[fila][ini];
    cout << ' ' << SOL[fila][ini + 1];
    cout << ' ' << SOL[fila][ini + 2];
}

void imp(int ini,int fin){
    for(int i = ini;i <= fin;i++){
        imp2(1,3,i);
        cout << " " << (char)124 << " ";
        imp2(4,6,i);
        cout << " " << (char)124 << " ";
        imp2(7,9,i);
        cout << '\n';
    }
}

void imprime(){
    imp(1,3);
    cout << "------+-------+------\n";
    imp(4,6);
    cout << "------+-------+------\n";
    imp(7,9);
}

void back(int i,int j){
    if(i == 9 && j == 9){
        imprime();
        return;
    }
    if(j == 9){
        back(i + 1,0);
        return;
    }
    if(SOL[i][j + 1]){
        back(i,j + 1);
        return;
    }
    for(int k = 1;k < SIZE;k++){
        int cuadrado = ident_cuad(i,j + 1);
        if(!Mk[k][i][0] && !Mk[k][j + 1][1] && !Mk[k][cuadrado][2]){
            Mk[k][i][0] = Mk[k][j + 1][1] = Mk[k][cuadrado][2] = 1;
            SOL[i][j + 1] = k;
            back(i,j + 1);
            SOL[i][j + 1] = 0;
            Mk[k][i][0] = Mk[k][j + 1][1] = Mk[k][cuadrado][2] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("SUDOKOS.IN","r",stdin);
//    freopen("SUDOKOS.OUT","w",stdout);

    lect(1,3);
    cin >> basura;
    lect(4,6);
    cin >> basura;
    lect(7,9);

    back(1,0);

    return 0;
}
