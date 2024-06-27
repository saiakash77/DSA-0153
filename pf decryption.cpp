#include <stdio.h>
#include <string.h>

// Function to find the row and column of a character in the Playfair square
void findPosition(char square[5][5], char ch, int *row, int *col) {
    if (ch == 'J') // Treat 'J' as 'I'
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (square[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decrypt the Playfair-encoded message
void decryptPlayfair(char square[5][5], const char *cipherText) {
    char decrypted[strlen(cipherText)];
    int len = strlen(cipherText);
    int row1, col1, row2, col2;

    for (int i = 0; i < len; i += 2) {
        char ch1 = cipherText[i];
        char ch2 = cipherText[i + 1];

        // Find positions of the two characters in the Playfair square
        findPosition(square, ch1, &row1, &col1);
        findPosition(square, ch2, &row2, &col2);

        if (row1 == row2) { // Characters are in the same row
            decrypted[i] = square[row1][(col1 - 1 + 5) % 5];
            decrypted[i + 1] = square[row2][(col2 - 1 + 5) % 5];
        } else if (col1 == col2) { // Characters are in the same column
            decrypted[i] = square[(row1 - 1 + 5) % 5][col1];
            decrypted[i + 1] = square[(row2 - 1 + 5) % 5][col2];
        } else { // Characters form a rectangle
            decrypted[i] = square[row1][col2];
            decrypted[i + 1] = square[row2][col1];
        }
    }
    decrypted[len] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char square[5][5] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'R', 'Y', 'T'},
        {'U', 'H', 'E', 'Y', 'F'},
        {'S', 'K', 'R', 'E', 'H'}
    };

    const char *cipherText = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWITTUOLKSYCAJPO???????NTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    decryptPlayfair(square, cipherText);

    return 0;
}

