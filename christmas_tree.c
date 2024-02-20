#include <stdio.h>

int main(){
    int n;
    printf("input n: ");
    scanf("%d", &n);

    //find how many row will be used
    int row=0,counter,adder=1;;
    for (counter=0; counter < n; counter+=adder,adder++){
        row++;
    }
    printf("row: %d\n",row);

    //find how many column will be used
    int lwing, rwing;
    if (counter > n){
        if (row % 2 == 0){
            lwing = row - 2; rwing = row - 1;
        }
        else {
            rwing = row - 2; lwing = row - 1;
        }
    }
    else if (counter == n){
        if (row % 2 == 0){
            lwing = row ; rwing = row - 1;
        }
        else {
            rwing = row ; lwing = row - 1;
        }
    }
    printf("lwing: %d, rwing: %d\n", lwing, rwing);

    //print tree with alphabet
    int alpha = 0;
    int printed = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < (lwing + rwing - 1); j++){
            if((i % 2 == 0) && (printed < n) && (j >= lwing - 1 && j < lwing + i)){
                printf("%c ",'A'+((alpha++))%26);
                printed++;
            }
            else if((i % 2 != 0) && (printed < n) && (j < lwing && j >= (lwing - i) - 1)){
                printf("%c ",'A'+((alpha++))%26);
                printed++;
            }
            else{
                printf("_ ");
            }
        }
        printf("\n");
    }
    return 0;
}
