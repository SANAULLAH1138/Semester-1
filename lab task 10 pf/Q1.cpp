#include <stdio.h>

int calculate_weight(void *box, int *weights, int *is_box, int size) {
    int total_weight = 0;
    for (int i = 0; i < size; i++) {
        if (is_box[i]) {
            total_weight += calculate_weight(box + i, weights, is_box, size);
        } else {
            total_weight += weights[i];
        }
    }
    return total_weight;
}

