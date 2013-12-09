#!/bin/bash

input[0]=1
input[1]=7
input[2]=12
input[3]=19

expected[0]=1
expected[1]=6
expected[2]=4
expected[3]=18

for i in {0..3}
do
	#echo ${input[$i]}
	output=$(./EulerTotient ${input[$i]})

	result="Input: ${input[$i]}, expected: ${expected[$i]}, output: $output" 
	if [ "$output" -eq "${expected[$i]}" ]; then
		result="$result, CORRECT!"
	fi

	echo $result
	
done
