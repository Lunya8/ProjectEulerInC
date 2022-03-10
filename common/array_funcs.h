#ifndef PROJECTEULER_ARRAY_FUNCS_H
#define PROJECTEULER_ARRAY_FUNCS_H

int in_i(int x, const int* arr, int arr_len, int start) {
    for (int i = start; i < arr_len + start; i++) {
        if (arr[i] == x) return i;
    }
    return 0;
}

#endif //PROJECTEULER_ARRAY_FUNCS_H
