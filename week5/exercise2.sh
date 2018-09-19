#!/bin/sh
if [ ! -f foo.txt ]; then
    touch foo.txt
    echo "1" >> foo.txt
fi

while true 
do
     if ! [[ -e file.lock ]]
     then
        ln file file.lock
        break
     fi
done

while true
do
file=`tail -1 foo.txt | head -1`
echo "$file"
file=$((file+1))
echo "$file" >> foo.txt
done


