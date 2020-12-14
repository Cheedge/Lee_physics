#include<stdio.h>// printf
#include<stdlib.h>//strtol
#include<string.h>//atoi
#include<math.h>
#include<time.h>
/*2020-12-14 11:24*/
#define twopi 6.283185307179586
#define BUFFSIZE 1000

int main(int argc, char *argv[])
{
	//long int N; 
	//char* p;// for strtol function.
	clock_t clock_star=clock();
	int N;
	int i,j,t=0;
	double freq=0.0, invdt;
	double bufx, bufz;
	double x;
	//double *x;
	double *efieldy;
	double *fft_e_im, *fft_e_rl;
	FILE* f_out;
	FILE* fp;//=fopen(argv[1], "r");
	char buff[BUFFSIZE];
/* get M, dx */
    if((fp = fopen(argv[1], "r"))==NULL)
    {
		// input file is EFIELD.OUT.
        printf("command should be: \"%s <input_file> row_num\" ", argv[0]);
        return 1;
    }
    //printf("<file_input> is %s\n", argv[1]);
	//printf("num of rows is %s\n", argv[2]);
	//N=strtol(argv[2], &p, 10);
	if (argv[2]==NULL)
	{
		printf("give M: number of points same as rows\n");
		return 1;
		//exit(1);
	}
	else
	{
		sscanf(argv[2], "%d", &N);
		//N=atoi(argv[2]);
	}
	//printf(" %d\n", N);

	efieldy=(double*)malloc(sizeof(double)*N);
	fft_e_rl=(double*)malloc(sizeof(double)*N);
	fft_e_im=(double*)malloc(sizeof(double)*N);

	f_out=fopen("DFT_EFIELD.DAT", "w");
	while(fgets(buff, BUFFSIZE-1, fp) !=NULL)
	{
		sscanf(buff, "%lf %lf %lf %lf", &x, &bufx, &efieldy[t], &bufz);
		t++;
	}
	if(N!=t)
	{
		printf("input \"N\" not match the rows number");
		return 1;
	}
	invdt=1.0/N;
	for (i=0; i<N; i++)
	{
		fft_e_im[i]=0.0;
		fft_e_rl[i]=0.0;
		for (j=0; j<N; j++)
		{
			fft_e_rl[i]+=efieldy[j]*cos(i*j*twopi/N);
			fft_e_im[i]-=efieldy[j]*sin(i*j*twopi/N);
		}
	}

	for (i=0; i<N; i++)
	{
		freq+=invdt;
		fprintf(f_out, "%.11lf  %.11lf\n", freq, sqrt(pow(fft_e_rl[i],2)+pow(fft_e_im[i],2)));
	}
	fclose(f_out);
	fclose(fp);
	free(efieldy);
	clock_t clock_end=clock();
//	clock_t total_t=(double)(clock_end-clock_star)/CLOCKS_PER_SEC;
	printf("total time is %lf\n", (double)(clock_end-clock_star)/CLOCKS_PER_SEC);
	return 0;
}
