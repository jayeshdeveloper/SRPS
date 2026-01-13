#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE* openFile(char *);

typedef struct {
    char* id;
    char* name;
    int minor[5];
    int major[5];
} Student;

int main(){   
    FILE * fpInp  = openFile("input.txt");
    int noOfStudents; 
    
    fscanf(fpInp, "%d", &noOfStudents);
    printf("Number of students are:%d\n", noOfStudents);

    Student* arrStudents[noOfStudents];

    for(int i=0; i<noOfStudents; i++){
        Student* s = (Student*) malloc(sizeof(Student));
        // char* id = "test"; 
        char *id = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", id);
        printf("id is: %s \n", id);

        char *name = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", name);
        printf("name is: %s \n", name);

        for(int i=0; i<5; i++){
            fscanf(fpInp, "%d", &s->minor[i]);
        }

        for(int i=0; i<5; i++){
            fscanf(fpInp, "%d", &s->major[i]);
        }
    }
   
//    Student* st = arrStudents[0]; 
//    char* name = &(st->id); 
//    printf("name is: %s", name);
   
   
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


