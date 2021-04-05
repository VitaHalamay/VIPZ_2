#include <stdio.h>
#include "Realisation.h"

int main() {
    struct SList *pFirstItem = NULL;
    ReadStudentsFromFile(pFirstItem);
    GetStudentsCount(pFirstItem);

    struct SStudent sStudent1 = {"Middle", "Inserted", 1, 5, 4};
    sStudent1.sBirthday.tm_mday = 1;
    sStudent1.sBirthday.tm_mon = 5;
    sStudent1.sBirthday.tm_year = 2003 - 1900;

    struct SStudent sStudent2 = {"Bottom", "Inserted", 1, 3, 4};
    sStudent2.sBirthday.tm_mday = 2;
    sStudent2.sBirthday.tm_mon = 5;
    sStudent2.sBirthday.tm_year = 1993 - 1900;

    struct SStudent sStudent3 = {"Top", "Inserted", 1, 3, 4};
    sStudent3.sBirthday.tm_mday = 3;
    sStudent3.sBirthday.tm_mon = 5;
    sStudent3.sBirthday.tm_year = 2013 - 1900;

    FILE *pFile;
    pFile = fopen("MyTextFile.txt", "w");

    printf("Choose the way of output: in file(1) or console(0)");
    int nChoice;
    scanf("%d", &nChoice);

    switch (nChoice) {
        case 1:
            PrintTableInFile("All students before ordering", 1, pFile);
            OrderByBirthdayAscending(pFirstItem);
            PrintTableInFile("All students after ordering", 1, pFile);
            PrintTableInFile("Students with marks lower then average group mark", 0, pFile);
            InsertStudent(sStudent1);
            InsertStudent(sStudent2);
            InsertStudent(sStudent3);
            PrintTableInFile("Students after inserting", 1, pFile);
            DeleteStudentWithout5();
            PrintTableInFile("Students after deleting", 1, pFile);
            fclose(pFile);
            break;
        case 0:
            PrintTable("All students before ordering", 1);
            OrderByBirthdayAscending(pFirstItem);
            PrintTable("All students after ordering", 1);
            PrintTable("Students with marks lower then average group mark", 0);
            InsertStudent(sStudent1);
            InsertStudent(sStudent2);
            InsertStudent(sStudent3);
            PrintTable("Students after inserting", 1);
            DeleteStudentWithout5();
            PrintTable("Students after deleting", 1);
            break;
        default:
            printf("Wrong input!");
    }
    return 0;

}
