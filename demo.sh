set -x

./run.sh cnf/510-5.cnf

./cnfdd/ddcnf cnf/510-5.cnf output.cnf ./run.sh

cat output.cnf

./run.sh output.cnf
