#!/bin/sh

#
# Usagei: enter input file name and peak find threshold values for X,Y, and Z axes 
#

gcc -o all_waveform_peaks_find all_waveform_peaks_find.c
if [ "$#" -ne 4 ]; then
	    echo "Enter Input File Name and X and Y and Z axis peak find threshold"
	    exit
    fi

./all_waveform_peaks_find $1 waveform_peaks_output_x.csv waveform_gnuplot_x.csv waveform_peaks_output_y.csv waveform_gnuplot_y.csv waveform_peaks_output_z.csv waveform_gnuplot_z.csv $2 $3 $4
gnuplot waveform_gnuplot_script
sudo cp waveform_plot.png /var/www/html/graphics 
#echo "If no error is reported, view the plot image at http://<Beaglebone IP Address>:8080/graphics/waveform_plot.png"

