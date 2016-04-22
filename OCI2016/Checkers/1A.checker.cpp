/*
CNC2016-1A Checker
frankr@coj
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 201;

int main(int args, char * argv[])
{
    ifstream fin("hexagono.in");
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

    //cout << "000" << endl;

    string line1_ok;
    fout >> line1_ok;
    string line2_ok[2];
    fout >> line2_ok[0] >> line2_ok[1];

    string line1;
    fcon >> line1;
    string line2[2];
    fcon >> line2[0] >> line2[1];

    string tmp;
    if (fcon >> tmp){
        cout << "checker log: salida adicional" << endl;
        return 102;
    }

    double PuntFinal = 0.0;

    if (line1_ok != line1)
        cout << "ckecker log: no calculo bien el primer numero" << endl;
    else
        PuntFinal += 2.0;

    if (line2[0] != line2_ok[0] || line2[1] != line2_ok[1])
        cout << "ckecker log: no calculo bien el segundo y tercer numeros" << endl;
    else
        PuntFinal += 3.0;

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
