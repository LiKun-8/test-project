#!/bin/bash  
  
function rand(){  
    min=$1  
    max=$(($2-$min+1))  
    num=$(($RANDOM+1000000000)) #增加一个10位的数再求余  
    echo $(($num%$max+$min))  
}  

for i in {1..141}
do
    rnd=$(rand 1 5)  
    echo $rnd  
done
