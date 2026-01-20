#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "StudentUtil.h"


void printFinalReport(Student* arrStudents[], int noOfStudents){
    printf("\n-----------------------FINAL REPORT OF STUDENTS-----------------------\n");
    printf("\n%-10s %-15s %-50s %-50s %-48s %-10s %-5s %-5s %-5s", "Id", "Name",  "Minor Marks", "Major Marks", "Total Marks", "Percentage", "Grade", "CGPA", "Backlog");
    printf("\n%-10s %-15s %-8s %-8s %-8s %-8s %-10s","","", "IOT", "BCT", "OS", "CN", "DDPC"); 
    for(int i=0; i<2; i++)printf("%5s%-8s %-8s %-8s %-8s %-10s","","IOT", "BCT", "OS", "CN", "DDPC");
    printf("\n"); 
    
    printArrOfStudent(arrStudents, noOfStudents);
    
}
