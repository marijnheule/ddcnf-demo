# ddcnf-demo
Demo of delta debugging for CNF formulas

# introduction

The repository contains a buggy version of the SAT
solver CaDiCaL. The file buggy-cadical/src/cadical.cpp
was modified to incorrectly print the solution by 
adding a line to the App::print_witness procedure:

  if (tmp % 100 == 33) tmp = -tmp; // bug

The demo shows the effectiveness of the delta
debugger to find this bug.

# installation and running

First compile all the sources:

  ./init.sh

Afterwards run the demo code

  ./demo.sh


# demo output

The demo first runs the buggy CaDiCaL on a graph 
coloring problem 2550 variables and 13030 clauses

++ ./run.sh cnf/510-5.cnf
c ERROR: clause 47 not satisfied

Afterwards it runs the delta debugger to reduce
the size of the formula. The tool produces a 
smaller formula called output.cnf with only just
one clause. It produces the same ERROR.

++ cat output.cnf
p cnf 2550 1
33 0
++ ./run.sh output.cnf
c ERROR: clause 1 not satisfied


