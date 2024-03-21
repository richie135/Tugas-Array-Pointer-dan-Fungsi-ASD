#include <stdio.h>
#include <string.h>

// Fungsi untuk mengubah nilai kartu menjadi bilangan bulat
int cardValue(char card[3]) {
    if (strcmp(card, "J") == 0) {
        return 11;
    } else if (strcmp(card, "Q") == 0) {
        return 12;
    } else if (strcmp(card, "K") == 0) {
        return 13;
    } else if (strcmp(card, "10") == 0) {
        return 10;
    } else {
        return card[0] - '0';
    }
}

// Fungsi untuk menampilkan urutan kartu
void printCards(char cards[][3], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", cards[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    char cards[n][3];

    for (int i = 0; i < n; i++) {
        scanf("%s", cards[i]);
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (cardValue(cards[j]) < cardValue(cards[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
            char temp[3];
            strcpy(temp, cards[i]);
            strcpy(cards[i], cards[min_index]);
            strcpy(cards[min_index], temp);
            count++;
            printf("Pertukaran %d: ", count);
            printCards(cards, n);
        }
    }

    printf("%d\n", count);
    return 0;
}
