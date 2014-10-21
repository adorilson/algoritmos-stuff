for i in {1..8}
do
    cd ../$i
    make
    make clean
done
cd ../scripts

