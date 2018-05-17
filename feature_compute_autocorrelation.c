#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*  takes in correlation peak file and output file that contains number of peaks and troughs
*/
int 
main(int argc, char **argv) 
{
   FILE *fp, *fp_input;
   char *name_file,*ofile_name;
   size_t len=0,len1=0;
   ssize_t read,read1;
   int Count, rv;
   int i;
   float Amp[2];
   float diff;
   float dummy;
   char *line=NULL, *line1=NULL;
   char file_name[1000];
   

   if (argc!=3){
   	fprintf(stderr,
		"Error -check usage\n"
		);
	exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	name_file_M = argv[1];    //first motion peak file, second correlation peak file
	name_file_X = argv[2];
	ofile_name= argv[3];



    // read name_file_M
   fp= fopen(name_file_M, "r");
=======
	name_file = argv[1;
	ofile_name= argv[2];

   fp= fopen(name_file, "r");
>>>>>>> 02881de68f9c977dfcc220c4d4ebd2e0744b3a39
   if (fp == NULL){
   	fprintf(stderr,
		"Failed to read from file \'%s\"/\n",
		name_file
		);
	exit(EXIT_FAILURE);
   }
        //read file names
   
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
	i=0;
	//discard header
        read1=getline(&line1,&len1, fp_input);
        while((read1 = getline(&line1, &len1,fp_input))!= -1){
		if(Count <2)
		{
		 scanf("%[^,], %e",dummy,Amp[i]);  //read in the first two amplitude
		 i++;
		}
		
		Count++;
	}
	fclose(fp_input);
        
        diff=Amp[1]-Amp[0];
	fp_input = fopen(ofile_name, "a+");
	   fprintf(fp_input, "%10d%10e\n", Count,diff); //first peak number,second difference
	fclose(fp_input);
	
   }
   
   fclose(fp);
  
  //rewind output file
   fp_input=fopen(ofile_name, "a+");
   rewind(fp_input);
   fclose(fp_input);

  // read name_file_X

  fp= fopen(name_file_X, "r");
     if (fp == NULL){
             fprintf(stderr,
	                     "Failed to read from file \'%s\"/\n",
			                     name_file_X
                      );
	exit(EXIT_FAILURE);
   }
  
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
												Count=0;												               //discard header
																						               read1=getline(&line1,&len1, fp_input);																			               while((read1 = getline(&line1, &len1,fp_input))!= -1){						        Count++;																				               }
 													fclose(fp_input);
	fp_input = fopen(ofile_name, "a+");
	fprintf(fp_input, "30%d\n", Count);  //third correlation peaks
        fclose(fp_input);																		 }				
   fclose(fp);


   return(0);
   
}
