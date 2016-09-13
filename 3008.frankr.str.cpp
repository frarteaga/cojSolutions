/*
Prob: 3008 - Flip Five
Idea: BFS, string for state representation
frankr@coj
*/

#include <bits/stdc++.h>

using namespace std;

char up(char x){
    if(x == '.')
        return '*';
    else
        return '.';
}

string cambia(string a, int x){
    if(x == 0){
        a[0] = up(a[0]);
        a[1] = up(a[1]);
        a[3] = up(a[3]);
    }
    else if(x == 1){
        a[1] = up(a[1]);
        a[0] = up(a[0]);
        a[4] = up(a[4]);
        a[2] = up(a[2]);
    }
    else if(x == 2){
        a[2] = up(a[2]);
        a[1] = up(a[1]);
        a[5] = up(a[5]);
    }
    else if(x == 3){
        a[3] = up(a[3]);
        a[0] = up(a[0]);
        a[4] = up(a[4]);
        a[6] = up(a[6]);
    }
    else if(x == 4){
        a[4] = up(a[4]);
        a[1] = up(a[1]);
        a[3] = up(a[3]);
        a[5] = up(a[5]);
        a[7] = up(a[7]);
    }
    else if(x == 5){
        a[5] = up(a[5]);
        a[2] = up(a[2]);
        a[4] = up(a[4]);
        a[8] = up(a[8]);
    }
    else if(x == 6){
        a[6] = up(a[6]);
        a[3] = up(a[3]);
        a[7] = up(a[7]);
    }
    else if(x == 7){
        a[6] = up(a[6]);
        a[4] = up(a[4]);
        a[8] = up(a[8]);
        a[7] = up(a[7]);
    }
    else if(x == 8){
        a[5] = up(a[5]);
        a[7] = up(a[7]);
        a[8] = up(a[8]);
    }

    return a;
}


map <string, bool>Mk;
map <string, int> C;

int bfs(string fin){
    queue <string> Q;
    Mk.clear();
    C.clear();
    Q.push(".........");
    Mk["........."] = 1;
     C["........."] = 0;

    while(!Q.empty()){
        string nodo = Q.front();
        Q.pop();

        if(nodo == fin)
            return C[nodo];

        for(int i = 0; i < 9; i++){
            string nn = cambia(nodo, i);

            if(!Mk[nn]){
                Q.push(nn);
                Mk[nn] = 1;
                C[nn] = C[nodo] + 1;
            }
        }
    }
    return -1;
}
int main(){
    int cas;
    cin >> cas;
    while(cas--){
        char a;
        string s = "";
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++){
                cin >> a;
                s += a;
            }

        cout << bfs(s) << endl;
    }

    return 0;
}

