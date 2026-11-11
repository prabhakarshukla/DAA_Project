
#include "structures.h"

int solveBacktracking(int subjectIndex,
                      TimetableEntry timetable[]) {

    // All subjects successfully assigned
    if (subjectIndex == subjectCount) {
        return 1;
    }

    // Try every examination slot
    for (int j = 0; j < slotCount; j++) {

        // Try every available room
        for (int k = 0; k < roomCount; k++) {

            if (isValidAssignment(
                subjectIndex, j, k, timetable)) {

                // Make assignment
                timetable[subjectIndex].subjectIndex =
                    subjectIndex;

                timetable[subjectIndex].slotIndex = j;

                timetable[subjectIndex].roomIndex = k;

                timetable[subjectIndex].assigned = 1;

                // Recursively schedule next subject
                if (solveBacktracking(
                    subjectIndex + 1, timetable)) {

                    return 1;
                }

                // Undo assignment (Backtracking)
                timetable[subjectIndex].subjectIndex = -1;
                timetable[subjectIndex].slotIndex = -1;
                timetable[subjectIndex].roomIndex = -1;
                timetable[subjectIndex].assigned = 0;
            }
        }
    }

    // No valid assignment found
    return 0;
}

int generateBacktracking(TimetableEntry timetable[]) {

    return solveBacktracking(0, timetable);
}
