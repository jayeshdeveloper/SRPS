# Student Registration System (SRPS)

## 1. Introduction
This project implements a modular Student Registration and Result Processing System in C.

## 2. Modularization
The project is divided into the following modules:
- StudentUtil – validation and grading functions  
- RegisterStudent – reading input and creating students  
- Printers – printing reports  
- Main – program control  

Each module has its own .h and .c file and can be compiled separately.

## 3. Module Specification


### Module 1: StudentUtil Module

Module Name: StudentUtil  
Purpose: Provides validation, grading, and utility functions for student data.

Functions:

1. bool isMarksValide(double scored, double maxMarks)  
   - Input: scored, maxMarks  
   - Precondition: Marks must be numeric  
   - Logic: Check if scored is between 0 and maxMarks  
   - Output: Returns true if valid, else false  

2. bool isNameValid(char* name)  
   - Input: name  
   - Precondition: Name must be a string  
   - Logic: Check each character is alphabet only  
   - Output: Returns true if valid, else false  

3. bool isIdValid(char* id)  
   - Input: id  
   - Precondition: ID must be non-empty string  
   - Logic: Check all characters are alphanumeric  
   - Output: Returns true if valid, else false  

4. char* findGrade(double marks)  
   - Input: marks  
   - Precondition: Marks in range 0–100  
   - Logic: Assign grade based on percentage  
   - Output: Returns grade string (O, A+, …, F)  

---

### Module 2: RegisterStudent Module

Module Name: RegisterStudent  
Purpose: Reads input file, creates student records, and stores them in memory.

Function:

1. int registerStudents(int noOfStudents, Student** arrStudents)  
   - Input: noOfStudents (initially 0), arrStudents  
   - Precondition: input.txt must exist, arrStudents must have enough capacity  

Logic:  
- Open input file  
- Read number of students  
- For each student:  
  - Read id, name, marks  
  - Validate data  
  - Allocate memory and store  

Output: Returns total number of students and fills arrStudents  

---

### Module 3: Printers Module

Module Name: Printers  
Purpose: Prints formatted student report and statistics.

Functions:

1. void printFinalReport(Student* arrStudents[], int noOfStudents)  
   - Input: arrStudents, noOfStudents  
   - Precondition: Student array must be filled  
   - Logic:  
     - Print table headers  
     - Call printArrOfStudent  
   - Output: Displays final report  

2. void printArrOfStudent(Student* arrStudents[], int noOfStudents)  
   - Input: arrStudents, noOfStudents  
   - Precondition: Student data must be valid  
   - Logic:  
     - Loop through students  
     - Print each student  
     - Calculate average, highest, lowest  
   - Output: Prints rows and summary  

3. double printStudent(Student* student)  
   - Input: student  
   - Precondition: student != NULL  
   - Logic:  
     - Print marks  
     - Compute total, percentage, grade  
   - Output: Returns percentage  

---

### Module 4: Main Module

Module Name: Main  
Purpose: Controls program flow and coordinates all modules.

Function:

1. int main()  
   - Input: None  
   - Precondition: All modules compiled correctly  
   - Logic:  
     - Initialize variables  
     - Call registerStudents  
     - Call printFinalReport  
   - Output: Displays complete student report  


## 4. How to Compile and Run

```bash
gcc main.c StudentUtil.c RegisterStudent.c Printers.c
./a.out 
 ``` 

Output when user enters invalid data
<img width="1470" height="956" alt="image" src="https://github.com/user-attachments/assets/51e965ab-7402-4741-b0c5-b3515c92c35b" />

Output when user enters valid data
<img width="1470" height="956" alt="image" src="https://github.com/user-attachments/assets/ff6f4280-fd33-4da9-bb59-86240930c903" />
