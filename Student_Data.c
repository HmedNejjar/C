#include <stdio.h>
#include <stdlib.h>
// Define a structure to hold student information
typedef struct 
{
    char name[20];         // Student's name
    int ID;                // Student's ID
    float MathMark;        // Student's Math score
    float EngMark;         // Student's English score
    float ChinMark;        // Student's Chinese score
    float Average;         // Student's average score
} Student;

// Function prototypes
float average(Student students[], int n);        // Calculate class average
void Pass(Student students[], int n, float avg); // Check if students pass or fail
void Ranking(Student students[], int n);         // Rank students by average score
void CheckStudentInfo(Student students[], int n);// Display student information by ID

int main(void)
{
    int num;
    // Prompt the user to enter the number of students
    printf("Type in Student number: ");
    scanf("%d", &num);

    do {
        printf("Error, number must be greater than 0.\nStudent numbers: "); // Error message if student number is invalid
        scanf("%d", &num);
    } while (num <= 0);


    Student students[num]; // Declare an array to hold students' data

    // Collect information for each student
    for (int i = 0; i < num; i++)
    {
        printf("Student %d name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].ID);

        printf("Math score: ");
        scanf("%f", &students[i].MathMark);

        printf("English score: ");
        scanf("%f", &students[i].EngMark);

        printf("Chinese score: ");
        scanf("%f", &students[i].ChinMark);

        printf("\n");

        // Calculate and store the student's average score
        students[i].Average = (students[i].ChinMark + students[i].EngMark + students[i].MathMark) / 3.0;
        printf("Average score: %.3f\n", students[i].Average);
    }

    // Calculate the class average
    float avgClass = average(students, num);
    printf("Class average is: %.3f\n", avgClass);

    // Check which students passed or failed
    Pass(students, num, avgClass);

    // Rank students by their average score
    Ranking(students, num);

    // Allow the user to check information for a specific student
    CheckStudentInfo(students, num);
}

// Function to calculate the class average
float average(Student students[], int n)
{
    float sum = 0;

    // Sum the average scores of all students
    for (int i = 0; i < n; i++)
    {
        sum += students[i].Average;
    }

    // Return the average of the averages
    return sum / n;
}

// Function to check if students pass or fail
void Pass(Student students[], int n, float avg)
{
    for (int i = 0; i < n; i++)
    {
        if (students[i].Average < avg)
        {
            // Student failed
            printf("Student: %s\nID number: %d\nFails.\nAverage score: %.3f\nClass average score: %.3f\n\n", 
                   students[i].name, students[i].ID, students[i].Average, avg);
        }
        else
        {
            // Student passed
            printf("Student: %s\nID number: %d\nPasses.\nAverage score: %.3f\nClass average score: %.3f\n\n", 
                   students[i].name, students[i].ID, students[i].Average, avg);
        }
    }
}

// Function to rank students by their average score in descending order
void Ranking(Student students[], int n)
{
    // Sort students using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].Average < students[j + 1].Average) 
            {
                // Swap students[j] and students[j + 1]
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display the sorted list of students
    printf("Students from highest score to lowest:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s %d %.3f\n", students[i].name, students[i].ID, students[i].Average);
    }
}

// Function to display student information based on their ID
void CheckStudentInfo(Student students[], int n)
{
    int ID;

    // Prompt the user to enter a student ID
    printf("Type in student ID to see student information.\n");
    scanf("%d", &ID);

    // Search for the student with the given ID
    for (int i = 0; i < n; i++)
    {
        if (students[i].ID == ID) // Corrected comparison operator
        {
            // Display the student's information
            printf("Student Name: %s\nStudent ID: %d\nMath Score: %.3f\nEnglish Score: %.3f\nChinese Score: %.3f\nAverage Score: %.3f\n", 
                   students[i].name, students[i].ID, students[i].MathMark, students[i].EngMark, students[i].ChinMark, students[i].Average);
        }
    }

    // If no student is found with the given ID
    printf("Student ID not found.\n");
}
