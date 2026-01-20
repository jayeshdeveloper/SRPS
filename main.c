#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "StudentUtil.h"
#include "RegisterStudent.h"
#include "finalReportPrinter.c"

/* JAYESH JAISWAL MTECH CS
    input.txt format
    40 (shows no. of students)
    25ABC01 Jayesh 18 72 20 68 15 19 17 75 19 80 => detais of individual student, where  values are:
        id, 
        name, 
        minor marks of 5 subjects (out of 40)
        major marks of 5 subjects (out of 60)
*/

// typedef struct {
//     char* id;
//     char* name;
//     double minor[5];
//     double major[5];

//     // double totalMarks; 
//     // double percentage; 
//     // char* grade; 
// } Student;

FILE* openFile(char *);

bool isMarksValide(double scored, double maxMarks);
bool isNameValid(char* name);
bool isIdValid(char* id);
bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr);


int main(){  
    int noOfStudents; 
    Student* arrStudents[noOfStudents]; 
    registerStudents(noOfStudents, arrStudents);
    printFinalReport(arrStudents, noOfStudents);
   
}

// FILE* openFile(char * fileName){
//     printf("function invoked: openFile() for file name %s\n", fileName);
//     FILE *fpInp = fopen(fileName, "r");
//      if(fpInp != NULL){ 
//         printf("file opened successfully\n");
//     }else{
//         printf("Unable to open input.txt\n");
//     }

//     return fpInp;
// }


// bool isMarksValide(double scored, double maxMarks){
//     if(scored<0 || scored >maxMarks) return false;
//     return true;
// }

// bool isNameValid(char* name){
//     int length = strlen(name);
//     for(int i=0; i<length; i++){
//         char ch = name[i];
//         if((ch<'A' || ch> 'Z') && (ch<'a' || ch> 'z') ){
//                 printf("ERROR: Invalid Name. Failed at %c. ", ch);
//                 return false;   
//         }
//     }
//     return true;
// }

// bool isIdValid(char* id){
//     int length = strlen(id);
//         for(int i=0; i<length; i++){
//         char ch = id[i];
//         if((ch<'A' || ch> 'Z') && (ch<'a' || ch> 'z') && (ch<'0' || ch> '9')){
//                 printf("ERROR: Invalid Id. Failed at %c. Id %s is invalid\n", ch, id);
//                 return false;   
//         }
//     }
//     printf("");
//     return true; 
// }

// bool isDuplicateId(char* idArr[], char* id, int sizeOfIdArr){
//     for(int i=0; i<sizeOfIdArr; i++) {
//         if(strcasecmp(idArr[i], id)==0){
//             printf("ERROR: Duplicate Id Found. msg: more than one students have same id %s\n", id);
//             return true;
//         }
//     }
//     return false;
// }







