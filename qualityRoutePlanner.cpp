#include <iostream>
#include <map>
#include <string>
using namespace std;

map<pair<int, int>, bool> mp;

const int qua[4] = {0, 1, 2, 3};
const int dist[4][4] = {
    {0, 6, 8, 3},
    {6, 0, 2, 3},
    {8, 2, 0, 5},
    {3, 3, 5, 0}
};
const int f[4][4] = {
    {0, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 1, 0, 1},
    {0, 0, 0, 0}
};
const int wea[32] = {
    2, 2, 1, 3, 1, 2, 3, 1, 2, 2,
    3, 2, 1, 2, 2, 1, 1, 2, 1, 3,
    2, 1, 1, 2, 2, 0, 0, 0, 0, 0,
    0, 0
};
const int mx = 3, my = 2;
const int cx = 5, cy = 10;
const int sx[4] = {0, 5, 8, 10};
const int sy[4] = {0, 7, 6, 10};
const int n = 4;
const int maxm = 1200;
const int coins = 10000;
const int base = 1000;
const int date = 30;

int costx[32][4][4];
int costy[32][4][4];
int days[32][4][4];

int ans = 0;
int rec[32];
int act[32];
int ansx[32];
int ansact[32];
int ansg, ansh;
int g, h;

string placeName(int id) {
    switch (id) {
        case 0: return "Start";
        case 1: return "Village";
        case 2: return "Mine";
        case 3: return "End";
        default: return "Unknown";
    }
}

string actionName(int type) {
    switch (type) {
        case -1: return "None";
        case 0: return "Move";
        case 1: return "Mine without investment";
        case 2: return "Mine with investment";
        default: return "Unknown";
    }
}

void dfs(int day, int now, int nm, int c, int x, int y, int type) {
    if (day > date)
        return;

    if (c + x * cx + y * cy + (date - day) * base <= ans)
        return;

    act[day] = type;
    rec[day] = now;

    if (qua[now] == 3) {
        if (ans <= c + x * cx + y * cy) {
            ansg = g;
            ansh = h;
            ans = c + x * cx + y * cy;
            for (int i = 0; i <= date; i++)
                ansx[i] = rec[i];
            for (int i = 0; i <= date; i++)
                ansact[i] = act[i];
        }
        act[day] = -1;
        rec[day] = -1;
        return;
    }

    if (day >= date) {
        act[day] = -1;
        rec[day] = -1;
        return;
    }

    if (qua[now] == 1)
        nm = maxm - mx * x - my * y;

    for (int i = 0; i < n; i++) {
        if (f[qua[now]][qua[i]]) {
            int tx = costx[day][now][i];
            int ty = costy[day][now][i];
            int ucost = c;
            int ux, uy;
            int um = nm;

            if (x >= tx)
                ux = x - tx;
            else {
                ux = 0;
                ucost -= 2 * (tx - x) * cx;
                um -= (tx - x) * mx;
            }

            if (y >= ty)
                uy = y - ty;
            else {
                uy = 0;
                ucost -= 2 * (ty - y) * cy;
                um -= (ty - y) * my;
            }

            if (ucost < 0 || um < 0)
                continue;

            int arriveDay = day + days[day][now][i];
            if (arriveDay <= date)
                dfs(arriveDay, i, um, ucost, ux, uy, 0);
        }
    }

    if (qua[now] == 2) {
        {
            int attday = day;
            int tx = sx[wea[attday]];
            int ty = sy[wea[attday]];
            attday++;
            int new_x = x, new_y = y;
            int new_nm = nm, new_c = c;

            if (new_x >= tx) {
                new_x -= tx;
                tx = 0;
            } else {
                tx -= new_x;
                new_x = 0;
            }

            if (new_y >= ty) {
                new_y -= ty;
                ty = 0;
            } else {
                ty -= new_y;
                new_y = 0;
            }

            new_nm -= tx * mx + ty * my;
            new_c -= 2 * tx * cx + 2 * ty * cy;
            if (new_nm >= 0 && new_c >= 0)
                dfs(attday, now, new_nm, new_c, new_x, new_y, 1);
        }

        {
            int attday = day;
            int tx = sx[wea[attday]] * 2;
            int ty = sy[wea[attday]] * 2;
            attday++;
            int new_x = x, new_y = y;
            int new_nm = nm, new_c = c;

            if (new_x >= tx) {
                new_x -= tx;
                tx = 0;
            } else {
                tx -= new_x;
                new_x = 0;
            }

            if (new_y >= ty) {
                new_y -= ty;
                ty = 0;
            } else {
                ty -= new_y;
                new_y = 0;
            }

            new_nm -= tx * mx + ty * my;
            new_c -= 2 * tx * cx + 2 * ty * cy;
            new_c += base;
            if (new_nm >= 0 && new_c >= 0)
                dfs(attday, now, new_nm, new_c, new_x, new_y, 2);
        }
    }

    act[day] = -1;
    rec[day] = -1;
}

int main() {
    for (int d = 0; d <= date; d++) {
        rec[d] = -1;
        act[d] = -1;
        ansx[d] = -1;
        ansact[d] = -1;
    }

    for (int d = 0; d <= date; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[qua[i]][qua[j]]) {
                    int now = 0, count = 0, sumx = 0, sumy = 0;
                    while (count < dist[i][j]) {
                        if (now + d > date)
                            break;

                        if (wea[now + d] != 3) {
                            count++;
                            sumx += 2 * sx[wea[now + d]];
                            sumy += 2 * sy[wea[now + d]];
                        } else {
                            sumx += sx[wea[now + d]];
                            sumy += sy[wea[now + d]];
                        }
                        now++;
                    }

                    if (count < dist[i][j]) {
                        sumx = sumy = 20000;
                        now = 30;
                    }

                    costx[d][i][j] = sumx;
                    costy[d][i][j] = sumy;
                    days[d][i][j] = now;
                }
            }
        }
    }

    for (int i = 0; i <= maxm; i++) {
        g = i / mx;
        h = (maxm - i) / my;
        if (!mp[make_pair(g, h)]) {
            dfs(0, 0, 0, coins - g * cx - h * cy, g, h, -1);
            mp[make_pair(g, h)] = true;
        }
    }

    if (ans == 0) {
        cout << "No feasible route found." << endl;
        return 0;
    }

    cout << "Best route:" << endl;
    for (int i = 0; i <= date; i++) {
        if (ansx[i] == -1 && ansact[i] == -1)
            continue;

        cout << "Day " << i << ": "
             << placeName(ansx[i]) << " (" << ansx[i] << "), "
             << actionName(ansact[i]) << " (" << ansact[i] << ")" << endl;
    }

    cout << endl;
    cout << "Final value: " << ans << endl;
    cout << "Initial water: " << ansg << endl;
    cout << "Initial food: " << ansh << endl;

    return 0;
}
