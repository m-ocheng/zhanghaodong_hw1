/*
 * @Author: mochen 3230104299@zju.edu.cn
 * @Date: 2024-04-08 18:03:46
 * @LastEditors: mochen 3230104299@zju.edu.cn
 * @LastEditTime: 2024-05-04 12:43:39
 * @FilePath: \zhanghaodong_hw1\src\algebra.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if (a.rows == b.rows && a.cols == b.cols)
    {
        Matrix c = create_matrix(a.rows,a.cols);
                for (int i = 0; i < a.rows; i++)
                {
                    for (int j = 0; j < a.cols; j++)
                    {
                        c.data[i][j]=a.data[i][j]+b.data[i][j];
                    }
                }
        return(c);
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    return create_matrix(0, 0);

}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if (a.rows == b.rows && a.cols == b.cols)
    {
        Matrix c = create_matrix(a.rows,a.cols);
                for (int i = 0; i < a.rows; i++)
                {
                    for (int j = 0; j < a.cols; j++)
                    {
                        c.data[i][j]=a.data[i][j]-b.data[i][j];
                    }
                }
        return(c);
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    return create_matrix(0, 0);
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if (a.cols == b.rows)
    {
        Matrix c = create_matrix(a.rows,b.cols);
                for (int i = 0; i < a.rows; i++)
                {
                    for (int j = 0; j < b.cols; j++)
                    {
                        c.data[i][j] = 0;
                        for(int k =0; k < a.cols; k++)
                        {
                            c.data[i][j]=c.data[i][j]+a.data[i][k]*b.data[k][j];
                        }
                    }
                }
        return(c);
    }
    else
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.");
    }
    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
     Matrix c = create_matrix(a.rows,a.cols);
                for (int i = 0; i < a.rows; i++)
                {
                    for (int j = 0; j < a.cols; j++)
                    {
                        c.data[i][j]=a.data[i][j]*k;
                    }
                }
        return(c);
    return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    Matrix c = create_matrix(a.rows,a.cols);
                for (int i = 0; i < a.rows; i++)
                {
                    for (int j = 0; j < a.cols; j++)
                    {
                        c.data[i][j]=a.data[j][i];
                    }
                }
        return(c);
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    if(a.cols == a.rows)
    {
        if (a.cols == 1)
        {
            return a.data[0][0];
        }
        else if (a.cols == 2)
        {
            return a.data[0][0]*a.data[1][1]- a.data[0][1]*a.data[1][0];
        }
        else
        {
            double result = 0;
            for(int k = 0; k < a.cols; k++)
            {
               Matrix c = create_matrix(a.rows-1,a.cols-1);
                for (int i = 0; i < a.rows-1; i++)
                {
                    for (int j = 0; j < a.cols-1; j++)
                    {
                        if(j<k)
                        c.data[i][j] = a.data[i+1][j];
                        else
                        c.data[i][j] = a.data[i+1][j+1];
                    }
                } 
                int l = (k%2) ? -1:1;
                result += l *det_matrix(c)*a.data[0][k];
                
            }
            return result;
        }
        
        

    }
    else
    {
        printf("Error: The matrix must be a square matrix.");
    }
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    if(a.cols == a.rows)
    {
        if(det_matrix(a) !=0)
        {
           Matrix c = create_matrix(a.rows,a.cols); 
            for(int j=0;j<a.rows;j++)
            {
                for(int i=0;i<a.cols;i++)
                {
                    Matrix b = create_matrix(a.rows-1,a.cols-1);
                    for (int m = 0; m < a.rows-1; m++)
                    {
                         for (int n = 0; n < a.cols-1; n++)
                        {
                            if(m<j)
                            {
                                if(n<i)
                                {
                                    b.data[m][n]=a.data[j][i];
                                }
                                else
                                {
                                    b.data[m][n]=a.data[j][i+1];
                                }
                            }
                        
                            else
                            {
                                if(n<i)
                                {
                                    b.data[m][n]=a.data[j+1][i];
                                }
                                else
                                {
                                    b.data[m][n]=a.data[j+1][i+1];
                                }
                            }
                        }
                    }
                    int l = ((i+j)%2) ? -1:1;
                    c.data[i][j]=l*det_matrix(b);

                }
            }
            return c;
        }
        else
        {
            printf("Error: The matrix is singular.");
        }

    }
    else
    {
        printf("Error: The matrix must be a square matrix.");
    }
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    int rank =a.rows < a.cols ? a.rows : a.cols;
    for(int i = 0;i<a.cols;i++)
    {
        if(a.data[i][i] == 0)
        {
            int j;
            for(j=i+1;j<rank;j++)
            {
                if(a.data[j][i]!=0)
                    break;
            }
            if(a.data[j][i]!=0)
            {
                for(int k = 0;k<a.cols;k++)
                {
                    double temp;
                    temp=a.data[j][k];
                    a.data[j][k]=a.data[i][k];
                    a.data[i][k]=temp;
                }
            }
            else
            {
                rank--;
                for(int r=0;r<a.rows;r++)
                {
                    a.data[r][i]=a.data[r][rank];
                }
            }
            
        }
        else
        {
            for(int j=i+1;j<a.rows;j++)
            {
                double factor=a.data[j][i]/a.data[i][i];
                for(int k = i;k<a.cols;k++)
                {
                    a.data[j][k]-=factor*a.data[i][k];
                }
            }
        }
    }
    return rank;
    return 0;
}

double trace_matrix(Matrix a)
{
    if(a.cols==a.rows)
    {
        double s=0;
        for(int i=0;i<a.cols;i++)
        {
            s+=a.data[i][i];
        }
        return s;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.");
    }
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}