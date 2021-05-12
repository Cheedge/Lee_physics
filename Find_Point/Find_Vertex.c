#include<stdio.h>
#include<stdlib.h>//malloc for gcc
#include<string.h>//atoi
#include<math.h>
#define BUFFERSIZE 1000

int main( int argc, char *argv[])
{
        int i, j, left, right, top, bottom, N;
        double *x, *y, *z;
        //double* y;
        //double* z;
        double nex, nup, ndw, ntot, nsup, nsdw;
        double a, b;
        FILE* fp_in;
        FILE* fp_out;
        char buff[BUFFERSIZE];

        if(argc<3)
        {
                printf("command should like: \"%s <file> N(rows)\"\n", argv[0]);
                return 1;
        }
        if((fp_in = fopen(argv[1], "r"))==NULL)
        {
                printf("give right input file name! not this \"%s\"!\n", argv[1]);
                return 1;
        }
        if(argv[2]==NULL)
        {
                printf("2nd para is num of rows, not this \"%s\"\n", argv[2]);
                return 1;
        }
        //sscanf(argv[2], "%d", &N);
        N=atoi(argv[2]);
        x=(double*)malloc(sizeof(double)*N);
        y=(double*)malloc(sizeof(double)*N);
        z=(double*)malloc(sizeof(double)*N);
        j=0;
        while(fgets(buff, BUFFERSIZE-1, fp_in)!=NULL)
        {
                sscanf(buff, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x[j], &y[j], &z[j], &nex, &nup, &ndw, &ntot, &nsup, &nsdw);
                j++;
        }
        if(j!=N)
        {
                printf("given row number \"%s\" is wrong", N);
                return 1;
        }
        a=x[0];
        b=y[0];
        for(i=0;i<N;i++)
        {
                if(a<x[i])
                {
                        a=x[i];
                        right=i;
                }
                if(b<y[i])
                {
                        b=y[i];
                        top=i;
                }
        }
        for(i=0;i<N;i++)
        {
                if(a>x[i])
                {
                        a=x[i];
                        left=i;
                }
                if(b>y[i])
                {
                        b=y[i];
                        bottom=i;
                }
        }
        fp_out=fopen("Vertex.dat", "w");
        fprintf(fp_out, "%18.16lf     %18.16lf     %18.16lf\n", x[left], y[left], z[left]);
        fprintf(fp_out, "%18.16lf     %18.16lf     %18.16lf\n", x[top], y[top], z[top]);
        fprintf(fp_out, "%18.16lf     %18.16lf     %18.16lf\n", x[right], y[right], z[right]);
        fprintf(fp_out, "%18.16lf     %18.16lf     %18.16lf\n", x[bottom], y[bottom], z[bottom]);
        fclose(fp_in);
        fclose(fp_out);
        free(x);
        free(y);
        free(z);
        return 1;
}
