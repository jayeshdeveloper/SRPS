#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE* openFile(char *);

typedef struct {
    char id[10];
    char name[20];
    int minor[5];
    int major[5];
} Student;

int main(){   
    FILE * fpInp  = openFile("input.txt");
    int noOfStudents; 
    
    fscanf(fpInp, "%d", &noOfStudents);
    printf("Number of students are:%d\n", noOfStudents);

    int arrStudents[noOfStudents];

    for(int i=0; i<noOfStudents; i++){
        Student* s = (Student*) malloc(sizeof(Student));
        fscanf(fpInp, "%s", s->name);
    }
   
   printf("%c", arrStudents[0]->name);
   
   
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


