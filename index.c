#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    int paymentType;
    printf("Enter payment:\n");
    scanf("%d",&paymentType);

    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charsetLength = sizeof(charset) - 1; // Length of the charset

    srand(time(NULL));

    char voucherId[7]; // 6 characters + 1 for null-terminator

    for (int i = 0; i < 6; i++) {
        int randomIndex = rand() % charsetLength;
        voucherId[i] = charset[randomIndex];
    }

    voucherId[6] = '\0';

    if (paymentType == 1500) {
        printf("PH%s\n", voucherId);
    } else if (paymentType == 5000) {
        printf("PD%s\n", voucherId);
    } else {
        printf("\nInvalid input.\n");
    }

    return 0;
}
