/*
 *      Modified original bubble sort code;
 *	this no longer sorts. Instead, it
 *	RETURNS XCorr Min,Max,Sum,Norm, Normalized min & max info
 *
 *	Usage:
 *	./XCorr_Peak_Features <INPUT_FILE> <OUTPUT_FILE>
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_SIZE 1024
 
void exchange(float *vec1, float *vec2)
{
    	float tmp = *vec1;
    	*vec1 = *vec2;
    	*vec2 = tmp;
}

void bubble_sort(float vector1[], float vector2[], int n)
{
   	int i, j;
   	for (i = 0; i < n-1; i++){
       		for (j = 0; j < n-i-1; j++){
           	if (vector1[j] > vector1[j+1]){
              		exchange(&vector1[j], &vector1[j+1]);
			exchange(&vector2[j], &vector2[j+1]);
			}
		}
	}
	
}

void norm_vector(float vector[], float *norm, int n)
{
        int i;
        for (i = 0; i < n; i++){
		vector[i] = vector[i]/(*norm);
        }

}

void max_vector(float vector[], float *max, int n)
{
        int i;
	*max = vector[0];	
        for (i = 1; i < n; i++){
		if (*max < vector[i]){
			*max = vector[i];
		}
        }

}

void min_vector(float vector[], float *min, int n)
{	
       	int i;
        *min = vector[0];
        for (i = 1; i < n; i++){
                if (*min > vector[i]){
                        *min = vector[i];
                }
        }
}

int main(int argc, char **argv)
{
	FILE *fp;
        char *ifile_name, *ofile_name;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int N_SAMPLES;

	int vector_length, rv, i;
	float norm, vec_min, vec_max;

	float * time_vector;
	float * amplitude_vector;

	              if (argc != 3) {
                       fprintf(stderr, 
                              "Error - check usage\n"
                              );
                        exit(EXIT_FAILURE);
                }


	ifile_name = argv[1];
        ofile_name = argv[2];

        /* open the input file */
        printf(" Input file \'%s\'.\n", ifile_name);
        fp = fopen(ifile_name, "r");
        if (fp == NULL) {
                fprintf(stderr, 
                                "Failed to read from file \'%s\'.\n", 
                                ifile_name
                       );
                exit(EXIT_FAILURE);
        }

        /* count the number of lines in the file */
        read = getline(&line, &len, fp); //discard header of file
        N_SAMPLES = 0;
        while ((read = getline(&line, &len, fp)) != -1) {
                N_SAMPLES++;
        }

        /* go back to the start of the file so that the data can be read */
        rewind(fp);
        read = getline(&line, &len, fp); //discard header of file

	/* decrement N_SAMPLES to account for header line */

        i = 0;
        time_vector = (float *) malloc(sizeof(float) * N_SAMPLES);
        amplitude_vector  = (float *) malloc(sizeof(float) * N_SAMPLES);
        while ((read = getline(&line, &len, fp)) != -1) {
                /* parse the data */
                rv = sscanf(line, "%f,%f\n", &time_vector[i], &amplitude_vector[i]);
                if (rv != 2) {
                        fprintf(stderr,
                                        "%s %d \'%s\'\n",
                                        "Skip line",
                                        i,
                                        line
                               );
		continue;
                }
                i++;
        }
        fclose(fp);

	vector_length = N_SAMPLES;

    	bubble_sort(time_vector, amplitude_vector, vector_length);

/*	printf("Time Vector Values\n");
    	for (i=0; i < vector_length; i++){
        	printf("%f\n", time_vector[i]);
	}

	printf("Amplitude Vector Values\n");

	for (i=0; i < vector_length; i++){
                printf("%f\n", amplitude_vector[i]);
        }
*/
	norm = time_vector[vector_length-1];

	norm_vector(time_vector, &norm, vector_length);
/*
        printf("Time Vector Values Normalized\n");
        for (i=0; i < vector_length; i++){
                printf("%f\n", time_vector[i]);
        }
*/
	min_vector(amplitude_vector, &vec_min, vector_length);
	max_vector(amplitude_vector, &vec_max, vector_length);
	
	printf("min %f max %f\n", vec_min, vec_max);
	norm = vec_max - vec_min;
	norm_vector(amplitude_vector, &norm, vector_length);
	float sum= vec_max + vec_min;
	printf("Sum of Max & Min %f\n",sum);
 	printf("Normalization Value %f\n",norm);
 	
	printf("Normalized min %f max %f\n", vec_min/norm, vec_max/norm);

/*Open file for writing*/
	fp=fopen(ofile_name,"w");
	if (fp==NULL){
		fprintf(stderr,
				"ERROR Failed to WRITE to file \'%s\'.\n",
				ofile_name
			);
		exit(EXIT_FAILURE);
	}
/*Write the values into the file*/
	fprintf (fp, "Min Value & MAX Value \n");
	fprintf(fp,"%f %f\n", vec_min, vec_max);
	fprintf(fp,"Sum of MAX & MIN\n");
	fprintf(fp,"%f\n",sum);
	fprintf(fp,"Normalization Value\n");
	fprintf(fp,"%f\n",norm);
	fprintf(fp,"Normalized Min & MAX\n");
	fprintf(fp,"%f %f\n",vec_min/norm,vec_max/norm);

	fclose(fp);
	return 0;
}


//THE code below is from the original sorting algorithm used to open a file
//and print out normalized time & amplitude values

/*      printf("Amplitude Vector Values Normalized\n");
        for (i=0; i < vector_length; i++){
                printf("%f\n", amplitude_vector[i]);
        }
*/
        /* open the output file to write the x axis data */
 /*
 	printf("Sorted and normalized data file \'%s\'.\n", ofile_name);
        fp = fopen(ofile_name, "w");
        if (fp == NULL) {
                fprintf(stderr, 
                                "Failed to write to file \'%s\'.\n", 
                                ofile_name
                       );
                exit(EXIT_FAILURE);
        }
*/
	/* Write output data at offset 1 to ignore zero entry */
/*
        fprintf(fp, "Normalized Time and Amplitude\n");
        for (i = 1; i < vector_length; i++) {
                fprintf(fp, "%f, %f\n",
                                time_vector[i],
                                amplitude_vector[i]
                       );
        }
        fclose(fp);


    	return 0;
}
*/


