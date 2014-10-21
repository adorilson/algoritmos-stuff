for i in {1..8}
do
    cd ../$i
    ./mainapp > ../output/result$i.dat
done
cd ../scripts

