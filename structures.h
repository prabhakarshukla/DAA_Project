
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_SUBJECTS 20
#define MAX_ROOMS 10
#define MAX_FACULTY 20
#define MAX_SLOTS 30

typedef struct {
    int id;
    char name[50];
    int facultyId;
} Subject;

typedef struct {
    int id;
    char name[20];
    int available[MAX_SLOTS];
} Room;

typedef struct {
    int id;
    char name[50];
    int available[MAX_SLOTS];
} Faculty;

typedef struct {
    int id;
    char date[20];
    char time[20];
} ExamSlot;

typedef struct {
    int subjectId;
    int slotId;
    int roomId;
} TimetableEntry;

#endif
