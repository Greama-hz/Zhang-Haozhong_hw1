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
    int i, j;
    Matrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: matrices are not the same size\n");
        exit(1);
    }
    c.rows = a.rows;
    c.cols = a.cols;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }return create_matrix(0, 0);
    return c;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    int i, j;
    Matrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: matrices are not the same size\n");
        return create_matrix(0, 0);
    }
    else
    {c.rows = a.rows;
     c.cols = a.cols;
        for (i = 0; i < a.rows; i++) 
        {
            for (j = 0; j < a.cols; j++) 
            {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
    return c;
}
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    int i, j, k;
    Matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    if(a.cols!= b.rows) 
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    for(i = 0; i < c.rows; i++) {
        for(j = 0; j < c.cols; j++) {
            c.data[i][j] = 0;
            for(k = 0; k < a.cols; k++) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

Matrix scale_matrix(Matrix a, double k)
{
    int i,j;
    for(i=0;i<a.rows;i++) {
        for(j=0;j<a.cols;j++) {
            a.data[i][j] = k*a.data[i][j];
        }
    }
    return a;
}

Matrix transpose_matrix(Matrix a)
{
    int i, j;
    Matrix b;
    b = create_matrix(a.rows, a.cols);
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            b.data[j][i] = a.data[i][j];
        }
    }
    return b;
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    double trace = 0.0;
    int i, j;
    for (i = 0; i < a.rows; i++) {
        trace += a.data[i][i];
    }
    return trace;
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