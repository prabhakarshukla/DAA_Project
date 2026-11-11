
#include <stdio.h>
#include "structures.h"

void displayTimetable(
    TimetableEntry timetable[],
    int success
) {

    if (!success) {
        printf("\nScheduling Status: FAILED\n");
        printf("No valid timetable could be generated.\n");
        return;
    }

    printf("\n");
    printf("--------------- EXAM TIMETABLE ---------------\n");

    printf("%-22s %-14s %-12s %-10s\n",
           "Subject", "Date", "Time", "Room");

    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < subjectCount; i++) {

        int slot = timetable[i].slotIndex;
        int room = timetable[i].roomIndex;

        printf("%-22s %-14s %-12s %-10s\n",
               subjects[i].name,
               slots[slot].date,
               slots[slot].time,
               rooms[room].name);
    }

    printf("---------------------------------------------------------------\n");

    printf("Scheduling Status: SUCCESSFUL\n");
}
