rm -f output.txt
make
for i in {1..10}
do
 /usr/bin/time -p -a --output=output.txt ./run >/dev/null 
done
python calc.py
make clean
