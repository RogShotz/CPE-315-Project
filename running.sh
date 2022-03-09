#Will spin up and test running the program with diffferent pictures, as well as different copy conts
##pseudocode
#variable

#clean filedump directory
#run 500,000 copies of each file
COPIES=50



rm -r files
mkdir files
make clean
make

#11x11, 600b
time -o perfOutputs/2kb.out ./copystorm "sourceimages/john my boi_11x11.bmp" $COPIES
rm -r files
mkdir files

#25x25, 2.5kb
time -o perfOutputs/2kb.out ./copystorm "sourceimages/john my boi_25x25.bmp" $COPIES
rm -r files
mkdir files

#28x28, 3kb
time -o perfOutputs/3kb.out ./copystorm "sourceimages/john my boi_28x28.bmp" $COPIES
rm -r files
mkdir files

#30x30, 3.5kb
time -o perfOutputs/3_5kb.out ./copystorm "sourceimages/john my boi_30x30.bmp" $COPIES
rm -r files
mkdir files

#32x32, 4.13kb
time -o perfOutputs/4kb.out ./copystorm "sourceimages/john my boi_32x32.bmp" $COPIES
rm -r files
mkdir files

#40x40, 6.4kb
time -o perfOutputs/4_5kb.out ./copystorm "sourceimages/john my boi_40x40.bmp" $COPIES
rm -r files
mkdir files

#50x50, 10kb
time -o perfOutputs/10kb.out ./copystorm "sourceimages/john my boi_50x50.bmp" $COPIES
rm -r files
mkdir files

#144p, 26kb
time -o perfOutputs/26kb.out ./copystorm "sourceimages/john my boi_144.bmp" $COPIES
rm -r files
mkdir files

#240p, 71kb
time -o perfOutputs/71kb.out ./copystorm "sourceimages/john my boi_240.bmp" $COPIES
rm -r files
mkdir files

#480p, 285kb
time -o perfOutputs/285kb.out ./copystorm "sourceimages/john my boi_480.bmp" $COPIES
rm -r files
mkdir files

#720p, 900kb
time -o perfOutputs/900kb.out ./copystorm "sourceimages/john my boi_720.bmp" $COPIES
rm -r files
mkdir files

#1920p, 4.5MB
time -o perfOutputs/4500kb.out ./copystorm "sourceimages/john my boi_1920.bmp" $COPIES
rm -r files
mkdir files

#4kp, 18MB
time -o perfOutputs/18000kb.out ./copystorm "sourceimages/john my boi_4k.bmp" $COPIES
rm -r files
mkdir files