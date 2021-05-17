#!/bin/bash
DIPL=01j
for j in `seq 2 1 21| awk '{printf "%02d\n", $0}'`
do
	sed -n '1p' $DIPL$j.dat | awk '{printf "%e\n", $3}' >> Gamma.dat
	sed -n '16p' $DIPL$j.dat | awk '{printf "%e\n", $3}' >> Mdian.dat
	sed -n '91p' $DIPL$j.dat | awk '{printf "%e\n", $3}' >> Kdian.dat
done

