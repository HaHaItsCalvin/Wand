#!/bin/sh

echo "what motion? all lowercase ex: patronus,disarm"
read motion
echo "how many times do we run this?"
read end

if [ ! -d "~/Wand/"$motion"/Xcorr_data" ]; then
mkdir ~/Wand/"$motion"/Xcorr_data
fi

if [ ! -d "~/Wand/Data_Graphs/"$motion"" ]; then
mkdir ~/Wand/Data_Graphs/"$motion"
fi

i=1

while [ $i -lt $(($end+1)) ]
do

sh all_compute_cross_correlation.sh ~/Wand/"$motion"/Motion_data/"$motion"_motion_$i ~/Wand/"$motion"/Motion_data/"$motion"_motion_$i 20
cp xcorr_output.csv ~/Wand/"$motion"/Xcorr_data/"$motion"_xcorr_$i

cp xcorr_autocorr_plot.png ~/Wand/Data_Graphs/"$motion"/"$motion"_autocorr_graph_"$i".png
cp xcorr_cross_corr_file_1_x_axis-file_2_z_axis_plot.png ~/Wand/Data_Graphs/"$motion"/"$motion"_xcorr_graph_"$i".png

i=$(($i+1))

done
