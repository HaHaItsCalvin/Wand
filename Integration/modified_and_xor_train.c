/*
	
	Modified so there's only 2 inputs instead of 3!!!!

	and_xor_train,c is based on xor_train.c

	compile with:
	gcc -lfann -o and_xor_train and_xor_train.c

	*/

#include <stdio.h>
#include "fann.h"

int FANN_API
test_callback(struct fann *ann, struct fann_train_data *train,
		unsigned int max_epochs, unsigned int epochs_between_reports,
		float desired_error, unsigned int epochs)
{
	printf("Epochs%8d. MSE: %.5f. Desired-MSE: %.5f\n",epochs,fann_get_MSE(ann),desired_error);
	return 0;
}

int main()
{		
	fann_type	*calc_out;
	float	bit_fail_value;
	const unsigned int num_input=4;
	const unsigned int num_output=2;
	unsigned int num_layers=3;
	unsigned int num_neurons_hidden;
	const float	desired_error= (const float) 0;
	const unsigned int max_epochs= 50000;
	const unsigned int epochs_between_reports=10000;
	struct fann *ann;
	struct fann_train_data *data;

	struct	fann_connection *connections;
	unsigned int connection_number;

	unsigned int i=0;
	unsigned int j=0;
	printf("Enter number of neurons in hidden layer\n");
	scanf("%u",&num_neurons_hidden);

	printf("Creating network. \n");
	ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

//~~~~~~~~~~~~START MEMORY ALLOCATION PORTION~~~~~~~~~~~~~	
	//Essential to allocate memory to connections array 
	//before using fann_print_connections_array fuynction
	connection_number=fann_get_total_connections(ann);
	if (connection_number==0){
		printf("ERROR: Connections count is 0. No neural network was made.\n");
		return 0;
	}

	connections= calloc(connection_number,sizeof(*connections));
	if (connections==NULL){
		printf("ERROR: Can't allocate mmory to connections because there are no connectionsn");
		return 0;
	}
//~~~~~~~~~~~~~END MEMORY ALLOCATION PORTION~~~~~~~~~~~~~~~~
	data=fann_read_train_from_file("TrainingFile.txt");

	fann_set_activation_steepness_hidden(ann,1);
	fann_set_activation_steepness_output(ann,1);

	//set the types of activation functions we wish to use, it can be SIGMOID, RELU, or TAH)
	//refer to documentation for correct variable name for FANN_[function]_SYMMETRIC below
	fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
	fann_set_activation_function_output(ann,FANN_SIGMOID_SYMMETRIC);
	fann_set_train_stop_function(ann,FANN_STOPFUNC_BIT);
	
	fann_set_bit_fail_limit(ann, 0.0001);

	fann_set_training_algorithm(ann, FANN_TRAIN_RPROP);

	fann_init_weights(ann,data);

	printf("Training network.\n");
	fann_train_on_data(ann,data,max_epochs,epochs_between_reports,desired_error);
	fann_get_bit_fail_limit(ann);

	printf("Testing network with Bit Fail indicating number of output neurons exceeding"
		"error of %f\n", ann -> bit_fail_limit);

		for(i=0; i< fann_length_train_data(data); i++){
		calc_out=fann_run(ann, data->input[i]);
		printf("AND XOR test (%f, %f, %f, %f) \t-> %f %f\t should be:%f,%f\ndifference 1="
		"%f \t difference 2= %f \t difference 3= %f \n",
		data->input[i][0],data->input[i][1], data->input[i][2],data->input[i][3],
		calc_out[0],calc_out[1],
		data->output[i][0], data->output[i][1],
		fann_abs(calc_out[0] - data->output[i][0]),
		fann_abs(calc_out[1] - data->output[i][1])
		);
//		sleep(3);
		}
//	printf("Produce the connections of the ANN in a matrix\n");
	fann_print_connections(ann);
	
//	printf("Get Connection Array check\n");
	fann_get_connection_array(ann, connections);
//	printf("After Get Connection Array\n");
	
	for (j = 0; j< connection_number; ++j){
		printf("Connection weight from neuron %u to neuron %u: %f\n",
			connections[j].from_neuron,
			connections[j].to_neuron,connections[j].weight);
	}

	printf("Saving network.\n");
	bit_fail_value=fann_get_bit_fail_limit(ann);
	printf("bit fail limit %1.5f\n", bit_fail_value);

	
	fann_save(ann, "and_xor_float.net");
	free(connections);	
	fann_destroy_train(data);
	fann_destroy(ann);

	return 0;
}
