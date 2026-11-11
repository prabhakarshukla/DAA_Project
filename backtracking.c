
#include "structures.h"

static int solveBacktracking(
    int subjectIndex,
    TimetableEntry timetable[]
)
{
    if (subjectIndex == subjectCount)
    {
        return 1;
    }

    for (int j = 0; j < slotCount; j++)
    {
        
        for (int k = 0; k < roomCount; k++)
        {
            if (isValidAssignment(
                    subjectIndex, j, k, timetable))
            {
                
                timetable[subjectIndex].subjectIndex =
                    subjectIndex;

                timetable[subjectIndex].slotIndex = j;
                timetable[subjectIndex].roomIndex = k;
                timetable[subjectIndex].assigned = 1;

                
                if (solveBacktracking(
                        subjectIndex + 1, timetable))
                {
                    return 1;
                }

                timetable[subjectIndex].subjectIndex = -1;
                timetable[subjectIndex].slotIndex = -1;
                timetable[subjectIndex].roomIndex = -1;
                timetable[subjectIndex].assigned = 0;
            }
        }
    }

    return 0;
}

int generateBacktracking(TimetableEntry timetable[])
{
    return solveBacktracking(0, timetable);
}
