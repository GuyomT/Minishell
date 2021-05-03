#!/bin/sh

cat <<EOF > list_cmd
    ls -l
    sleep 2
    /bin/pwd
EOF

cat list_cmd | tcsh 2>&1 > tcsh.result
cat list_cmd | ./mysh 2>&1 > mysh.result

diff tcsh.result mysh.result
if [ $? -eq 0 ]
then
    echo "Resultat identiques \o/ !"
else
    echo "Raté =/ !"
fi