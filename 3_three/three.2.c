#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_BUF 1000

int main() {
    FILE *fptr;

    if (fptr == NULL) {
        printf("Not able to open the file.");
    }

    fptr = fopen("three.in", "r");
    char data[MAX_BUF];
    unsigned long long ans = 0;
    while (fgets(data, sizeof data, fptr)) {
        data[100] = '\0';
        // printf("%s\n", data);
        unsigned long long tmp = 0;
        int beg = 11;
        int maxi = -1;
        while(beg >= 0) {
            int maxP = -1;
            for (int i = maxi + 1; data[i + beg] != '\0'; i++) {
                // printf("%c ", data[i]);
                if(data[i] - '0' > maxP) {
                    maxi = i;
                    maxP = data[i] - '0';
                }
            }
            // printf("\n");
            ans += maxP * pow(10, beg);
            tmp += maxP * pow(10, beg);
            beg--;
        }
        printf("%llu\n", tmp);
    }
    printf("--> %llu", ans);

    fclose(fptr);
}