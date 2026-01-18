#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_EVENTS 5

/* ---------- ENUM FOR EVENT TYPE ---------- */
typedef enum {
    CULTURAL,
    SPORTS,
    TECHNICAL
} EventType;

/* ---------- UNION FOR SCORE ---------- */
typedef union {
    int culturalScore;
    int sportsScore;
    int technicalScore;
} Score;

/* ---------- EVENT STRUCT ---------- */
typedef struct {
    char eventName[30];
    EventType type;
    int maxMarks;
    Score score;
} Event;

/* ---------- CONTACT STRUCT ---------- */
typedef struct {
    char phone[15];
    char email[30];
} Contact;

/* ---------- STUDENT STRUCT ---------- */
typedef struct {
    int roll;
    char name[30];
    int age;
    Contact contact;
    int eventCount;
    Event events[MAX_EVENTS];
    int totalMarks;
    float average;
    char grade;
} Student;

/* ---------- FUNCTION DECLARATIONS ---------- */
void addStudent(Student students[], int count);
void calculateResult(Student students[], int index);
char calculateGrade(float avg);
void displayStudent(Student s);
void searchStudent(Student students[], int count, int roll);
void rankStudents(Student students[], int count);

/* ---------- ADD STUDENT ---------- */
void addStudent(Student students[], int count) {

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Phone: ");
    scanf("%s", students[count].contact.phone);

    printf("Enter Email: ");
    scanf("%s", students[count].contact.email);

    printf("Enter number of events (max %d): ", MAX_EVENTS);
    scanf("%d", &students[count].eventCount);

    for (int i = 0; i < students[count].eventCount; i++) {
        printf("\nEvent %d Name: ", i + 1);
        scanf(" %[^\n]", students[count].events[i].eventName);

        printf("Event Type (0-Cultural, 1-Sports, 2-Technical): ");
        scanf("%d", (int *)&students[count].events[i].type);

        printf("Max Marks: ");
        scanf("%d", &students[count].events[i].maxMarks);

        printf("Score Obtained: ");
        if (students[count].events[i].type == CULTURAL)
            scanf("%d", &students[count].events[i].score.culturalScore);
        else if (students[count].events[i].type == SPORTS)
            scanf("%d", &students[count].events[i].score.sportsScore);
        else
            scanf("%d", &students[count].events[i].score.technicalScore);
    }

    calculateResult(students, count);
}

/* ---------- CALCULATE TOTAL, AVERAGE, GRADE ---------- */
void calculateResult(Student students[], int index) {

    students[index].totalMarks = 0;

    for (int i = 0; i < students[index].eventCount; i++) {
        if (students[index].events[i].type == CULTURAL)
            students[index].totalMarks += students[index].events[i].score.culturalScore;
        else if (students[index].events[i].type == SPORTS)
            students[index].totalMarks += students[index].events[i].score.sportsScore;
        else
            students[index].totalMarks += students[index].events[i].score.technicalScore;
    }

    students[index].average =
        (float)students[index].totalMarks / students[index].eventCount;

    students[index].grade =
        calculateGrade(students[index].average);
}

/* ---------- GRADE LOGIC ---------- */
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else return 'D';
}

/* ---------- DISPLAY STUDENT ---------- */
void displayStudent(Student s) {
    printf("\nRoll: %d | Name: %s | Total: %d | Avg: %.2f | Grade: %c",
           s.roll, s.name, s.totalMarks, s.average, s.grade);
}

/* ---------- SEARCH STUDENT ---------- */
void searchStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            displayStudent(students[i]);
            return;
        }
    }
    printf("\nStudent not found!");
}

/* ---------- RANK STUDENTS ---------- */
void rankStudents(Student students[], int count) {
    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].totalMarks > students[i].totalMarks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n\n===== LEADERBOARD =====");
    for (int i = 0; i < count; i++) {
        displayStudent(students[i]);
    }
}

/* ---------- MAIN FUNCTION ---------- */
int main() {

    Student students[MAX_STUDENTS];
    int count = 0, choice, roll;

    do {
        printf("\n\n===== UNIVERSITY STUDENT & EVENT MANAGEMENT =====");
        printf("\n1. Add Student");
        printf("\n2. Search Student");
        printf("\n3. Display Leaderboard");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, count);
                count++;
                break;

            case 2:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                searchStudent(students, count, roll);
                break;

            case 3:
                rankStudents(students, count);
                break;

            case 4:
                printf("\nExiting Program...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 4);

    return 0;
}
