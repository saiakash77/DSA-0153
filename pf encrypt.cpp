#include <stdio.h>
#include <string.h>
#include <ctype.h>
void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char matrix[5][5], char ch1, char ch2, char *encrypted) {
    int row1, col1, row2, col2;
    findPosition(matrix, ch1, &row1, &col1);
    findPosition(matrix, ch2, &row2, &col2);

    if (row1 == row2) {
        encrypted[0] = matrix[row1][(col1 + 1) % 5];
        encrypted[1] = matrix[row2][(col2 + 1) % 5];
    }
    else if (col1 == col2) {
        encrypted[0] = matrix[(row1 + 1) % 5][col1];
        encrypted[1] = matrix[(row2 + 1) % 5][col2];
    }
    else {
        encrypted[0] = matrix[row1][col2];
        encrypted[1] = matrix[row2][col1];
    }
}

int main() {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'J'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char message[] = "see you ";
    int len = strlen(message);
    char preparedMessage[2 * len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            preparedMessage[j++] = toupper(message[i]);
        }
    }
    preparedMessage[j] = '\0';
    if (strlen(preparedMessage) % 2 != 0) {
        preparedMessage[j++] = 'X';
        preparedMessage[j] = '\0';
    }

    char encryptedMessage[2 * len];
    int k = 0;
    for (int i = 0; i < strlen(preparedMessage); i += 2) {
        encryptDigraph(matrix, preparedMessage[i], preparedMessage[i + 1], &encryptedMessage[k]);
        k += 2;
    }
    encryptedMessage[k] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);

    return 0;
}

