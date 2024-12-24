#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void deleteStudent(int id, struct Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }

    if (found) {
        printf("Sinh vien co ID %d da duoc xoa.\n", id);
    } else {
        printf("Khong tim thay sinh vien co ID %d trong danh sach.\n", id);
    }
}
void printStudents(struct Student students[], int currentLength) {
    printf("Danh sach sinh vien hien tai:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van An", 20, "0123456789"},
        {2, "Bui Van Anh", 21, "0987654321"},
        {3, "Nguyen Trong Vuong", 19, "0123987654"},
        {4, "Pham Thi Diem", 22, "0192837465"},
        {5, "Nguyen Thanh Cong", 20, "0918273645"}
    };
    int currentLength = 5;
    printStudents(students, currentLength);

    printf("\nXoa sinh vien co ID = 3:\n");
    deleteStudent(3, students, &currentLength);

    printStudents(students, currentLength);

    return 0;
}

