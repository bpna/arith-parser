#!/bin/sh

cat index.html | grep "<td><em>" | cut -d "<" -f3 | cut -d ">" -f2 | uniq
