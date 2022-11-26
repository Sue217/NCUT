clear
gcc -o test getb.c fixsize.c finde.c print.c fs.c main.c -std=c11 -Wall -Werror
./test > result.txt
