#!/bin/bash

for i in `seq 2 1 3| awk '{printf "%02d\n", $0}'`
do
	for j in `seq 4 1 5|awk '{printf "%02d\n", $0}'`
	do
		cp ${i}j${j}.dat temp.dat
		python3.7 Interpolat_imshow.py
		mv Interpolat_imshow.png ${i}_to_$j.png
		rm temp.dat
	done
done
for j in `seq 6 1 21|awk '{printf "%02d\n", $0}'`
do
	cp "05j"${j}.dat temp.dat
	python3.7 Interpolat_imshow.py
	mv Interpolat_imshow.png 5_to_$j.png
	rm temp.dat
done
