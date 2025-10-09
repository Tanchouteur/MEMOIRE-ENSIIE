//
// Created by louis.tanchou on 09/10/2025.
//

int isInTab(int *tab, int size, int m) {
    int a = 0;
    int b = size - 1;
    int mid = 0;

    while (a <= b){
        mid = (a + b) / 2;
        if (tab[mid] == m){
            return 1;
        }else if (tab[mid] < m){
            a = mid + 1;
        }else {
            b = mid - 1;
        }
    }
    return 0;
}