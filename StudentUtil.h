#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "student.h"

void printArrOfStudent(Student* arrStudents[], int noOfStudents);
double printStudent(Student* student);
char* findGrade(double marks);
void allocateCategory(double marks, int* noOfStudentsPerCategoryArr);

FILE* openFile(char * fileName);
bool isMarksValide(double scored, double maxMarks);
bool isNameValid(char* name);
bool isIdValid(char* id);
bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr);
