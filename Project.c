#include <stdio.h>

// 1. Take Student Details
void inputDetails(int roll[], int marks[][3], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Details Of Student %d\n", i + 1);

        printf("Enter Roll Number : ");
        scanf("%d", &roll[i]);

        printf("Enter Marks in English : ");
        scanf("%d", &marks[i][0]);

        printf("Enter Marks in Maths : ");
        scanf("%d", &marks[i][1]);

        printf("Enter Marks in Computer : ");
        scanf("%d", &marks[i][2]);
    }
}

// Marks[] -> Array
// Subject -> Integer

int calculateTotal(int marks[], int subject)
{
    int total = 0;
    for (int i = 0; i < subject; i++)
    {
        // total = 0-> 0+45 -> 45 -> 45+35-> 80 -> 80+25 -> 105
        total += marks[i];
    }

    return total;
}

// Percentage
float calculatePercentage(int total)
{
    return (total / 300.0) * 100;
}

// Display
void displayStudents(int roll[], int marks[][3], int n)
{
    printf("\n---------------------------STUDENT RECORDS----------------------------\n\n");

    printf("%-10s %-10s %-10s %-10s %-10s %-11s\n", "Roll", "English", "Maths", "Computer", "Total", "Percentage");

    printf("---------------------------------------------------------------------");

    for (int i = 0; i < n; i++)
    {
        int total = calculateTotal(marks[i], 3);
        printf("\n%-10d %-10d %-10d %-10d %-10d %-11.2f \n",
               roll[i], marks[i][0], marks[i][1], marks[i][2], total, calculatePercentage(total));
    }
}

// Check Pass / Fail
// True, False
// False - 0
// True - 1

int checkPassFail(int marks[], int subject)
{
    for (int i = 0; i < subject; i++)
    {
        if (marks[i] < 33)
        {
            return 0;
        }
    }

    return 1;
}

void displayResult(int roll[], int marks[][3], int n)
{
    printf("\n--------------------- STUDENT RESULT -------------------");

    for (int i = 0; i < n; i++)
    {
        // individual totalof each student
        int total = calculateTotal(marks[i], 3);

        printf("\n Roll Number %d\n", roll[i]);
        printf("Total Marks %d / 300 \n", total);
        printf("Percentage : %.2f%%\n", calculatePercentage(total));

        if (checkPassFail(marks[i], 3))
        {
            printf("RESULT : Pass\n");
        }
        else
        {
            printf("RESULT : FAIL\n");
        }
    }
}

void searchStudent(int roll[], int marks[][3], int n)
{
    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number To Search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < n; i++)
    {
        if (roll[i] == searchRoll)
        {
            int total = calculateTotal(marks[i], 3);

            printf("\n Roll Number %d\n", roll[i]);
            printf("English : %d\n", marks[i][0]);
            printf("Maths : %d\n", marks[i][1]);
            printf("Computer : %d\n", marks[i][2]);
            printf("Total Marks %d / 300 \n", total);
            printf("Percentage : %.2f%%\n", calculatePercentage(total));

            if (checkPassFail(marks[i], 3))
            {
                printf("RESULT : Pass\n");
            }
            else
            {
                printf("RESULT : FAIL\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSTUDENT NOT FOUND");
    }
}

void findTopper(int roll[], int marks[][3], int n)
{
    int highTotal = calculateTotal(marks[0], 3);
    int topperIndex = 0;

    for (int i = 1; i < n; i++)
    {
        int total = calculateTotal(marks[i], 3);

        if (total > highTotal)
        {
            highTotal = total;
            topperIndex = i;
        }
    }

    printf("\n============CLASS TOPPER===============\n");
    printf("\n Roll Number %d\n", roll[topperIndex]);
    printf("English : %d\n", marks[topperIndex][0]);
    printf("Maths : %d\n", marks[topperIndex][1]);
    printf("Computer : %d\n", marks[topperIndex][2]);
    printf("Total Marks %d / 300 \n", highTotal);
    printf("Percentage : %.2f%%\n", calculatePercentage(highTotal));
}

int main()
{

    // Array to store number of students & Roll Number, marks

    int students[100]; // Roll Number
    int marks[100][3]; // marks (in table)

    // Actual number of students
    int n, choice;

    printf("---------Student Management System----------\n");

    printf("Enter Number Of Students \n");
    scanf("%d", &n);

    // MENU DRIVEN

    if (n <= 0 || n > 100)
    {
        printf("Inavalid Number Of Students");
        return 0;
    }

    inputDetails(students, marks, n);

    while (1)
    {
        printf("\nSELECT YOUR OPTION");
        printf("\n1. Display All Students");
        printf("\n2. Check Pass/Fail");
        printf("\n3. Search Student");
        printf("\n4. Class Topper");
        printf("\n5. Exit");

        printf("\nEnter Your Choice ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            displayStudents(students, marks, n);
        }
        else if (choice == 2)
        {
            displayResult(students, marks, n);
        }
        else if (choice == 3)
        {
            searchStudent(students, marks, n);
        }
        else if (choice == 4)
        {
            findTopper(students, marks, n);
        }
        else if (choice == 5)
        {
            printf("\n\n Thankyou For Using.");
            break;
        }
        else
        {
            printf("Invalid Choice. Try Again");
        }
    }

    return 0;
}
