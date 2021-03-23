all: mult-C.exe mult-C-A.exe
    
mult-C.exe:mult-C.o
		gcc -o mult-C mult-C.o

mult-C.o:mult.c
		gcc -c mult.c

mult-C-A.exe:mult-C-A.o mulMatriz.o
		gcc -o mult-C-A mult-C-A.o mulMatriz.o

mult-C-A.o:mulMatriz.s
		gcc -c mult-C-A.c   

mulMatriz.o:mulMatriz.s
		as -o mulMatriz.o mulMatriz.s

clean:
		rm *.o
		rm mult-C.exe 
		rm mult-C-A.exe