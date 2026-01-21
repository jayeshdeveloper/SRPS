#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "StudentUtil.h"
#include "RegisterStudent.h"
#include "Printers.h"
#define MAX 100;

/* JAYESH JAISWAL MTECH CS
    input.txt format
    40 (shows no. of students)
    25ABC01 Jayesh 18 72 20 68 15 19 17 75 19 80 => detais of individual student, where  values are:
        id, 
        name, 
        minor marks of 5 subjects (out of 40)
        major marks of 5 subjects (out of 60)
*/

FILE* openFile(char *);

bool isMarksValide(double scored, double maxMarks);
bool isNameValid(char* name);
bool isIdValid(char* id);
bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr);

int main(){  
    int noOfStudents; 
    Student* arrStudents[100]; 
    noOfStudents = registerStudents(noOfStudents, arrStudents);
    printFinalReport(arrStudents, noOfStudents);
}






