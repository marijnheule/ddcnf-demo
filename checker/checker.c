#include <stdio.h>
#include <stdlib.h>


int main (int argc, char** argv) {
  FILE* cnf;
  FILE* sol;

  int tmp, nVar, nCls;

  cnf = fopen (argv[1], "r");
  sol = fopen (argv[2], "r");

  tmp = fscanf (cnf, " p cnf %i %i ", &nVar, &nCls);

  int *model = (int *) malloc (sizeof(int) * (nVar+1));
  for (int i = 1; i <= nVar; i++) model[i] = -1;

  while (1) {
    int lit;
    tmp = fscanf (sol, " %i ", &lit);
    if (tmp == EOF || tmp == 0) break;
    if (lit > 0 && lit <= nVar) {
//      printf ("%i true in model\n", lit);
      model[lit] = 1; }
  }
  fclose (sol);

  int line = 1;
  int sat = 0;
  while (1) {
    int lit;
    tmp = fscanf (cnf, " %i ", &lit);
    if (tmp == EOF) break;
    if (lit == 0) {
      if (sat == 0) {
        printf ("c ERROR: clause %i not satisfied\n", line);
        exit (0); }
//      printf ("c clause %i is satisfied by model\n", line);
      sat = 0;
      line++;
    }
    else {
      if (lit > 0) {
        if (model[ lit] ==  1) sat = 1; }
      else {
        if (model[-lit] == -1) sat = 1; } }
  }

  printf ("s VERIFIED SOLUTION\n");

  exit (1);
}
