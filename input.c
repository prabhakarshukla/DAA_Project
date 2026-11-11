
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "structures.h"


Subject subjects[MAX_SUBJECTS];
Room rooms[MAX_ROOMS];
Faculty faculty[MAX_FACULTY];
ExamSlot slots[MAX_SLOTS];

int subjectCount;
int roomCount;
int facultyCount;
int slotCount;

static int readNumber(const char *message, int min, int max)
{
    char line[100];
    char *end;
    long value;

    while (1)
    {
        printf("%s", message);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("Input error. Try again.\n");
            clearerr(stdin);
            continue;
        }

        errno = 0;
        value = strtol(line, &end, 10);

        while (*end == ' ' || *end == '\t' ||
               *end == '\n' || *end == '\r')
        {
            end++;
        }

        if (end == line || *end != '\0' ||
            errno == ERANGE || value < min || value > max)
        {
            printf("Invalid input! Enter a number between %d and %d.\n",
                   min, max);
            continue;
        }

        return (int)value;
    }
}

static void readText(const char *message, char text[], int size)
{
    while (1)
    {
        printf("%s", message);

        if (fgets(text, size, stdin) == NULL)
        {
            printf("Input error. Try again.\n");
            clearerr(stdin);
            continue;
        }

        text[strcspn(text, "\n")] = '\0';

        // Handle text longer than the buffer
        if (strchr(text, '\n') == NULL && !feof(stdin))
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

        if (text[0] == '\0')
        {
            printf("Input cannot be empty.\n");
            continue;
        }

        return;
    }
}

int getUserInput(void)
{
    printf("\n========================================\n");
    printf("   COLLEGE EXAM TIMETABLE GENERATION\n");
    printf("========================================\n");

    // SUBJECT INPUT
    subjectCount = readNumber(
        "\nEnter number of subjects: ",
        1, MAX_SUBJECTS
    );

    printf("\n--- SUBJECT DETAILS ---\n");

    for (int i = 0; i < subjectCount; i++)
    {
        subjects[i].id = i + 1;

        printf("\nSubject %d\n", i + 1);

        readText(
            "Enter subject name: ",
            subjects[i].name,
            sizeof(subjects[i].name)
        );

        subjects[i].studentCount = readNumber(
            "Enter number of students: ",
            1, MAX_STUDENTS
        );
    }

    facultyCount = readNumber(
        "\nEnter number of faculty members: ",
        1, MAX_FACULTY
    );

    printf("\n--- FACULTY DETAILS ---\n");

    for (int i = 0; i < facultyCount; i++)
    {
        faculty[i].id = i + 1;

        char message[100];
        snprintf(message, sizeof(message),
                 "Enter faculty %d name: ", i + 1);

        readText(message, faculty[i].name,
                 sizeof(faculty[i].name));
    }

    printf("\n--- ASSIGN FACULTY TO SUBJECTS ---\n");

    for (int i = 0; i < subjectCount; i++)
    {
        printf("\nSubject: %s\n", subjects[i].name);

        for (int j = 0; j < facultyCount; j++)
        {
            printf("%d. %s\n", j + 1, faculty[j].name);
        }

        char message[100];
        snprintf(message, sizeof(message),
                 "Select faculty number for %s: ",
                 subjects[i].name);

        int choice = readNumber(message, 1, facultyCount);

        // Store faculty array index
        subjects[i].facultyId = choice - 1;
    }

    roomCount = readNumber(
        "\nEnter number of examination rooms: ",
        1, MAX_ROOMS
    );

    printf("\n--- ROOM DETAILS ---\n");

    for (int i = 0; i < roomCount; i++)
    {
        rooms[i].id = i + 1;

        printf("\nRoom %d\n", i + 1);

        readText(
            "Enter room name: ",
            rooms[i].name,
            sizeof(rooms[i].name)
        );

        rooms[i].capacity = readNumber(
            "Enter room seating capacity: ",
            1, MAX_STUDENTS
        );
    }

    slotCount = readNumber(
        "\nEnter number of available exam slots: ",
        1, MAX_SLOTS
    );

    printf("\n--- EXAM SLOT DETAILS ---\n");

    for (int i = 0; i < slotCount; i++)
    {
        slots[i].id = i + 1;

        printf("\nExam Slot %d\n", i + 1);

        readText(
            "Enter date (e.g. 20-Nov-2026): ",
            slots[i].date,
            sizeof(slots[i].date)
        );

        readText(
            "Enter time (e.g. 09:00 AM): ",
            slots[i].time,
            sizeof(slots[i].time)
        );
    }

    for (int i = 0; i < roomCount; i++)
    {
        for (int j = 0; j < slotCount; j++)
        {
            rooms[i].available[j] = 1;
        }
    }

    for (int i = 0; i < facultyCount; i++)
    {
        for (int j = 0; j < slotCount; j++)
        {
            faculty[i].available[j] = 1;
        }
    }

    printf("\n========================================\n");
    printf("       INPUT SUCCESSFULLY RECORDED\n");
    printf("========================================\n");

    return 1;
}
