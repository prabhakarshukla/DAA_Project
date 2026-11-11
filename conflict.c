
#include "structures.h"

void initializeTimetable(TimetableEntry timetable[]) {

    for (int i = 0; i < subjectCount; i++) {

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
) {

    int facultyId = subjects[subjectIndex].facultyId;

    // Check room availability
    if (rooms[roomIndex].available[slotIndex] == 0) {
        return 0;
    }

    // Check faculty availability
    if (faculty[facultyId].available[slotIndex] == 0) {
        return 0;
    }

    // Check conflicts with existing assignments
    for (int i = 0; i < subjectCount; i++) {

        if (timetable[i].assigned == 1) {

            // Same room cannot host two exams simultaneously
            if (timetable[i].slotIndex == slotIndex &&
                timetable[i].roomIndex == roomIndex) {

                return 0;
            }

            // Same faculty cannot handle two exams simultaneously
            int existingFaculty =
                subjects[timetable[i].subjectIndex].facultyId;

            if (timetable[i].slotIndex == slotIndex &&
                existingFaculty == facultyId) {

                return 0;
            }
        }
    }

    return 1;
}
