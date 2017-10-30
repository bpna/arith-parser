#!/bin/sh

RAW_SCORES=`cat index.html | grep -E '<td>student-NR ' | cut -d ">" -f2 | cut -d "%" -f1`
echo $RAW_SCORES | ~/comp
