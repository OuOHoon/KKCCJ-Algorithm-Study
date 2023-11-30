#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <pair <char, pair <int, int>>> v;
vector <char> d;

bool check(int x, int y) {
    if (x > 5 || x < -5 || y > 5 || y < -5) return false;
    else return true;
}

int solution(string dirs) {
    int x = 0, y = 0;

    for (int i = 0; i < dirs.size(); i++) 
        d.push_back(dirs[i]);

    for (int i = 0; i < d.size(); i++) {

        switch (d[i]) {
        case 'U' :
            if (!check(x, y + 1)) continue;
            v.push_back({ d[i], { x, y } });
            y++;
            v.push_back({ 'D', { x, y } });
            break;
        case 'D':
            if (!check(x, y - 1)) continue;
            v.push_back({ d[i], { x, y } });
            y--;
            v.push_back({ 'U', { x, y } });
            break;
        case 'L':
            if (!check(x - 1, y)) continue;
            v.push_back({ d[i], { x, y } });
            x--;
            v.push_back({ 'R', { x, y } });
            break;
        case 'R':
            if (!check(x + 1, y)) continue;
            v.push_back({ d[i], { x, y } });
            x++;
            v.push_back({ 'L', { x, y } });
            break;
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return v.size() / 2;
}
