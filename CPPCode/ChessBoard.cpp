//2026-10-23
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 1024;
int board[MAX][MAX];
int t = 0;

void ChessBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 1) return;
    int s = size / 2;
    int t1 = ++t;

    if (dr < tr + s && dc < tc + s) {
        ChessBoard(tr, tc, dr, dc, s);
    } else {
        board[tr + s - 1][tc + s - 1] = t1;
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    if (dr < tr + s && dc >= tc + s) {
        ChessBoard(tr, tc + s, dr, dc, s);
    } else {
        board[tr + s - 1][tc + s] = t1;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    if (dr >= tr + s && dc < tc + s) {
        ChessBoard(tr + s, tc, dr, dc, s);
    } else {
        board[tr + s][tc + s - 1] = t1;
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    if (dr >= tr + s && dc >= tc + s) {
        ChessBoard(tr + s, tc + s, dr, dc, s);
    } else {
        board[tr + s][tc + s] = t1;
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main() {
    int k = 2;
    int size = 1 << k;
    int dr = 0, dc = 1;

    board[dr][dc] = 0;

    ChessBoard(0, 0, dr, dc, size);

    cout << "棋盘覆盖结果 (0 表示特殊方格):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
