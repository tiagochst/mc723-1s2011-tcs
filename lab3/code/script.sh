make

for ((i=0;i<10;i++))
do
	./create
done

python calcSeq.py
python calcFrag.py
python calcHFrag.py
python calcHSeq.py
