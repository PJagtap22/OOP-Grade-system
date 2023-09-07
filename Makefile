CC = g++ 
CFLAG = 


Main.exe : Main.o grading.o 
    $(CC) $(CFLAG) -o Main.exe Main.o grading.o

Main.o : Main.cpp ReportCard.h
    $(CC) $(CFLAG) -c Main.cpp

grading.o: grading.cpp ReportCard.h
    $(CC) $(CFLAG) -c grading.cpp

Clean : 
    rm -f Main.exe *o 
    