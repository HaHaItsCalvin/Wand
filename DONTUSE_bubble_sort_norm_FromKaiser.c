/*
 *      Perform bubble sort on two vector pairs where
 *      first vector, time_vector value determine
 *      sort order from minimum to maximum value
 *
 *	Time values are normalized to difference between 
 *	maximum and minimum values
 *
 *      Amplitude values are normalized to difference between 
 *      maximum and minimum values
 *
 *	Usage:
 *	./bubble_sort_norm <INPUT_FILE1> <OUTPUT_FILE1> <INPUT_FILE2> <OUTPUT_FILE2>
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
	FILE *fp,*fp1;
        char *ifile_name, *ofile_name, *ifile_name1, *ofile_name1;
        char *line = NULL, *line1=NULL;
        size_t len = 0, len1=0;
        ssize_t read,read1;
        int N_SAMPLES, N_SAMPLES1;

	int vector_length, rv, i;
    int vector_length1, rv1, i1;
    float norm, vec_min, vec_max;
    float norm1, vec_min1, vec_max1;

	float * time_vector, * time_vector1;
	float * amplitude_vector, *amplitude_vector1;

	              if (argc != 5) {
                       fprintf(stderr, 
                              "Error - check usage\n"
                              );
                        exit(EXIT_FAILURE);
                }


	ifile_name = argv[1];
        ofile_name = argv[2];
        ifile_name1 = argv[3];
        ofile_name1= argv[4];

        /* open the input file */
        printf(" Input file \'%s\'.\n", ifile_name ,"\n", ifile_name1);
        fp = fopen(ifile_name, "r");
        if (fp == NULL) {
                fprintf(stderr, 
                                "Failed to read from file \'%s\'.\n", 
                                ifile_name
                       );
                exit(EXIT_FAILURE);
        }
        
	fp1= fopen(ifile_name1, "r");
        if (fp1 == NULL) {
        fprintf(stderr,
                "Failed to read from file \'%s\'.\n",
                ifile_name1
                );
        exit(EXIT_FAILURE);
        }
    
    
    
        /* count the number of lines in the file */
        read = getline(&line, &len, fp); //discard header of file
        N_SAMPLES = 0;
        while ((read = getline(&line, &len, fp)) != -1) {
                N_SAMPLES++;
        }
    
        read1 = getline(&line1, &len1, fp1); //discard header of file
        N_SAMPLES1= 0;
        while ((read1 = getline(&line1, &len1, fp1)) != -1) {
                N_SAMPLES1++;
        }
    
    
        /* go back to the start of the file so that the data can be read */
        rewind(fp);
        read = getline(&line, &len, fp); //discard header of file
        rewind(fp1);
        read1 = getline(&line1, &len1, fp1);
	
    
    /* decrement N_SAMPLES to account for header line */
    
    // file 1

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

	printf("Time Vector Values\n");
    	for (i=0; i < vector_length; i++){
        	printf("%f\n", time_vector[i]);
	}

	printf("Amplitude Vector Values\n");

	for (i=0; i < vector_length; i++){
                printf("%f\n", amplitude_vector[i]);
        }

	norm = time_vector[vector_length-1];

	norm_vector(time_vector, &norm, vector_length);

        printf("Time Vector Values Normalized\n");
        for (i=0; i < vector_length; i++){
                printf("%f\n", time_vector[i]);
        }

	min_vector(amplitude_vector, &vec_min, vector_length);
	max_vector(amplitude_vector, &vec_max, vector_length);
	
	printf("min %f max %f\n", vec_min, vec_max);
    printf("Normalization Value%f\n",norm);
	norm = vec_max - vec_min;
	norm_vector(amplitude_vector, &norm, vector_length);
        printf("Amplitude Vector Values Normalized\n");
        for (i=0; i < vector_length; i++){
                printf("%f\n", amplitude_vector[i]);
        }

    
    // file 2
    
    i1 = 0;
    time_vector1 = (float *) malloc(sizeof(float) * N_SAMPLES1);
    amplitude_vector1  = (float *) malloc(sizeof(float) * N_SAMPLES1);
    while ((read1 = getline(&line1, &len1, fp1)) != -1) {
        /* parse the data */
        rv1 = sscanf(line1, "%f,%f\n", &time_vector1[i1], &amplitude_vector1[i1]);
        if (rv1 != 2) {
            fprintf(stderr,
                    "%s %d \'%s\'\n",
                    "Skip line",
                    i1,
                    line1
                    );
            continue;
        }
        i1++;
    }
    fclose(fp1);
    
    vector_length1 = N_SAMPLES1;
    
    bubble_sort(time_vector1, amplitude_vector1, vector_length1);
    
    printf("Time Vector2 Values\n");
    for (i1=0; i1 < vector_length1; i1++){
        printf("%f\n", time_vector1[i1]);
    }
    
    printf("Amplitude Vector2 Values\n");
    
    for (i1=0; i1 < vector_length1; i1++){
        printf("%f\n", amplitude_vector1[i1]);
    }
    
    norm1 = time_vector1[vector_length1-1];
    
    norm_vector(time_vector1, &norm1, vector_length1);
    
    printf("Time Vector2 Values Normalized\n");
    for (i1=0; i1 < vector_length1; i1++){
        printf("%f\n", time_vector1[i1]);
    }
    
    min_vector(amplitude_vector1, &vec_min1, vector_length1);
    max_vector(amplitude_vector1, &vec_max1, vector_length1);
    
    printf("min2 %f max2 %f\n", vec_min1, vec_max1);
    norm1 = vec_max1 - vec_min1;
    norm_vector(amplitude_vector1, &norm1, vector_length1);
    printf("Amplitude Vector2 Values Normalized\n");
    for (i1=0; i1 < vector_length1; i1++){
        printf("%f\n", amplitude_vector1[i1]);
    }
    
    
    /* open the two output files to write the x axis data */
        printf("Sorted and normalized data file \'%s\'.\n", ofile_name);
        fp = fopen(ofile_name, "w");
        if (fp == NULL) {
                fprintf(stderr, 
                                "Failed to write to file \'%s\'.\n", 
                                ofile_name
                       );
                exit(EXIT_FAILURE);
        }

	
        printf("Sorted and normalized data file \'%s\'.\n", ofile_name1);
        fp1 = fopen(ofile_name1, "w");
        if (fp1 == NULL) {
            fprintf(stderr,
                "Failed to write to file \'%s\'.\n",
                ofile_name1
                );
            exit(EXIT_FAILURE);
        }
    
    
    
    /* Write output data at offset 1 to ignore zero entry */

        fprintf(fp, "Normalized Time and Amplitude\n");
        for (i = 0; i < vector_length; i++) {
        	if(amplitude_vector[i] ==0 && i==0 || i==0 && amplitude_vector== -0)
			i=1;
		fprintf(fp, "%f, %f\n",
                                time_vector[i],
                                amplitude_vector[i]
                       );
        }
        fclose(fp);
    
    
        fprintf(fp1, "Normalized Time and Amplitude\n");
        for (i1 = 0; i1 < vector_length1; i1++) {
		if(amplitude_vector1[i1]== 0 && i1==0 || i1==0 && amplitude_vector1[i1]== -0)
			i1=1;
            fprintf(fp1, "%f, %f\n",
                    time_vector1[i1],
                    amplitude_vector1[i1]
                    );
        }
        fclose(fp1);

    
    
    return 0;
}

