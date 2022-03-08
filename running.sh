#Will spin up and test running the program with diffferent pictures, as well as different copy conts
##pseudocode
#variable

#clean filedump directory
#run 500,000 copies of each file
COPIES=500000



rm files/*
make clean
make

#11x11, 600b
perfperf stat ./copystorm "sourceimages/john my boi_11x11.bmp" $COPIES 1> outfile.temp 2> perfOutputs/2kb.out
rm files/*

#25x25, 2.5kb
perf stat ./copystorm "sourceimages/john my boi_25x25.bmp" $COPIES 1> outfile.temp 2> perfOutputs/2kb.out
rm files/*

#28x28, 3kb
perf stat ./copystorm "sourceimages/john my boi_28x28.bmp" $COPIES 1> outfile.temp 2> perfOutputs/3kb.out
rm files/*

#30x30, 3.5kb
perf stat ./copystorm "sourceimages/john my boi_30x30.bmp" $COPIES 1> outfile.temp 2> perfOutputs/3_5kb.out
rm files/*

#32x32, 4.13kb
perf stat ./copystorm "sourceimages/john my boi_32x32.bmp" $COPIES 1> outfile.temp 2> perfOutputs/4kb.out
rm files/*

#40x40, 6.4kb
perf stat ./copystorm "sourceimages/john my boi_40x40.bmp" $COPIES 1> outfile.temp 2> perfOutputs/4_5kb.out
rm files/*


#50x50, 10kb
perf stat ./copystorm "sourceimages/john my boi_50x50.bmp" $COPIES 1> outfile.temp 2> perfOutputs/10kb.out
rm files/*

#144p, 26kb
perf stat ./copystorm "sourceimages/john my boi_144.bmp" $COPIES 1> outfile.temp 2> perfOutputs/26kb.out
rm files/*

#240p, 71kb
perf stat ./copystorm "sourceimages/john my boi_240.bmp" $COPIES 1> outfile.temp 2> perfOutputs/71kb.out
rm files/*

#480p, 285kb
perf stat ./copystorm "sourceimages/john my boi_480.bmp" $COPIES 1> outfile.temp 2> perfOutputs/285kb.out
rm files/*

#720p, 900kb
perf stat ./copystorm "sourceimages/john my boi_720.bmp" $COPIES 1> outfile.temp 2> perfOutputs/900kb.out
rm files/*

#1920p, 4.5MB
perf stat ./copystorm "sourceimages/john my boi_1920.bmp" $COPIES 1> outfile.temp 2> perfOutputs/4500kb.out
rm files/*

#4kp, 18MB
perf stat ./copystorm "sourceimages/john my boi_4k.bmp" $COPIES 1> outfile.temp 2> perfOutputs/18000kb.out
rm files/*
