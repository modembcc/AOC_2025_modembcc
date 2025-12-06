#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1000

int main() {
    FILE *fptr;

    if (fptr == NULL) {
        printf("Not able to open the file.");
    }

    fptr = fopen("three.in", "r");
    char data[MAX_BUF];
    int ans = 0;
    while (fgets(data, sizeof data, fptr)) {
        data[100] = '\0';
        // printf("%s\n", data);
        int maxP = -1;
        int maxi = 0;
        int tmp = 0;
        for (int i = 0; data[i + 1] != '\0'; i++) {
            // printf("%c ", data[i]);
            if(data[i] - '0' > maxP) {
                maxi = i;
                maxP = data[i] - '0';
            }
        }
        // printf("\n");
        ans += maxP * 10;
        tmp += maxP * 10;
        maxP = -1;
        for (int i = maxi + 1; data[i] != '\0'; i++) {
            if(data[i] - '0' > maxP) {
                maxP = data[i] - '0';
            }
        }
        if(maxP == -1) {
            printf("Max I at %d\n", maxi);
            printf("%s", data);
        }
        ans += maxP;
        tmp += maxP;
        printf("%d\n", tmp);
    }
    printf("%d", ans);

    fclose(fptr);
}