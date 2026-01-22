#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "student.h"

void allocateCategory(double marks, int* noOfStudentsPerCategoryArr){
    if(marks>=90) noOfStudentsPerCategoryArr[0]++;
    else if (marks>=85) noOfStudentsPerCategoryArr[1]++;
    else if (marks>=75) noOfStudentsPerCategoryArr[2]++;
    else if (marks>=65) noOfStudentsPerCategoryArr[3]++;
    else if (marks>=60) noOfStudentsPerCategoryArr[4]++;
    else if (marks>=55) noOfStudentsPerCategoryArr[5]++;
    else if (marks>=50) noOfStudentsPerCategoryArr[6]++;
    else noOfStudentsPerCategoryArr[7]++;
}

char* findGrade(double marks){
    char* grade; 
    if(marks>=90) grade="O";
    else if (marks>=85) grade="A+";
    else if (marks>=75) grade="A";
    else if (marks>=65) grade="B+";
    else if (marks>=60) grade="B";
    else if (marks>=55) grade="C";
    else if (marks>=50) grade="D";
    else grade="F";
    return grade;
}

FILE* openFile(char * fileName){
    printf("function invoked: openFile() for file name %s\n", fileName);
    FILE *fpInp = fopen(fileName, "r");
     if(fpInp != NULL){ 
        printf("file opened successfully\n");
    }else{
        printf("Unable to open input.txt\n");
    }

    return fpInp;
}


bool isMarksValid(double scored, double maxMarks){
    if(scored<0 || scored >maxMarks) return false;
    return true;
}

bool isNameValid(char* name){
    int length = strlen(name);
    for(int i=0; i<length; i++){
        char ch = name[i];
        if((ch<'A' || ch> 'Z') && (ch<'a' || ch> 'z') ){
                printf("ERROR: Invalid Name. Failed at %c. ", ch);
                return false;   
        }
    }
    return true;
}

bool isIdValid(char* id){
    int length = strlen(id);
        for(int i=0; i<length; i++){
        char ch = id[i];
        if((ch<'A' || ch> 'Z') && (ch<'a' || ch> 'z') && (ch<'0' || ch> '9')){
                printf("ERROR: Invalid Id. Failed at %c. Id %s is invalid\n", ch, id);
                return false;   
        }
    }
    printf("");
    return true; 
}

bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr){
    for(int i=0; i<sizeOfIdArr; i++) {
        if(strcasecmp(idArr[i], id)==0){
            printf("ERROR: Duplicate Id Found. msg: more than one students have same id %s\n", id);
            return true;
        }
    }
    return false;
}
