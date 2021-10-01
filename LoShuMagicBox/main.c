#include <stdio.h>

int checkLoShu(int LoShuBox[3][3]);
int randomNumber();

void main(){

    int LoShuBox[3][3] = {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};

    for(int i = 0; i<3; i++){
        for(int s = 0; s<3; s++){
            printf("%d, ", LoShuBox[i][s]);
        }

        printf("\n");
    }

    int result = checkLoShu(LoShuBox);

    printf("Common sum of this box: %d\n", result);

    int maybeLoShuBox[3][3];



}

int checkLoShu(int LoShuBox[3][3]){
    //returns 0 if not a LoShuBox (sum can never be 0)
    //returns common sum if a LoShuBox
    int sum = 0;
    int sum2 = 0;

    //i is columns
    //s is rows

    //get sum to compare against
    for (int s = 0; s<3; s++){
        sum = sum + LoShuBox[0][s];
    }

    //get other sums to compare against sum
    for (int i = 1; i<3; i++){
        for (int s = 0; s<3; s++){
            sum2 = sum2 + LoShuBox[i][s];
        }

        if(sum2 != sum){
            return 0;
        }

        sum2 = 0;

    }

    //check diagonals
    for (int d = 0; d<3; d++){
        sum2 = sum2 + LoShuBox[d][d];
    }

    if(sum2 != sum){
        return 0;
    }

    sum2 = 0;

    //check other diagonal
    for(int t = 0; t<3; t++){
        sum2 = sum2 + LoShuBox[t][2-t];
    }

    if(sum2 != sum){
        return 0;
    }

    sum2 = 0;

    return sum;

}

int randomNumber(){
    

}