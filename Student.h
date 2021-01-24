//
// Created by 10991 on 2021/1/24.
//

#ifndef ALGORITHMLEETCODE_STUDENT_H
#define ALGORITHMLEETCODE_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }
    friend ostream& operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //ALGORITHMLEETCODE_STUDENT_H
