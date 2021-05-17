#!/bin/bash
i1=01
for j in `seq 2 1 21|awk '{printf "%02d\n", $0}'`
do
	cp ${i1}j${j}.dat temp.dat
	python3.7 Interpolat_imshow.py
	mv Interpolat_imshow.png ${i1}to$j.png
	rm temp.dat
done
for i in `seq 2 1 3| awk '{printf "%02d\n", $0}'`
do
	for j in `seq 4 1 21|awk '{printf "%02d\n", $0}'`
	do
		cp ${i}j${j}.dat temp.dat
		python3.7 Interpolat_imshow.py
		mv Interpolat_imshow.png ${i}to$j.png
		rm temp.dat
	done
done
for j in `seq 5 1 21|awk '{printf "%02d\n", $0}'`
do
	cp "04j"${j}.dat temp.dat
	python3.7 Interpolat_imshow.py
	mv Interpolat_imshow.png 04to$j.png
	rm temp.dat
done
for j in `seq 6 1 21|awk '{printf "%02d\n", $0}'`
do
	cp "05j"${j}.dat temp.dat
	python3.7 Interpolat_imshow.py
	mv Interpolat_imshow.png 05to$j.png
	rm temp.dat
done
