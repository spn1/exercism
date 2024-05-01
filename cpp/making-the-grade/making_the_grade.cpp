#include <array>
#include <string>
#include <vector>
#include <iostream>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> int_scores {};
    for (double score : student_scores) {
        int_scores.push_back(static_cast<int>(score));
    }
    return int_scores;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failed_students = 0;
    for (const int score : student_scores) {
        if (score <= 40) { 
            failed_students++;
        }
    }
    return failed_students;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> best_scores {};

    for (int score : student_scores) {
        if (score >= threshold) {
            best_scores.push_back(score);
        }
    }

    return best_scores;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> thresholds {};
    const int gap = (highest_score - 40) / 4;

    for (int i = 0; i < 4; ++i) {
        thresholds[i] = 41 + (gap * i);
    }

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> results {};

    for (unsigned int i = 0; i < student_scores.size(); ++i) {
        results.push_back(
            std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i])
        );
    }

    return results;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::string student_with_perfect_score {};

    for (unsigned int i = 0; i < student_scores.size(); i++) {
        std::cout << student_names[i] << " " << student_scores[i];
        if (student_scores[i] == 100) {
            student_with_perfect_score = student_names[i];
            break;
        }
    }

    return student_with_perfect_score;
}
