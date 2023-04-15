exeFile = main
sourceFile = main.c 
exeFileRm = main.exe


all:
	gcc -o $(exeFile) SUDOKU.h SUDOKU.c stdTypes.h conio.c conio.h $(sourceFile)
	./$(exeFile) 
	del $(exeFileRm)

# gcc -o main myBasics.c myArray.c myString.c struct.c stack.c queue.c main.c 
# ./main
# rm main

#run:
#	./$(exeFile)	

#clean:
#    rm $(exeFile)
