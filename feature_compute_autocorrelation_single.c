#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  takes in correlation peak file and output file that contains number of peaks and troughs
*/
int 
main(int argc, char **argv) 
{
   FILE *fp
   char *name_file,*ofile_name;
   size_t len=0,len1=0;
   ssize_t read,read1;
   int Count, rv;
   char *line=NULL, *line1=NULL;
   char file_name[1000];
   

   if (argc!=3){
   	fprintf(stderr,
		"Error -check usage\n"
		);
	exit(EXIT_FAILURE);
	}
	name_file = argv[1];
	ofile_name= argv[2];

   fp= fopen(name_file, "r");
   if (fp == NULL){
   	fprintf(stderr,
		"Failed to read from file \'%s\"/\n",
		name_file
		);
	exit(EXIT_FAILURE);
   }
        //read file names
  
   //read = getline(&line, &len, fp);
	//discard header of file
   
   while ((read = getline(&line, &len, fp)) != -1) {
     
       // read name file
	Count=0;
	//discard header
        read1=getline(&line1,&len1, fp);
        while((read1 = getline(&line1, &len1,fp))!= -1){      	 
		Count++;
	}
	fclose(fp);
        
	fp = fopen(ofile_name, "a+");
	   fprintf(fp_input, "number of xxpeaks %d\n", Count);
	fclose(fp);
        printf("number of xxpeaksd %d\n",Count);
	
   }
   
   

   
   return(0);
   
}
