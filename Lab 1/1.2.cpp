#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<iostream>
#include<time.h>
#include <cstdlib>
using namespace std;
#define Max 20

void mul2Matrix(int R1, int C1, int R2, int C2, int matrixA[][Max], int matrixB[][Max]){
    int i, j, k;

    //Cap phat ma tran C trong bo nho Heap
    int **Matrix_C = new int*[R1];
    for (int i=0; i<R1; i++){
        Matrix_C[i] = new int[C2];
    }

    //in cac phan tu cua ma tran A va B
    printf("\nCac phan tu cua ma tran A: \n\n");
    for (i=0; i<R1; i++){
        for (j=0; j<C1; j++){
            if (matrixA[i][j]>=0) printf(" %d\t", matrixA[i][j]);
            else                  printf("%d\t", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nCac phan tu cua ma tran B: \n\n");
    for (i=0; i<R2; i++){
        for (j=0; j<C2; j++){
            if (matrixB[i][j]>=0) printf(" %d\t", matrixB[i][j]);
            else                  printf("%d\t", matrixB[i][j]);
        }
        printf("\n");
    }
    //Nhan 2 ma tran A va B, luu ket qua vao C
    for (i=0; i<R1; i++){
         for (j=0; j<C2; j++){
              int sum = 0;
              for (k=0; k<C1; k++)
                  sum += matrixA[i][k] * matrixB[k][j];
                  Matrix_C[i][j] = sum;
         }
    }
    //In ma tran ket qua C
    printf("\nCac phan tu cua ma tran ket qua C: \n\n");
    for (i=0; i<R1; i++){
        for (j=0; j<C2; j++){
            if (Matrix_C[i][j]>=0) printf(" %d\t", Matrix_C[i][j]);
            else                   printf("%d\t", Matrix_C[i][j]);
        }
        printf("\n");
    }
}

int main () {
    srand(time(0));
    int Matrix_A[Max][Max], Matrix_B[Max][Max];
    int r1, c1, r2, c2;

    printf("Vui long nhap so hang va so cot cua ma tran A: ");
    scanf("%d %d", &r1, &c1);

    printf("Vui long nhap so hang va so cot cua ma tran B: ");
    scanf("%d %d", &r2, &c2);

    while (c1!=r2){
        printf("Error: Phai thoa man dieu kien C1 = R2\n");
        printf("Vui long nhap so hang va so cot cua ma tran A: ");
        scanf("%d %d", &r1, &c1);

        printf("Vui long nhap so hang va so cot cua ma tran B: ");
        scanf("%d %d", &r2, &c2);
    }

    //Cap phat bo nho ma tran C trong stack
    int Matrix_C[Max][Max];

    //Random cac gia tri cua 2 ma tran A va B
    for (int i=0; i<r1; i++){
        for (int j=0; j<c1; j++){
            Matrix_A[i][j] = -40 + (rand()/(RAND_MAX/91));
        }
    }

    for (int i=0; i<r2; i++){
        for (int j=0; j<c2; j++){
            Matrix_B[i][j] = -40 + (rand()/(RAND_MAX/91));
        }
    }

    //Goi ham nhan ma tran
    mul2Matrix(r1, c1, r2, c2, Matrix_A, Matrix_B);

    return 0;
}

