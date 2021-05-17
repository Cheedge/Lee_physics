#!/bin/bash
DIPL=DPLMAT_i01_j
for j in `seq 2 1 21| awk '{printf "%02d\n", $0}'`
do
	awk '{printf "%e	%e	%e\n", $1, $2, $4/$5}' ${DIPL}${j}.OUT > 01j${j}.dat
done
