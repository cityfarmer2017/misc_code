#!/bin/bash

echo -e "this script display all the triangular numbers within a range line by line,
display if it's odd or even on the next line to each triangular number,
then two more lines with the counts of the odd and even numbers respectively,
and finally two more lines with products of the odd numbers and even mubers respectively.\n"

read -p "Enter the value of the range start: " s
read -p "Enter the value of the range end: " e

if ((s >= e)); then
    echo
    echo "wrong input, start should be smaller than end!"
    exit 1
else
    echo
fi

tri_numbers=()
odd_numbers=()
eve_numbers=()
idx=0
idx1=0
idx2=0
product1=1
product2=1

for ((n = 1; ; ++n)); do
    t=$((n * (n+1) / 2))
    if (($t > e)); then
        break;
    fi
    if (($t < s)); then
        continue;
    fi
    tri_numbers[$idx]=$t
    idx+=1;
done

for elm in ${tri_numbers[@]}; do
    echo $elm
    if ((elm % 2)); then
        echo "odd"
        odd_numbers[$idx1]=$elm
        idx1+=1
        product1=$(expr $product1 \* $elm)
    else
        echo "even"
        eve_numbers[$idx2]=$elm
        idx2+=1
        product2=$(expr $product2 \* $elm)
    fi
done

cnt1=${#odd_numbers[@]}
cnt2=${#eve_numbers[@]}

echo
echo "No of odd: $cnt1"
echo "No of even: $cnt2"

echo
if ((cnt1 > 0)); then
    echo "Product of odd: $product1"
fi
if ((cnt2 > 0)); then
    echo "Product of even: $product2"
fi
