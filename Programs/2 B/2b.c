// C Program to demonstrate Passing structure in function and returning structure from function
#include <stdio.h>

struct student {
    int roll_no;
    char name[20];
    float marks;
};

struct student input_student() {
    struct student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    return s;
}

void display_student(struct student s) {
    printf("\nRoll number: %d", s.roll_no);
    printf("\nName: %s", s.name);
    printf("\nMarks: %.2f", s.marks);
}

void main() {
    struct student s = input_student();
    display_student(s);
}
