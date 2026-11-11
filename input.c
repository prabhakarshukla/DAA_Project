
#include <stdio.h>
#include <string.h>
#include "structures.h"

// Global data definitions
Subject subjects[MAX_SUBJECTS];
Room rooms[MAX_ROOMS];
Faculty faculty[MAX_FACULTY];
ExamSlot slots[MAX_SLOTS];

int subjectCount = 0;
int roomCount = 0;
int facultyCount = 0;
int slotCount = 0;

void loadSampleData(void) {

    subjectCount = 4;
    roomCount = 2;
    facultyCount = 2;
    slotCount = 4;

    subjects[0].id = 1;
    strcpy(subjects[0].name, "Mathematics");
    subjects[0].facultyId = 0;

    subjects[1].id = 2;
    strcpy(subjects[1].name, "Data Structures");
    subjects[1].facultyId = 0;

    subjects[2].id = 3;
    strcpy(subjects[2].name, "Database Management");
    subjects[2].facultyId = 1;

    subjects[3].id = 4;
    strcpy(subjects[3].name, "Operating Systems");
    subjects[3].facultyId = 1;

    rooms[0].id = 1;
    strcpy(rooms[0].name, "R101");

    rooms[1].id = 2;
    strcpy(rooms[1].name, "R102");

    faculty[0].id = 101;
    strcpy(faculty[0].name, "Faculty A");

    faculty[1].id = 102;
    strcpy(faculty[1].name, "Faculty B");

    slots[0].id = 1;
    strcpy(slots[0].date, "20-Nov-2026");
    strcpy(slots[0].time, "09:00 AM");

    slots[1].id = 2;
    strcpy(slots[1].date, "20-Nov-2026");
    strcpy(slots[1].time, "02:00 PM");

    slots[2].id = 3;
    strcpy(slots[2].date, "21-Nov-2026");
    strcpy(slots[2].time, "09:00 AM");

    slots[3].id = 4;
    strcpy(slots[3].date, "21-Nov-2026");
    strcpy(slots[3].time, "02:00 PM");

    for (int i = 0; i < roomCount; i++) {
        for (int j = 0; j < slotCount; j++) {
            rooms[i].available[j] = 1;
        }
    }

    for (int i = 0; i < facultyCount; i++) {
        for (int j = 0; j < slotCount; j++) {
            faculty[i].available[j] = 1;
        }
    }
}
