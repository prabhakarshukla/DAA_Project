
#include "structures.h"

void initializeTimetable(TimetableEntry timetable[])
{
    for (int i = 0; i < subjectCount; i++)
    {
        timetable[i].subjectIndex = -1;
        timetable[i].slotIndex = -1;
        timetable[i].roomIndex = -1;
        timetable[i].assigned = 0;
    }
}

int isValidAssignment(
    int subjectIndex,
    int slotIndex,
    int roomIndex,
    TimetableEntry timetable[]
)
{
    int facultyIndex = subjects[subjectIndex].facultyId;

    if (!rooms[roomIndex].available[slotIndex])
    {
        return 0;
    }

    if (!faculty[facultyIndex].available[slotIndex])
    {
        return 0;
    }

    if (rooms[roomIndex].capacity <
        subjects[subjectIndex].studentCount)
    {
        return 0;
    }

    for (int i = 0; i < subjectCount; i++)
    {
        if (timetable[i].assigned == 1)
        {
            if (timetable[i].slotIndex == slotIndex &&
                timetable[i].roomIndex == roomIndex)
            {
                return 0;
            }

            int existingFaculty =
                subjects[timetable[i].subjectIndex].facultyId;

            if (timetable[i].slotIndex == slotIndex &&
                existingFaculty == facultyIndex)
            {
                return 0;
            }
        }
    }

    return 1;
}
