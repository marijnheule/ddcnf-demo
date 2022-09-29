CNF=$1

./buggy-cadical/build/cadical $CNF > output-$$.txt
RES=`cat output-$$.txt | awk '/^s / {print $2}'`
if [ $RES == "SATISFIABLE" ]
then
  cat output-$$.txt | grep "^v " | sed 's|v ||g' > tmp-$$.sol
  ./checker/checker $CNF tmp-$$.sol
  RESULT=$?
  rm output-$$.txt tmp-$$.sol
  exit $RESULT
else # take care of the UNSAT case
  rm output-$$.txt tmp-$$.sol
  exit 20 # exit code for UNSATISFIABLE
fi

