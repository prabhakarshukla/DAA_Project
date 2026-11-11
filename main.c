
#include <stdio.h>
#include <time.h>
#include "structures.h"

int main(void)
{
    TimetableEntry greedyTimetable[MAX_SUBJECTS];
    TimetableEntry backtrackingTimetable[MAX_SUBJECTS];

    clock_t start, end;

    double greedyTime;
    double backtrackingTime;

    printf("\n========================================\n");
    printf("  COLLEGE EXAM TIMETABLE GENERATION\n");
    printf("========================================\n");

    if (!getUserInput())
    {
        printf("Unable to collect input.\n");
        return 1;
    }

    initializeTimetable(greedyTimetable);

    printf("\nGenerating Timetable using Greedy...\n");

    start = clock();

    int greedyStatus = generateGreedy(greedyTimetable);

    end = clock();

    greedyTime = (double)(end - start) / CLOCKS_PER_SEC;

    displayTimetable(greedyTimetable, greedyStatus);

    initializeTimetable(backtrackingTimetable);

    printf("\nGenerating Timetable using Backtracking...\n");

    start = clock();

    int backtrackingStatus =
        generateBacktracking(backtrackingTimetable);

    end = clock();

    backtrackingTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    displayTimetable(backtrackingTimetable, backtrackingStatus);

    printf("\n========================================\n");
    printf("          ALGORITHM PERFORMANCE\n");
    printf("========================================\n");

    printf("Greedy Execution Time       : %.8f seconds\n",
           greedyTime);

    printf("Backtracking Execution Time : %.8f seconds\n",
           backtrackingTime);

    printf("\nGreedy Status       : %s\n",
           greedyStatus ? "SUCCESSFUL" : "FAILED");

    printf("Backtracking Status : %s\n",
           backtrackingStatus ? "SUCCESSFUL" : "FAILED");

    printf("========================================\n");

    return 0;
}
