#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <malloc.h>

int i,j,temp,N=3,M=4,choise, v ;
int maximal=0,sort,sum=0,vvod,end;

int Maximum(int **A)
{
    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if (A[i][j] > maximal)
                {
                maximal = A[i][j];
                }
            }
        }
    printf("\n������������ �������� ������� �: %d\n",maximal);
}

int Transponate (int **B,int **T)
{
    for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                T[j][i] = B[i][j];
            }
        }
    printf("\n ���������������� ������� B :  \n");
    for (i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%3d ", T[i][j]);
        }
    printf("\n");
    }
}

int Multiply(int **A,int **B,int **Dob)
{
     for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                Dob[i][j]=0;
                for(int p=0;p<N;p++)
                {
                    Dob[i][j] += A[i][p] * B[p][j];
                }
            }
        }

        for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                printf("%3d ", Dob[i][j]);
            }
            printf("\n");
        }
}

int Sort(int **A,int sort)
{
    for(int k=1;k<N;k++)
    {
        for(j=0;j<N-k;j++)
        {

            if(A[sort][j]>A[sort][j+1])
            {
                    temp = A[sort][j];
                    A[sort][j] = A[sort][j+1];
                    A[sort][j+1] = temp;
            }
        }
    }
    for(j=0;j<N;j++)
    {
    printf("%3d ",A[sort][j]);
    }
}

int Summ(int **A,int **B,int sum)
{
    for(i=0;i<N;i++)
    {
        sum=0;
        for(j=0;j<N;j++)
        {
            sum += A[i][j];
        }
        printf("\n%d ����� ��������� ����� ������� � =%d",i,sum);
        }
    for(j=0;j<M;j++)
    {
        sum=0;
        for(i=0;i<N;i++)
        {
            sum += B[i][j];
        }
        printf("\n%d ����� ��������� �������� ������� � =%d",j,sum);
    }
}

int main()
{  setlocale(LC_ALL, "Rus");
 for(int q=0;q<5;q++)
 {
    printf("������� ������� �����))))\n");
    printf("�������� �������� �������:\n1. ��������������\n2. � ����������\n");
    scanf("%d",&vvod);
    if (vvod==2)
    {
    printf("\n������� ������ ���������� �������: ");
    scanf("%d",&N);
    printf("\n������� ������ ������������� �������: ");
    scanf("%d",&M);
    }


    int **A=NULL;
    A=(int**) malloc(N * sizeof(int));
    for(int i=0;i<N;i++)
    {
        A[i]=(int*) malloc(N * sizeof(int));
    }

    int **B=NULL;
    B=(int**) malloc(M * sizeof(int));

    int **Dob=NULL;
    Dob=(int**) malloc(M * sizeof(int));

    int **T=NULL;
    T=(int**) malloc(N * sizeof(int));

    for(int i=0;i<M;i++)
    {
        B[i]=(int*) malloc(N * sizeof(int));
        Dob[i]=(int*) malloc(N * sizeof(int));
        T[i]=(int*) malloc(M * sizeof(int));
    }

    if(vvod==2)
    {
    printf("������� �������� ���������� �������:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("������� �������� ������������� �������:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    }
    else
    {
        for (i=0;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                A[i][j]= rand() %10;
            }
        }
        for (i=0;i<N;i++)
        {
            for (j=0;j<M;j++)
            {
                B[i][j]= rand() %15;
            }
        }
    }

    printf("\n�������� ������� A � B:\n");
        for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
        printf("\n");

    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("\n���� ����������::\n1. ��� � \n2. ��������������� B\n3. �������� AxB\n4. ����������� ������ A\n5. �������� ����� � ������� � ��������\n");
        scanf("%d",&choise);
    }while(choise != 1 && choise != 2 && choise != 3 && choise != 4 && choise != 5);

    switch (choise)
    {
    case 1:
        Maximum(A);
    break;

    case 2:
        Transponate(B,T);
    break;

    case 3:
        printf("AxB:\n");
        Multiply(A,B,Dob);
    break;

    case 4:
        printf("\n������� ����� ������ ��� ����������: ");
        scanf("%d",&sort);
        Sort(A,sort);
    break;

    case 5:
        Summ(A,B,sum);
    break;

    }
        for(i=0;i<N;i++)
        {
          free(A[i]);
        }
        free(A);
        for(i=0;i<M;i++)
        {
          free(B[i]);
          free(Dob[i]);
          free(T[i]);
        }
        free(B);
        free(Dob);
        free(T);
        printf("\n\n");
 }
 return 0;
}
