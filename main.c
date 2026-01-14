#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char* id;
    char* name;
    double minor[5];
    double major[5];
} Student;


FILE* openFile(char *);
void printArrOfStudent(Student* arrStudents[], int noOfStudents);
void printStudent(Student* student);

int main(){   
    FILE * fpInp  = openFile("input.txt");
    int noOfStudents; 
    
    fscanf(fpInp, "%d", &noOfStudents);
    printf("Number of students are:%d\n", noOfStudents);

    Student* arrStudents[noOfStudents];

    for(int i=0; i<noOfStudents; i++){
        Student* student = (Student*) malloc(sizeof(Student));
        // char* id = "test"; 
        char *id = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", id);
        student->id=id;
        // printf("id is: %s \n", s->id);

        char *name = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", name);
        // printf("name is: %s \n", name);
        student->name=name;

        for(int i=0; i<5; i++){
            fscanf(fpInp, "%lf", &student->minor[i]);
        }

        // printf("%lf", s->minor[1]);

        for(int i=0; i<5; i++){
            fscanf(fpInp, "%lf", &student->major[i]);
        }
        arrStudents[i]=student;
    }
   
    printArrOfStudent(arrStudents, noOfStudents);
   
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

void printArrOfStudent(Student* arrStudents[], int noOfStudents){
    for(int i=0; i<noOfStudents; i++){
        Student* student = arrStudents[i];
        printStudent(student);
    }
}

void printStudent(Student* student){
      printf("%-10s %-15s ", student->id, student->name);
        for(int j=0; j<5; j++) printf("%-6.2lf ", student->minor[j]);
        for(int j=0; j<5; j++) printf("%-6.2lf ", student->major[j]);
        printf("\n");
}



