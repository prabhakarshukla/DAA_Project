
#include <stdio.h>
#include <time.h>
#include "structures.h"

int main() {

    TimetableEntry greedyTimetable[MAX_SUBJECTS];

    TimetableEntry backtrackingTimetable[MAX_SUBJECTS];

    clock_t start, end;

    double greedyTime, backtrackingTime;

    // Display project heading
    printf("========================================\n");
    printf("  COLLEGE EXAM TIMETABLE GENERATION\n");
    printf("========================================\n");

    // Load sample data
    loadSampleData();

    // Display subjects
    printf("\nAvailable Subjects:\n");

    for (int i = 0; i < subjectCount; i++) {
        printf("%d. %s\n", i + 1, subjects[i].name);
    }

    // GREEDY ALGORITHM
    initializeTimetable(greedyTimetable);

    printf("\nGenerating Timetable using Greedy...\n");

    start = clock();

    int greedySuccess = generateGreedy(greedyTimetable);

    end = clock();

    greedyTime = (double)(end - start) / CLOCKS_PER_SEC;

    displayTimetable(greedyTimetable, greedySuccess);

    // BACKTRACKING ALGORITHM
    initializeTimetable(backtrackingTimetable);

    printf("\nGenerating Timetable using Backtracking...\n");

    start = clock();

    int backtrackingSuccess =
        generateBacktracking(backtrackingTimetable);

    end = clock();

    backtrackingTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    displayTimetable(
        backtrackingTimetable,
        backtrackingSuccess
    );

    // PERFORMANCE COMPARISON
    printf("\n========================================\n");
    printf("       ALGORITHM PERFORMANCE\n");
    printf("========================================\n");

    printf("Greedy Execution Time       : %.8f seconds\n",
           greedyTime);

    printf("Backtracking Execution Time : %.8f seconds\n",
           backtrackingTime);

    printf("\nGreedy Status       : %s\n",
           greedySuccess ? "SUCCESSFUL" : "FAILED");

    printf("Backtracking Status : %s\n",
           backtrackingSuccess ? "SUCCESSFUL" : "FAILED");

    printf("========================================\n");

    return 0;
}
