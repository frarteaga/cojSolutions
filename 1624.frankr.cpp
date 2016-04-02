//Prob: 1624 - Counting Palindromes
//Idea: DP,  FIXME: Memoizar la funcion bool palindrome() haciendola recursiva
//frankr@coj

#include <iostream>

using namespace std;

int cont[1001];

string s;

//FIXME: Memoizar esta funcion
bool palindrome(int pos1 , int pos2)
{
    int i = pos1, j = pos2;
    for( ; i <= j; i++, j--)
        if(s[i] != s[j])
         return false;
    return true;

}

int resuelvete()
{
    int N = s.size();
    s = " " + s;
    for(int i = 1; i <= N; i++)
    {
        cont[i] = i;
        for(int j = 1; j <= i; j++)
        {
            if(cont[j - 1] + 1 < cont[i] && palindrome(j, i))
                cont[i] = cont[j - 1] + 1;
        }
    }
    return cont[N];
}

int main()
{
    cin >> s;

    int sol = resuelvete();
    cout << sol;

    return 0;
}
