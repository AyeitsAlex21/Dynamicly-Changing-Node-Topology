#!/bin/bash
TestData=TPCH_Test


rm -drf TPCH_Test

cd tpch-dbgen

mkdir -p "$TestData"
mkdir -p "$TestData"/Data
mkdir -p "$TestData"/Query

#DATASET GEN
./dbgen -s 0.01 -f
mv *.tbl "$TestData"/Data

#QUERIES
for i in {1..22}
do
    cp queries/"$i".sql .
    ./qgen $i > "$TestData"/Query/q${i}.sql
    rm "$i".sql
done

mv "$TestData" ..
cd ..