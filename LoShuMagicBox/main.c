//Compile script: gcc main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkLoShu(int LoShuBox[3][3]);
int randomNumber();

void main(){

    int LoShuBox[3][3] = {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
    int notLoShuBox[3][3] = {{2, 9, 5}, {7, 4, 1}, {6, 3, 8}};

    time_t t;

    srand((unsigned) time(&t));

    printf("Lo Shu Box: \n");
    for(int i = 0; i<3; i++){
        printf("[ ");
        for(int s = 0; s<3; s++){
            printf("%d ", LoShuBox[i][s]);
        }

        printf("]\n");
    }

    int result = checkLoShu(LoShuBox);

    printf("Common sum of this box: %d\n\n", result);

    //not a LoShuBox
    printf("Not a Lo Shu Box: \n");
    for(int i = 0; i<3; i++){
        printf("[ ");
        for(int s = 0; s<3; s++){
            printf("%d ", notLoShuBox[i][s]);
        }

        printf("]\n");
    }

    result = checkLoShu(notLoShuBox);
    if(result == 0){
        printf("This is not a Lo Shu Box\n\n");
    }else{
        printf("The common sum of this Lo Shu Box is: %d\n\n", result);
    }


    int maybeLoShuBox[3][3];
    int valuesInBox[9];
    int pointer = 0;
    int tf;
    int counter = 0;

    do{
    
    //create a box with no repeats
    for(int i = 0; i<3; i++){
        for(int s = 0; s<3; s++){
            maybeLoShuBox[i][s] = rand() % 9 + 1;
            valuesInBox[pointer] = maybeLoShuBox[i][s];
            for(int u = 0; u < pointer; u++){
                if(valuesInBox[u] == valuesInBox[pointer]){
                    // printf("Repeat: %d, %d: %d", i, s, maybeLoShuBox[i][s]);
                    maybeLoShuBox[i][s] = rand() % 9 +1;
                    valuesInBox[pointer] = maybeLoShuBox[i][s];
                    //incriments by 1 so to reach 0, has to be -1
                    u = -1;
                }
            }
            pointer++;

        }
    }

    pointer = 0;

    tf = checkLoShu(maybeLoShuBox);

    counter++;

    } while (tf == 0);


    printf("Random Loshu Box: \n");
    for(int i = 0; i<3; i++){
        printf("[ ");
        for(int s = 0; s<3; s++){
            printf("%d ", maybeLoShuBox[i][s]);
        }

        printf("]\n");
    }

    printf("Common sum of the random Lo Shu box: %d\n", tf);
    printf("Times attempted until Lo Shu box: %d", counter);


}

int checkLoShu(int Box[3][3]){
    //returns 0 if not a LoShuBox (sum can never be 0)
    //returns common sum if a LoShuBox
    int sum = 0;
    int sum2 = 0;

    //i is columns
    //s is rows

    //get sum to compare against
    for (int s = 0; s<3; s++){
        sum = sum + Box[0][s];
    }

    //get other rows
    for (int i = 1; i<3; i++){
        for (int s = 0; s<3; s++){
            sum2 = sum2 + Box[i][s];
        }

        if(sum2 != sum){
            return 0;
        }

        sum2 = 0;

    }

    //check columns
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            sum2 = sum2 + Box[c][r];
        }

        if(sum2 != sum){
            return 0;
        }

        sum2 = 0;
    }

    //check diagonals
    for (int d = 0; d<3; d++){
        sum2 = sum2 + Box[d][d];
    }

    if(sum2 != sum){
        return 0;
    }

    sum2 = 0;

    //check other diagonal
    for(int t = 0; t<3; t++){
        sum2 = sum2 + Box[t][2-t];
    }

    if(sum2 != sum){
        return 0;
    }

    sum2 = 0;

    return sum;

}
