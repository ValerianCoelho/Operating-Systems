#!/bin/bash
#Program Statement: Largest of 3 Numbers

echo 'Enter num 1 : '
read num1

echo 'Enter num 2 : '
read num2

echo 'Enter num 3 : '
read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
    echo $num1 ' is the largest'
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
    echo $num2 ' is the largest'
else
    echo $num3 ' is the largest'
fi
