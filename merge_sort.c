
#include <stdio.h>
#include "museum.h"

void merge(struct Exhibit arr[], int left, int mid, int right) {
    struct Exhibit temp[E];

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].id <= arr[j].id) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(struct Exhibit arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void sortExhibits(void) {
    mergeSort(exhibits, 0, E - 1);

    printf("\nEXHIBITS SORTED BY ID\n");
    displayExhibits();
}
