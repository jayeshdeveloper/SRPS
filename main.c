#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
    input.txt format
    40 (shows no. of students)
    25ABC01 Jayesh 18 72 20 68 15 19 17 75 19 80 => detais of individual student, where  values are:
        id, 
        name, 
        minor marks of 5 subjects (out of 40)
        major marks of 5 subjects (out of 60)

*/


typedef struct {
    char* id;
    char* name;
    double minor[5];
    double major[5];

    // double totalMarks; 
    // double percentage; 
    // char* grade; 
} Student;


FILE* openFile(char *);
void printArrOfStudent(Student* arrStudents[], int noOfStudents);
double printStudent(Student* student);
void printFinalReport(Student* arrStudents[], int noOfStudents);
char* findGrade(double marks);
void allocateCategory(double marks, int* noOfStudentsPerCategoryArr);



int main(){   
    FILE * fpInp  = openFile("input.txt");
    int noOfStudents; 
    
    fscanf(fpInp, "%d", &noOfStudents);
    printf("Number of students are:%d\n", noOfStudents);

    Student* arrStudents[noOfStudents];

    for(int i=0; i<noOfStudents; i++){
        Student* student = (Student*) malloc(sizeof(Student));
        char *id = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", id);
        student->id=id;

        char *name = malloc(50 * sizeof(char));
        fscanf(fpInp, "%s", name);
        student->name=name;

        for(int i=0; i<5; i++){
            fscanf(fpInp, "%lf", &student->minor[i]);
        }


        for(int i=0; i<5; i++){
            fscanf(fpInp, "%lf", &student->major[i]);
        }
        arrStudents[i]=student;
    }
   
    // printArrOfStudent(arrStudents, noOfStudents);
    printFinalReport(arrStudents, noOfStudents);
   
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
    double averagePercentage = 0.0;
    double lowestPercentage = __DBL_MAX__;
    double highestPercentage = __DBL_MIN__;
    int noOfStudentsPerCategoryArr[8];
    char* gradesArr[]={"O","A+","A","B+","B","C","D","F"};
    //0 ≥ 90 → 0
    //1 85–90 → A+
    //2 75–85 → A
    //3 65–75 → B+
    //4 60–65 → B
    //5 55-60 → C
    //6 50–55 → D
    //7 < 50 → F
    for(int i=0; i<8; i++) noOfStudentsPerCategoryArr[i]=0;

    for(int i=0; i<noOfStudents; i++){
        Student* student = arrStudents[i];
        double percentage = printStudent(student);
        averagePercentage+=percentage;
        if(percentage<lowestPercentage) lowestPercentage=percentage;
        if(percentage>highestPercentage) highestPercentage=percentage;
        allocateCategory(percentage, noOfStudentsPerCategoryArr);
    }
    averagePercentage/=noOfStudents;

    printf("\nAverage percentage is: %.1lf\n", averagePercentage);
    printf("Lowest percentage is: %.1lf\n", lowestPercentage);
    printf("Highest percentage is: %.1lf\n", highestPercentage);

    printf("\nNo. of students in each grade category\n");
    for(int i=0;i<8; i++){
        printf(" %-5s %-5d\n",gradesArr[i], noOfStudentsPerCategoryArr[i]);
    }


}

double printStudent(Student* student){
      printf("%-10s %-15s ", student->id, student->name);
        for(int j=0; j<5; j++) printf("%-8.1lf ", student->minor[j]); printf("%6s","");
        for(int j=0; j<5; j++) printf("%-8.1lf ", student->major[j]); printf("%6s","");
        
        double totalMarks = 0.0;
        int noOfBacklog=0;
        for(int j=0; j<5; j++){
            double minorPlusMajor = student->minor[j]+student->major[j];
             printf("%-8.1lf ", minorPlusMajor);
             totalMarks+=minorPlusMajor;
             if(minorPlusMajor<50) noOfBacklog++;

        }printf("%4s","");

        double percentage = totalMarks/5;
        double cgpa =percentage/10;
        char* grade = findGrade(percentage);

        printf("%-11.1lf",percentage);
        printf("%-6s",grade);
        printf("%-6.1lf", cgpa);
        printf("%d", noOfBacklog);
        printf("\n");

        return percentage;
}

void printFinalReport(Student* arrStudents[], int noOfStudents){
    printf("\n-----------------------FINAL REPORT OF STUDENTS-----------------------\n");
    printf("\n%-10s %-15s %-50s %-50s %-48s %-10s %-5s %-5s %-5s", "Id", "Name",  "Minor Marks", "Major Marks", "Total Marks", "Percentage", "Grade", "CGPA", "Backlog");
    printf("\n%-10s %-15s %-8s %-8s %-8s %-8s %-10s","","", "IOT", "BCT", "OS", "CN", "DDPC"); 
    for(int i=0; i<2; i++)printf("%5s%-8s %-8s %-8s %-8s %-10s","","IOT", "BCT", "OS", "CN", "DDPC");
    printf("\n"); 
    
    printArrOfStudent(arrStudents, noOfStudents);
    
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
