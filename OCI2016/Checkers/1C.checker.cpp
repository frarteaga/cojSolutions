/*
CNC2016-1C Checker
frankr@coj
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 201;

int N, M, K;
string A[MAXN];

int ejecuta(string CMD){
    int x = 1;
    int y = 1;
    int P = 0;
    int Premios = 0;
    while (x <= N && y <= M){
        if (A[x][y] == '#'){
            cout << "checker log: Llego a casilla peligrsa ):" << endl;
            return -1;
        }
        Premios += A[x][y] - '0';
        if (CMD[P] == 'R')
            y++;
        else
            x++;
        P = (P + 1) % CMD.length();
    }
    return Premios;
}

int main(int args, char * argv[])
{
    ifstream fin("robot.in");
    if (args != 3){
        cout << "Error en la linea de comandos\n";
        cout << "[program checker] [oficialOutput] [contestantOutput]" << endl;
        return 200;
    }
    string outFileName = string(argv[1]);
    ifstream fout(outFileName.c_str());
    string contestantFileName = string(argv[2]);
    ifstream fcon(contestantFileName.c_str());

    FILE *fp = fopen("puntuacion.txt", "w");
    fprintf(fp, "0.0\n");
    fclose(fp);

    if (fin.bad() || fout.bad() || fcon.bad() || fin.fail() || fout.fail() || fcon.fail()){
        cout << "Algo mal con los ficheros de datos\n";
        cout << fin.bad() << fout.bad() << fcon.bad() << fin.fail() << fout.fail() << fcon.fail() << endl;
        return 101;
    }

    string CMD = "";
    fcon >> CMD;

    fin >> N >> M >> K;

    if (K < (int)CMD.length()){
        cout << "checker log: La cadena de comandos muy larga" << endl;
        return 102;
    }

    if (0 == (int)CMD.length()){
        cout << "checker log: La cadena de comandos es vacia" << endl;
        return 102;
    }

    string tmp;
    if (fcon >> tmp){
        cout << "checker log: La cadena de comandos no contigua" << endl;
        return 102;
    }

    if (count(CMD.begin(), CMD.end(), 'R') + count(CMD.begin(), CMD.end(), 'D') < (int)CMD.length()){
        cout << "checker log: La cadena contiene caracteres no validos" << endl;
        return 102;
    }

    for (int i = 1 ; i <= N ; i++){
        fin >> A[i];
        A[i] = " " + A[i];
    }

    double PremiosConc = ejecuta(CMD);
    if (PremiosConc < 0)
        return 102;
    cout << "ckecker log: robot del concursante logra salir" << endl;
    string cmd;
    fout >> cmd;
    double PremiosOK = ejecuta(cmd);
    double PuntFinal = 5 + 5 * PremiosConc / PremiosOK;

    cout.precision(2);
    cout << fixed;
    cout << "ckecker log: puntuacion = " << PuntFinal << endl;

    freopen("puntuacion.txt", "w", stdout);
    cout << PuntFinal << endl;
    fclose(stdout);


//    CLOSE_FILES:
//    fin.close();
//    fout.close();
//    fcon.close();

    return 0;
}
