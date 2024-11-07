#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20

int get_data_csv(double ar[], int lenght, char str[]);

int main(void) {
    
    char str[100] = {0};
    double ar[MAX_LEN];
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    int lenght = get_data_csv(ar, MAX_LEN, str);
    
    for (int i = 0; i < lenght; ++i) {
        if (i == lenght - 1) printf("%.2lf", ar[i]);
        else printf("%.2lf ", ar[i]);
    }

    return 0;
}

int get_data_csv(double ar[], int lenght, char str[]) {
    int len = 0;
    str = strchr(str, ':');
    while (str != NULL) {
        ar[len++] = atof(++str);
        str = strchr(str, ';');       
    }
    return len;
}