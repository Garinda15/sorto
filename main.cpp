#include <iostream>
#include <stdio.h>
#include <math.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m\033[1m"
#define COLOR_GREEN   "\033[32m\033[1m"
#define COLOR_YELLOW  "\033[33m\033[1m"
#define COLOR_BLUE    "\033[34m\033[1m"
#define COLOR_CYAN    "\033[36m\033[1m"
#define TEXT_BOLD     "\033[1m"

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("array size, min number, max number?");
        getchar();
        return -1;
    }

    int min=atoi(argv[2]);
    int max=atoi(argv[3]);
    int m = atoi(argv[1]);
    int mass[m][m];
    int zamen=0;

    for (int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            mass[i][j] = (rand() % (max-min+1))+min;
        }
    }

    printf("Исходный массив:\n");
    for (int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d\t",mass[i][j]);
        }
        printf("\n");
    }

    getchar();

    printf("\033[1A");

    int temp1;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("\nПоехали в цикл: mass[%d][%d] = %d\n", i, j, mass[i][j]);
            for(int k = 0; k < m; k++)
            {
                for(int l = 0; l < m; l++)
                {
                    if (mass[i][j] < mass[k][l])
                    {
                        temp1 = mass[k][l];
                        mass[k][l] = mass [i][j];
                        mass[i][j] = temp1;
                        zamen++;
                        printf("\nЗамена номер %d: mass[%d][%d] стало = %d, было = %d\n", zamen, i, j, temp1, mass[k][l]);
                        for (int a=0; a<m; a++)
                        {
                            for(int b=0; b<m; b++)
                            {
                                if ((a==i and b==j) or (a==k and b==l)) printf(COLOR_YELLOW);
                                printf("%d\t",mass[a][b]);
                                printf(COLOR_RESET);
                            }
                            printf("\n");
                        }

                    }
                }
            }
        }
    }
    printf("\nКонечный результат:\n");
    for (int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d\t",mass[i][j]);
        }
        printf("\n");
    }
    printf("\nКоличество замен: %d", zamen);

    getchar();
    return 0;
}

