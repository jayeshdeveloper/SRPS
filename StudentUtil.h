typedef struct {
    char* id;
    char* name;
    double minor[5];
    double major[5];

    // double totalMarks; 
    // double percentage; 
    // char* grade; 
} Student;

void printArrOfStudent(Student* arrStudents[], int noOfStudents);
double printStudent(Student* student);
char* findGrade(double marks);
void allocateCategory(double marks, int* noOfStudentsPerCategoryArr);
