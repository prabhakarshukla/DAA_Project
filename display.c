
#include <stdio.h>
#include "structures.h"

void displayTimetable(
    TimetableEntry timetable[],
    int success
)
{
    printf("\n");
    printf("===============================================================\n");
    printf("                    EXAM TIMETABLE\n");
    printf("===============================================================\n");

    if (!success)
    {
        printf("Scheduling failed! No complete valid timetable found.\n");
        return;
    }

    printf("%-22s %-14s %-12s %-10s %-10s\n",
           "Subject", "Date", "Time", "Room", "Students");

    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < subjectCount; i++)
    {
        int s = timetable[i].subjectIndex;
        int t = timetable[i].slotIndex;
        int r = timetable[i].roomIndex;
        int f = subjects[s].facultyId;

        printf("%-22s %-14s %-12s %-10s %-10d\n",
               subjects[s].name,
               slots[t].date,
               slots[t].time,
               rooms[r].name,
               subjects[s].studentCount);

        printf("  Faculty: %-18s Room Capacity: %d\n",
               faculty[f].name,
               rooms[r].capacity);
    }

    printf("---------------------------------------------------------------\n");
    printf("Scheduling Status: SUCCESSFUL\n");
}
