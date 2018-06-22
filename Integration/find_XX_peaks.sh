#!/bin/sh

#
# Usagei: enter input file name and peak find threshold values for X  
#


if [ "$#" -ne 2 ]; then
	    echo "Enter Input File Name and X and Y axis peak find threshold"
	    exit
    fi

gcc -o 1XX_peak_find 1XX_peak_find.c -lm

./1XX_peak_find $1 waveform_peaks_output_XX.csv waveform_gnuplot_x.csv $2 
gnuplot ZZ_gnuplot_script
sudo cp zz_plot.png /var/www/html/graphics 
echo "If no error is reported, view the plot image at http://<Beaglebone IP Address>:8080/graphics/zz_plot.png"

