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
void addStudent(Student s[], int *count);
void calculateResult(Student *s);
char calculateGrade(float avg);
void displayStudent(Student s);
void searchStudent(Student s[], int count, int roll);
void rankStudents(Student s[], int count);

/* ---------- ADD STUDENT ---------- */
void addStudent(Student s[], int *count) {
    Student *st = &s[*count];

    printf("\nEnter Roll Number: ");
    scanf("%d", &st->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", st->name);

    printf("Enter Age: ");
    scanf("%d", &st->age);

    printf("Enter Phone: ");
    scanf("%s", st->contact.phone);

    printf("Enter Email: ");
    scanf("%s", st->contact.email);

    printf("Enter number of events (max %d): ", MAX_EVENTS);
    scanf("%d", &st->eventCount);

    for (int i = 0; i < st->eventCount; i++) {
        printf("\nEvent %d Name: ", i + 1);
        scanf(" %[^\n]", st->events[i].eventName);

        printf("Event Type (0-Cultural, 1-Sports, 2-Technical): ");
        scanf("%d", (int *)&st->events[i].type);

        printf("Max Marks: ");
        scanf("%d", &st->events[i].maxMarks);

        printf("Score Obtained: ");
        switch (st->events[i].type) {
            case CULTURAL:
                scanf("%d", &st->events[i].score.culturalScore);
                break;
            case SPORTS:
                scanf("%d", &st->events[i].score.sportsScore);
                break;
            case TECHNICAL:
                scanf("%d", &st->events[i].score.technicalScore);
                break;
        }
    }

    calculateResult(st);
    (*count)++;
}

/* ---------- CALCULATE TOTAL, AVERAGE, GRADE ---------- */
void calculateResult(Student *s) {
    s->totalMarks = 0;

    for (int i = 0; i < s->eventCount; i++) {
        switch (s->events[i].type) {
            case CULTURAL:
                s->totalMarks += s->events[i].score.culturalScore;
                break;
            case SPORTS:
                s->totalMarks += s->events[i].score.sportsScore;
                break;
            case TECHNICAL:
                s->totalMarks += s->events[i].score.technicalScore;
                break;
        }
    }

    s->average = (float)s->totalMarks / s->eventCount;
    s->grade = calculateGrade(s->average);
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
void searchStudent(Student s[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            displayStudent(s[i]);
            return;
        }
    }
    printf("\nStudent not found!");
}

/* ---------- RANK / LEADERBOARD ---------- */
void rankStudents(Student s[], int count) {
    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (s[j].totalMarks > s[i].totalMarks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\n\n===== LEADERBOARD =====");
    for (int i = 0; i < count; i++) {
        displayStudent(s[i]);
    }
}

/* ---------- MAIN FUNCTION ---------- */
int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice, roll;

    do {
        printf("\n\n===== UNIVERSITY STUDENT & EVENT MANAGEMENT =====");
        printf("\n1. Add Student");
        printf("\n2. Search Student by Roll Number");
        printf("\n3. Display Leaderboard");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
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
                printf("\nInvalid Choice!");
        }
    } while (choice != 4);

    return 0;
}
