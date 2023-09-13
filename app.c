#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    char voucherId[6][6];
    char digits[] = "0123456789";
    int digitsLength = strlen(digits);
    char lowers[] = "abcdefghijklmnopqrstuvwxyz";
    int lowersLength = strlen(lowers);
    char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int uppersLength = strlen(uppers);
    char symbols[] = "`!@#$^&*()_+{}";
    int symbolsLength = strlen(symbols);


    srand(time(NULL) * getpid());

    for (int i = 0; i < 6; i++) {
        int char_type = rand() % 4;

        if (char_type == 0) {
            voucherId[i] = digits[rand() % digitsLength];
        } else if (char_type == 1) {
            voucherId[i] = lowers[rand() % lowersLength];
        } else if (char_type == 2) {
            voucherId[i] = uppers[rand() % uppersLength];
        } else {
            voucherId[i] = symbols[rand() % symbolsLength];
        }
    }
    free(voucherId);

    printf("PS%s\n",voucherId);


    return 0;
}