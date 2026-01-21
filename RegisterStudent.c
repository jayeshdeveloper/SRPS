#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "StudentUtil.h"

int registerStudents(int noOfStudents, Student** arrStudents){
    // printf("Method invocked: registerStudents()\n");
      FILE * fpInp  = openFile("input.txt");
    // FILE * fpInp  = openFile("invalidInput.txt");
     
    fscanf(fpInp, "%d", &noOfStudents);
    printf("Number of students are:%d\n", noOfStudents);
    char* idArr[noOfStudents];

  
    char* arrSubjects[] = {"IOT", "BCT", "OS", "CN", "DDPC"};

    bool isAnyError=false;
 
    for(int i=0; i<noOfStudents; i++){
        Student* student = (Student*) malloc(sizeof(Student));
        char *id = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", id);
        student->id=id;
        
        if(!isIdValid(id) || isDuplicateId(idArr, id, i)) isAnyError=true;
        idArr[i]=id;

        char *name = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", name);
        student->name=name;
        if(!isNameValid(name)){
            printf("msg: student with id %s has invalid name \"%s\". \n", id, name);
            isAnyError=true;
        }

        for(int j=0; j<5; j++){
            fscanf(fpInp, "%lf", &student->minor[j]);
            if(!isMarksValide(student->minor[j],40.0)){
                printf("ERROR: Invalid Marks (Minor marks %.1lf should be in range [0,40] ).", student->minor[j]);
                printf(" msg: student with id %s has invalid minor marks in %s\n",id, arrSubjects[j]);
                isAnyError=true;
            }
        }


        for(int j=0; j<5; j++){
            fscanf(fpInp, "%lf", &student->major[j]);
            if(!isMarksValide(student->major[j],60.0)){
                printf("ERROR: Invalid Marks (Major marks %.1lf should be in range [0,60] ).", student->major[j]);
                printf(" msg: student with id %s has invalid major marks in %s\n",id, arrSubjects[j]);
                isAnyError=true;
            }
        }
        arrStudents[i]=student;
    }
    
    if(isAnyError) exit(1);
    // printf("Reached end of method: registerStudent()");
    return noOfStudents;
}