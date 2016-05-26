/* 
	username: leandro
	program: Dominoes Chips on Game
	lang: C++
*/

#include <cstdio>

int s;
int r1, c1;
int r2, c2;

inline int abs(int x) {
    return (x < 0) ? -x : +x;
}

bool is_no_ok() {
    if (r1 < 1 || r1 > 8 || c1 < 1 || c1 > 8) return true;
	if (r2 < 1 || r2 > 8 || c2 < 1 || c2 > 8) return true;
	if (r1 != r2 && c1 != c2) return true;
	if (r1 == r2) return abs(c1 - c2) != 1;
	if (c1 == c2) return abs(r1 - r2) != 1;
	return false;
}

int main() {

    /* Winning Strategy: Play Symmetrically */
    while (!feof(stdin)) {
	    scanf("%d%d%d%d%d\n", &s, &r1, &c1, &r2, &c2);
		if (is_no_ok())
		     printf("ERROR\n");
		else printf("%d\n", (s % 2) + 1);
	}
	
    return (0-0);
}

