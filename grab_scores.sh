#!/bin/sh

if $1="nc"
then
    echo "hello"
fi

RAW_SCORES=`cat index.html | grep -E '<td>students ' | cut -d ">" -f2 | cut -d "%" -f1`
echo $RAW_SCORES | ~/div
