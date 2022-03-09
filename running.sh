#Will spin up and test running the program with diffferent pictures, as well as different copy conts
##pseudocode
#variable
ulimit -m 8192000
#limit memory to 8GB
#clean filedump directory
#start with 250k copies of each file
COPIES=250000
#filenames array
FILES=("sourceimages/john_my_boi_11x11.bmp sourceimages/john_my_boi_25x25.bmp sourceimages/john_my_boi_28x28.bmp sourceimages/john_my_boi_30x30.bmp sourceimages/john_my_boi_32x32.bmp sourceimages/john_my_boi_40x40.bmp sourceimages/john_my_boi_50x50.bmp")
# sourceimages/john_my_boi_144.bmp sourceimages/john_my_boi_240.bmp sourceimages/john_my_boi_480.bmp  sourceimages/john_my_boi_720.bmp sourceimages/john_my_boi_1920.bmp sourceimages/john_my_boi_4k.bmp")
#outputfiles array
OUTPUT=(./perfOutputs/*.out)
#OUTPUT="perfOutputs/0_6kb.out,perfOutputs/2kb.out,perfOutputs/3kb.out,perfOutputs/3_5kb.out,perfOutputs/4kb.out,perfOutputs/4_5kb.out,perfOutputs/10kb.out,perfOutputs/26kb.out,perfOutputs/71kb.out,perfOutputs/285kb.out,perfOutputs/900kb.out,perfOutputs/4500kb.out,perfOutputs/18000kb.out"
#12 total


rm -r files
mkdir files
make clean
make

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done

COPIES=500000

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done

COPIES=1000000

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done

COPIES=2000000

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done


ulimit -m 819200

COPIES=500001

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done

COPIES=1000001

for f in $FILES; do

   (time ./copystorm $f $COPIES) 3>&2 2> "perfOutputs/$COPIES/$f.out"

   rm -r files
   mkdir files
done