#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Menandai posisi yang dapat dicapai oleh bidak kuda
    int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Mengisi array 2D dengan 0
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x*size + y) = 0;
        }
    }

    // Menandai posisi yang dapat dicapai oleh bidak kuda
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 0 && x < size && y >= 0 && y < size) {
            *(chessBoard + x*size + y) = 1;
        }
    }

    // Menampilkan hasil
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d", *(chessBoard + x*size + y));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int chessBoard[8][8];
    koboImaginaryChess(i, j, 8, (int *)chessBoard);
    return 0;
}
