/*
Fast Artificial Neural Network Library (fann)
Copyright (C) 2003-2016 Steffen Nissen (steffen.fann@gmail.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>

#include "fann.h"

int main()
{
	float diff1;
	float diff2;
	float thresh=0.2;
	float bin0=0;
	float bin1=1;
	float bin0LOW=(bin0-thresh);
	float bin0HIGH=(bin0+thresh);
	float bin1LOW=(bin1-thresh);
	float bin1HIGH=(bin1+thresh);

	fann_type *calc_out;
	unsigned int i;
	int ret = 0;

	struct fann *ann;
	struct fann_train_data *data;

	printf("Creating network.\n");

//#ifdef FIXEDFANN
//	ann = fann_create_from_file("xor_fixed.net");
//#else
	ann = fann_create_from_file("and_xor_float.net");
//#endif

	if(!ann)
	{
		printf("Error creating ann --- ABORTING.\n");
		return -1;
	}

	fann_print_connections(ann);
	fann_print_parameters(ann);

	printf("Testing network.\n");

//#ifdef FIXEDFANN
//	data = fann_read_train_from_file("xor_fixed.data");
//#else
	data = fann_read_train_from_file("TestFile.txt");
//#endif

	for(i = 0; i < fann_length_train_data(data); i++)
	{
		fann_reset_MSE(ann);
		calc_out = fann_test(ann, data->input[i], data->output[i]);
/*
#ifdef FIXEDFANN
		printf("XOR test (%d, %d) -> %d, should be %d, difference=%f\n",
			   data->input[i][0], data->input[i][1], calc_out[0], data->output[i][0],
			   (float) fann_abs(calc_out[0] - data->output[i][0]) / fann_get_multiplier(ann));

		if((float) fann_abs(calc_out[0] - data->output[i][0]) / fann_get_multiplier(ann) > 0.2)
		{
			printf("Test failed\n");
			ret = -1;
		}
#else
*/
		printf("AND_XOR test (%f, %f, %f)-> (%f %f) should be (%f %f)\n difference1=%f difference2=%f\n",
			   data->input[i][0], data->input[i][1], data->input[i][2],
			   calc_out[0], calc_out[1],
			   data->output[i][0], data->output[i][1],
			  diff1= (float) fann_abs(calc_out[0] - data->output[i][0]),
			  diff2= (float) fann_abs(calc_out[1] - data->output[i][1])
			   );
//#endif
	}
	if (calc_out[0]>=bin0LOW && calc_out[0]<=bin0HIGH && calc_out[1]>=bin0LOW && calc_out[1]<=bin0HIGH)
		printf("Shrinking Motion was used");
	else if (calc_out[0] >=bin0LOW && calc_out[0] <=bin0HIGH && calc_out[1]>=bin1LOW &&calc_out[1]<=bin1HIGH)
		printf("Disarm Motion was used");
	else if (calc_out[0]>=bin1LOW && calc_out[0]<=bin1HIGH && calc_out[1]>=bin0LOW && calc_out[1]<=bin1HIGH)
		printf("Aquamenete Motion was used");
	else if (calc_out[0]>=bin1LOW && calc_out[0]<=bin1HIGH && calc_out[1]>=bin1LOW && calc_out[1]<=bin1HIGH)
		printf("Patronus Motion was used");
	else
		printf("ERROR: Motion isn't easily distinguishable; all threshold were surpassed");
	printf("Cleaning up.\n");
	fann_destroy_train(data);
	fann_destroy(ann);

	return ret;
}
