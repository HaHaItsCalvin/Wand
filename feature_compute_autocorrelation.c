#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  takes in correlation peak file and output file that contains number of peaks and troughs
*/
int 
main(int argc, char **argv) 
{
   FILE *fp, *fp_input;
   char *name_file_M,*name_file_X,*ofile_name;
   size_t len=0,len1=0;
   ssize_t read,read1;
   int Count, rv;
   char *line=NULL, *line1=NULL;
   char file_name[1000];
   

   if (argc!=4){
   	fprintf(stderr,
		"Error -check usage\n"
		);
	exit(EXIT_FAILURE);
	}
	name_file_M = argv[1]
	name_file_X = argv[2];
	ofile_name= argv[3];

   fp= fopen(name_file_M, "r");
   if (fp == NULL){
   	fprintf(stderr,
		"Failed to read from file \'%s\"/\n",
		name_file_M
		);
	exit(EXIT_FAILURE);
   }
        //read file names
  
   //read = getline(&line, &len, fp);
	//discard header of file
   
   while ((read = getline(&line, &len, fp)) != -1) {
     
       // read name file
        rv= sscanf(line, "%s",file_name);
        fp_input= fopen(file_name, "r");
	if (fp_input == NULL){
	        fprintf(stderr,
		"Failed to read from file '%s'\n",
		 file_name
						                );
	  exit(EXIT_FAILURE);
	  }
	Count=0;
	//discard header
        read1=getline(&line1,&len1, fp_input);
        while((read1 = getline(&line1, &len1,fp_input))!= -1){      	 
		Count++;
	}
	fclose(fp_input);
        
	fp_input = fopen(ofile_name, "a+");
	   fprintf(fp_input, "%d\n", Count);
	fclose(fp_input);
	
   }
   
   fclose(fp);

   
   return(0);
   
}
