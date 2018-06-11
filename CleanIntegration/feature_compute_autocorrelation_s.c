#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*  takes in correlation peak file and output file that contains number of peaks and troughs
*/
int 
main(int argc, char **argv) 
{
   FILE *fp;
   char *name_file,*ofile_name;
   size_t len=0,len1=0;
   ssize_t read;
   int Count, rv;
   int i;
   float Amp[2];
   float diff;
   float dummy;
   char *line=NULL;
   
   

   if (argc!=3){
   	fprintf(stderr,
		"Error -check usage\n"
		);
	exit(EXIT_FAILURE);
	}
	name_file= argv[1];    
	ofile_name= argv[2];



    // read name_file
   fp= fopen(name_file, "r");
   if (fp == NULL){
   	fprintf(stderr,
		"Failed to read from file \'%s\"/\n",
		name_file
		);
	exit(EXIT_FAILURE);
   }
        //read file names
   //discard header
   Count=0;
   read=getline(&line,&len, fp);

        while ((read = getline(&line, &len, fp)) != -1) {
        	float time_hold;
		float amp_hold;
                //rv = sscanf(line, "%f, %f\n", &time_vector[i], &amplitude_vector[i]);
                rv = sscanf(line, "%f, %f\n", &time_hold, &amp_hold);
                if (rv != 2) {
                        fprintf(stderr,
                                        "%s %d \'%s\'\n",
                                        "Skip line",
                                        i,
                                        line
                               );
			continue;
                }
		else{
			Count++;
		}
                i++;
        }
        fclose(fp);
       
        fp=fopen(ofile_name, "a+");     
	fprintf(fp, "Number of xxpeaks is: %d\n", Count);  
	fclose(fp);							
	
   printf("Number of xxpeaks is: %d\n",Count);	
					

   return(0);
   
}
