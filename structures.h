
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_SUBJECTS 20
#define MAX_ROOMS 10
#define MAX_FACULTY 20
#define MAX_SLOTS 30

// Subject Information
typedef struct {
    int id;
    char name[50];
    int facultyId;
} Subject;

// Room Information
typedef struct {
    int id;
    char name[20];
    int available[MAX_SLOTS];
} Room;

// Faculty Information
typedef struct {
    int id;
    char name[50];
    int available[MAX_SLOTS];
} Faculty;

// Examination Slot Information
typedef struct {
    int id;
    char date[20];
    char time[20];
} ExamSlot;

// Timetable Assignment
typedef struct {
    int subjectIndex;
    int slotIndex;
    int roomIndex;
    int assigned;
} TimetableEntry;

// Shared data
extern Subject subjects[MAX_SUBJECTS];
extern Room rooms[MAX_ROOMS];
extern Faculty faculty[MAX_FACULTY];
extern ExamSlot slots[MAX_SLOTS];

extern int subjectCount;
extern int roomCount;
extern int facultyCount;
extern int slotCount;

// Function declarations
void loadSampleData(void);

void initializeTimetable(TimetableEntry timetable[]);

int isValidAssignment(
    int subjectIndex,
    int slotIndex,
    int roomIndex,
    TimetableEntry timetable[]
);

int generateGreedy(TimetableEntry timetable[]);

int generateBacktracking(TimetableEntry timetable[]);

void displayTimetable(
    TimetableEntry timetable[],
    int success
);

#endif

