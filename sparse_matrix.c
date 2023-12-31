#include <stdio.h>
int main()
{
    int sparse_matrix[4][5] = {{0, 0, 7, 0, 9},
                               {0, 0, 5, 7, 0},
                               {0, 0, 0, 0, 0},
                               {0, 2, 3, 0, 0}};
    int size = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    int matrix[3][size];
    int k = 0;
    // computing final matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                matrix[0][k] = i;
                matrix[1][k] = j;
                matrix[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    // dispaly the matrix
    for (int i = 0; i < 3; i++)
    {
        // for better understanding{
        if (i == 0)
        {
            printf("ROW\t");
        }
        else if (i == 1)
        {
            printf("COLUMN\t");
        }
        else if (i == 2)
        {
            printf("DATA\t");
        }
        // }
        for (int j = 0; j < size; j++)
        {
            printf("%d", matrix[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}