#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

FILE *input_p;
FILE *output_p;

int main(int argc, char *argv[])
 {
  int i,j,k,NT,NW;
  double w,t,W,T,dw,dt,ft;
  double *dip,*dipw,tmp;
  char *filein_p,*fileout_p;
  
/********* Get parameters from the command line *****************/

if( argc !=7 )
 { 
  printf("ERROR: should be %s T NT W NW <f_t in> <f_w out> \n",argv[0]);
  exit(1); 
 }
 
 if ( sscanf(argv[1],"%lf",&T) != 1 )
  {
   printf("Problem getting T from %s\n",argv[1]);
   exit(1);
  }  
 if ( sscanf(argv[2],"%d",&NT) != 1 )
  {
   printf("Problem getting NT from %s\n",argv[2]);
   exit(1);
  }
  
 if ( sscanf(argv[3],"%lf",&W) != 1 )
  {
   printf("Problem getting W from %s\n",argv[3]);
   exit(1);
  }  
 if ( sscanf(argv[4],"%d",&NW) != 1 )
  {
   printf("Problem getting NW from %s\n",argv[4]);
   exit(1);
  }  
  
 filein_p = argv[5];
 fileout_p = argv[6];

 if( filein_p == NULL )
  {
   printf("Couldn't read input <f_t in> from %s\n",argv[5]);
   exit(1);
  }


 if( fileout_p == NULL )
  {
   printf("Couldn't read output <f_w out> from %s\n",argv[6]);
   exit(1);
  }
 

/********* Calculate other variables ****************************/
 
 dt = T/(NT-1);	
 dw = W/(NW-1);
 
/*** Allocate memory ***/

 dip = (double *)malloc(sizeof(double)*NT);
 dipw = (double *)malloc(sizeof(double)*2*NW);
 
/*** Read in f_t ***/

 input_p = fopen(filein_p,"r");

 if( input_p == NULL)
  {
   printf("Error opening input\n");
   exit(1);	
  }

 for(i=0;i<NT;i++)
  {
   if( fscanf(input_p,"%lf %lf",&tmp,&dip[i]) != 2 )
    {
     printf("Error reading in dipole\n");
     exit(1);	
    } 	
  }

 fclose(input_p);

/*** Do fourier transform ***/

 
 for(i=0;i<NW;i++)
  {
   w = i*dw;

   dipw[2*i] = 0.0;
   dipw[2*i+1] = 0.0;

        
   for(j=0;j<NT;j++)
    {
     t = j*dt;

     ft = 1-3*pow(t/T,2.0)+2*pow(t/T,3.0);

     dipw[2*i] += dip[j]*cos(w*t)*ft;
     dipw[2*i+1] += dip[j]*sin(w*t)*ft;          	

    }
    
   dipw[2*i] *= dt;
   dipw[2*i+1] *= dt;

  }



/*** Output Fourier transform***/

 
 output_p = fopen(fileout_p,"w");
 
 for(i=0;i<NW;i++)
  {
   w = i*dw;
   	
      
   fprintf(output_p,"%lf %3.16f %3.16f %3.16f\n",w,dipw[2*i],dipw[2*i+1],pow(pow(dipw[2*i],2.0)+pow(dipw[2*i+1],2.0),0.5));
   
  }

fclose(output_p);

 

/*** Free the memory ***/

free(dip);
free(dipw);

/*** Exit the code ***/

 exit(0); 
 	
 }
