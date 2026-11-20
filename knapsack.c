
#include <stdio.h>
#include "museum.h"

void selectExhibits(void) {
    int dp[E + 1][121] = {0};
    int selected[E] = {0};
    int capacity;
    int i, w;

    printf("\nEnter visitor's available time (1-120 minutes): ");

    if (scanf("%d", &capacity) != 1 ||
        capacity < 1 || capacity > 120) {

        printf("Invalid time limit.\n");

        while (getchar() != '\n');

        return;
    }

    for (i = 1; i <= E; i++) {
        for (w = 0; w <= capacity; w++) {

            if (exhibits[i - 1].time <= w) {

                int include = exhibits[i - 1].value +
                    dp[i - 1][w - exhibits[i - 1].time];

                int exclude = dp[i - 1][w];

                dp[i][w] = (include > exclude) ? include : exclude;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    w = capacity;

    for (i = E; i >= 1; i--) {

        if (dp[i][w] != dp[i - 1][w]) {

            selected[i - 1] = 1;

            w -= exhibits[i - 1].time;
        }
    }

    printf("\nRECOMMENDED EXHIBITS\n");

    for (i = 0; i < E; i++) {

        if (selected[i]) {

            printf("%s | %d minutes | Value: %d\n",
                   exhibits[i].name,
                   exhibits[i].time,
                   exhibits[i].value);
        }
    }

    printf("\nTotal visit time: %d minutes\n",
           capacity - w);

    printf("Maximum interest value: %d\n",
           dp[E][capacity]);
}
