
#include <cstdio>
#include <queue>
#include <map>

using namespace std;
FILE *in = stdin, *out = stdout;

const int MAX = 100004;

struct Point {
    int x, y;
    bool operator < (const Point& r) const {
        return x != r.x ? x > r.x : y > r.y;
    }
};

int n;
int l, w, h;
Point points[MAX];

int atLeastH;
map <int, int> yCoords;
priority_queue <Point> add, rem;

void updateCoord(int y, int value) {
    yCoords[y] += value;
    map <int, int> :: iterator it = yCoords.find(y);
    if (it->second != 0 && it->second - value != 0)
        return;
    int lower, upper;
    it--; lower = y - it->first; it++;
    it++; upper = it->first - y; it--;
    atLeastH += ((lower >= h) + (upper >= h) - (lower + upper >= h)) * value;
    if (it->second == 0)
        yCoords.erase(it);
}


void updateLine(int& xPosition) {
    bool updated = true;
    while (updated) {
        updated = false;

        // Add new points
        while (!add.empty() && add.top().x - w < xPosition) {
            Point point = add.top(); add.pop();
            updateCoord(point.y, +1);
        }

        // Move the sweep line and remove points that are already behind
        while (!rem.empty() && (rem.top().x <= xPosition || atLeastH == 0)) {
            Point point = rem.top(); rem.pop();
            if (atLeastH == 0)
                xPosition = point.x, updated = true;
            updateCoord(point.y, -1);
        }
    }
}

int solve() {
    yCoords[0] = 1, yCoords[l] = 1, atLeastH = (l >= h);

    int xPosition = 0;
    for (int i = 0; i < n; i++) {
        // Boundaries don't change anything
        if (points[i].x == 0 || points[i].x == l || points[i].y == 0 || points[i].y == l)
            continue;

        // Unnecessary (already passed)
        if (points[i].x <= xPosition)
            continue;

        // Add for future evaluation
        add.push(points[i]), rem.push(points[i]);

        // Move the sweep line if possible
        updateLine(xPosition);
        if (xPosition + w > l)
            return i + 1;
    }
    return -1;
}

int main(void) {

    freopen( "fumigacion.in", "r", stdin );
    freopen( "fumigacion.out", "w", stdout );

    fscanf(in, "%d %d %d %d", &n, &l, &w, &h);
    for (int i = 0; i < n; i++)
        fscanf(in, "%d %d", &points[i].x, &points[i].y);
    fprintf(out, "%d\n", solve());

    return 0;
}
