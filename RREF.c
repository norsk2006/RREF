#include <stdio.h>
#include <stdlib.h>
#define first_row 0

int i, j, temp, temp2, x, y;

typedef struct Matrix{
        int rowCount;
        int colCount;
        double matrix[99][99];
    } Matrix;



Matrix swap(Matrix M, int row1, int row2){ //swap row1 with row2
    printf("Swapping rows %d and %d\n", row1, row2);
    for(x = 0; x<M.colCount;x++){
        
        temp = M.matrix[row1][x];
        M.matrix[row1][x] = M.matrix[row2][x];
        M.matrix[row2][x] = temp;
    }
    
 return M;
}

void print( Matrix M){
    for(x=0;x<M.rowCount;x++){
        for(y=0;y<M.colCount;y++){
            printf("%.2f\t", M.matrix[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    
}

Matrix RREF(Matrix M){ //RREF algorithm
     
    int row = 0;
    int k = 0;

    print(M);
    
    i=0;j=0;
    if(M.matrix[i][j]==0){ //check for 0 in first pivot column
        while(M.matrix[row][0]==0){
            row++;
          
        }
            
            M = swap(M, first_row, row);
            print(M);
    }
                
    i=0;j=0;      
   
    while(k < M.rowCount){
        float mult; //row multiplier
        float div; //row divisor
        for(i=0;i<M.rowCount;i++){
            
            div = M.matrix[k][k];
            if(div == 0){
                break;
            }
            mult = M.matrix[i][k] / M.matrix[k][k];
             
            for(j=0;j<M.colCount;j++){
                
                if(i == k){
                    M.matrix[i][j] /= div;
                    
                }
                else{
                    M.matrix[i][j] -= M.matrix[k][j] * mult;
                    
                }
            }
                  
        }
             k++;
             print(M);
            
    }
    
    printf("Reduced Row Echelon Form of Matrix is:\n");
    print(M);
    
    return M;
}


Matrix input(){
    
Matrix output; //outputted matrix

printf("Please input the number of rows in the matrix:\n ");

scanf("%d", &output.rowCount);

printf("\nPlease input the number of columns in the matrix:\n");
scanf("%d", &output.colCount);




for(i=0;i<output.rowCount;i++){
    printf("Please input row %d\n", i+1);
    for(j=0;j<output.colCount;j++)
    scanf("%lf", &output.matrix[i][j]); 
}

return output;

}

int main() {

    Matrix matrix = input();
    RREF(matrix);

    return 0;
}