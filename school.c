#include <stdio.h>
#include <string.h>

int main() {
    FILE *file1 = fopen("/Users/kagya/Cproject/input.txt", "r");  
    FILE *file2 = fopen("/Users/kagya/Cproject/courses.txt", "r");
    char school[100];
    int cut;
    char schoolGender[10];
    char gender[10];
    char text[100];
    int number;

    printf("WELCOME TO OUR SCHOOL PLACEMENT SYSTEM\nHOW MAY WE ASSIST YOU\n");
    printf("1 -- View school placement for existing students in our database\n2 -- Check school placement for a new student\n");
    int userChoice;
    scanf("%d", &userChoice);

    if(userChoice == 1){
        if (file1 == NULL || file2 == NULL) {
            printf("Error opening file\n");
            return 1;
        }//if-statement to check if file can be opened
            // the while loop reads everything on the line except ':'
        while (fscanf(file1, "%[^:]: %d = %s\n", text, &number, gender) == 3) {
        rewind(file2);//while loop checks if we have read the name of student, grade point and gender on each line
            while(fscanf(file2,"%[^:]: %d = %s\n", school, &cut, schoolGender) == 3){
                if(number <= cut && strcmp(schoolGender, gender) == 0){
                    
                         FILE *filer = fopen("/Users/kagya/cproject/result.txt", "a");//opens the result file
                         fprintf(filer,"%s: %s\n", text, school);//writes the name of the student and their school assigned in the result file
                         fclose(filer);
                    
                }//if checks if a student meets the cotoff point and is also the assigned gender of the school.
            }
        }

        printf("Current database has been compiled at:\n /Users/kagya/cproject/result.txt ");//prints the directory of the result file
        fclose(file1);
        fclose(file2);
    }

    else if(userChoice == 2){// this code excutes when someone chooses option 2
        char name[100];
        char school[100];
        int grade;
        char schoolChoice[100];
        char inputGender[10];
        printf("Enter your First name:\n");
        scanf("%s", name);// stores the name of the person in a variable
        printf("Enter your grade:\n");
        scanf("%d", &grade);//stores the grade in a variable
        printf("Enter your gender:\n");
        scanf("%s", inputGender);//stores the gender in a variable

        FILE *file2 = fopen("/Users/kagya/cproject/courses.txt", "r");
        rewind(file2);

        while(fscanf(file2,"%[^:]: %d = %s\n", school, &cut, schoolGender) == 3){
            // checks to see if each line in the file opened contains school, cutoff and gender
            if(grade<= cut && strcmp(inputGender, schoolGender) == 0){
                printf("%s\n", school);
              //if statement selects and print the schools which is deseerved 
               
            }
            
    }
    if(grade > cut){
            printf("No School Available\nKindly check for self placement");
        }
        // the if statement checks if grade is above cutoff point

        fclose(file2);
    
    }
    
    else{
        printf("Invalid Input");
        return 1;
    }

}
