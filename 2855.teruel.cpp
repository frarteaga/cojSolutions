//2855 - Sum of Numbers
//BF, next_permutation

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char s[12];
int len;
long long sum, sol;

int main() {
    while(1) {
        cin >> s;

        if(s[0] == '0' && !s[1])
            break;

        sol = 0;
        len = strlen(s);
        sort(s, s + len);

        int pos = 0;
        while(s[pos] == '0')
            pos++;
        swap(s[0], s[pos]);

        do {
            sum = 0;
            if(s[0] != '0')
                for(int i = 0; i < len; i++)
                    sum = sum * 10 + s[i] - '0';
            sol += sum;
        } while(next_permutation(s, s + len));

        cout << sol << '\n';
    }
}
