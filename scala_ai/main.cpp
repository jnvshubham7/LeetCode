#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

double calculateFinalGrade(double assignments, double exams, double attendance) {
    return assignments * 0.5 + exams * 0.2 + attendance * 0.3;
}

void generateTranscript(const json& student) {
    std::string student_id = student["id"];
    std::string student_name = student["name"];
    double cumulativeGPA = 0.0;
    int totalCredits = 0;

    std::cout << "Transcript for " << student_name << " (ID: " << student_id << ")\n";

    for (const auto& semester : student["semesters"]) {
        std::string term = semester["term"];
        std::cout << "Semester: " << term << "\n";
        double semesterGPA = 0.0;
        int semesterCredits = 0;

        for (const auto& subject : semester["subjects"]) {
            std::string subject_name = subject["name"];
            int credits = subject["credits"];
            auto performance = subject["performance"];
            double assignments = performance["assignments"];
            double exams = performance["exams"];
            double attendance = performance["attendance"];

            double finalGrade = calculateFinalGrade(assignments, exams, attendance);

            double gradePoint = (finalGrade / 100.0) * 4.0;

            semesterGPA += gradePoint * credits;
            semesterCredits += credits;

            std::cout << "Subject: " << subject_name << ", Grade: " << finalGrade << "\n";
        }

        double semesterGPA_average = semesterGPA / semesterCredits;
        cumulativeGPA += semesterGPA;
        totalCredits += semesterCredits;

        std::cout << "Semester GPA: " << semesterGPA_average;
        if (semesterGPA_average >= 3.7) {
            std::cout << " (With Honors)";
        }
        std::cout << "\n";
    }

    double cumulativeGPA_average = cumulativeGPA / totalCredits;
    std::cout << "Cumulative GPA: " << cumulativeGPA_average;
    if (cumulativeGPA_average >= 3.7) {
        std::cout << " (With Honors)";
    }
    std::cout << "\n\n";
}

int main() {
    std::string jsonData = R"(
    {
      "students": [
        {
          "id": "S001",
          "name": "Alice",
          "semesters": [
            {
              "term": "Fall 2023",
              "subjects": [
                { "name": "Math", "credits": 4, "performance": { "assignments": 80, "exams": 70, "attendance": 85 } },
                { "name": "Physics", "credits": 3, "performance": { "assignments": 90, "exams": 60, "attendance": 70 } }
              ]
            }
          ]
        },
        {
          "id": "S002",
          "name": "Bob",
          "semesters": [
            {
              "term": "Fall 2023",
              "subjects": [
                { "name": "Math", "credits": 4, "performance": { "assignments": 85, "exams": 75, "attendance": 90 } },
                { "name": "English", "credits": 2, "performance": { "assignments": 95, "exams": 82, "attendance": 60 } }
              ]
            }
          ]
        }
      ]
    }
    )";

    json data = json::parse(jsonData);

    for (const auto& student : data["students"]) {
        generateTranscript(student);
    }

    return 0;
}