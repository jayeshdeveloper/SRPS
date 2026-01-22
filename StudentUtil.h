#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "student.h"

char* findGrade(double marks);
void allocateCategory(double marks, int* noOfStudentsPerCategoryArr);

FILE* openFile(char * fileName);
bool isMarksValid(double scored, double maxMarks);
bool isNameValid(char* name);
bool isIdValid(char* id);
bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr);
