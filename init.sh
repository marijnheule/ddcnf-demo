cd cnfdd
gcc cnfdd.c -O2 -o ddcnf
cd ..
cd buggy-cadical
./configure; make;
cd ..
cd checker
gcc checker.c -O2 -std=c99 -o checker
cd ..
