
#include "structures.h"

int generateGreedy(TimetableEntry timetable[]) {

    // Process subjects one by one
    for (int i = 0; i < subjectCount; i++) {

        int assigned = 0;

        // Try available examination slots
        for (int j = 0; j < slotCount; j++) {

            // Try available rooms
            for (int k = 0; k < roomCount; k++) {

                if (isValidAssignment(i, j, k, timetable)) {

                    timetable[i].subjectIndex = i;
                    timetable[i].slotIndex = j;
                    timetable[i].roomIndex = k;
                    timetable[i].assigned = 1;

                    assigned = 1;
                    break;
                }
            }

            if (assigned) {
                break;
            }
        }

        // No valid slot found
        if (!assigned) {
            return 0;
        }
    }

    return 1;
}
