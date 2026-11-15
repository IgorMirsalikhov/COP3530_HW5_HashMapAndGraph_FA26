#include "HashMap.hpp"
#include <iostream>
#include <string>
#include <iomanip>


std::ostream& operator<<(std::ostream& out, const Student& st) {
    out << "{" << st.name << ", " << st.major << ", " << st.gpa << "}";
    return out;
}

bool addStudent(HashMap<Student>& map, int student_id, const Student& st) {
    return true;
}   

bool updateStudent(HashMap<Student>& map, int student_id, const Student& st) {
    return true;
}

bool removeStudent(HashMap<Student>& map, int student_id) {
    return true;
}

const Student* findStudent(const HashMap<Student>& map, int student_id) {
    return nullptr;
}

//=========================================

void printSection(const std::string& title) {
    static bool first_section = true;

    if (!first_section) {
        std::cout << '\n';
    }
    first_section = false;

    std::cout << "========================================\n";
    std::cout << title << '\n';
    std::cout << "========================================\n";
}

void printResult(const std::string& operation, bool success) {
    std::cout << operation << ": " << (success ? "success" : "failed") << '\n';
}

void printStudent(const HashMap<Student>& database, int student_id) {
    std::cout << "Find " << student_id << ": ";
    const Student* student = findStudent(database, student_id);
    if (student == nullptr) {
        return;
    }
    std::cout << *student;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    HashMap<Student> database(7);

    printSection("1. Empty database");
    database.printStatistics();

    printSection("2. Add students");

    printResult("Add 101", addStudent(database, 101, Student("Alice Johnson", "Computer Science", 3.80)));
    printResult("Add 108", addStudent(database, 108, Student("Bob Smith", "Mathematics", 3.40)));
    printResult("Add 115", addStudent(database, 115, Student("Emma Davis", "Biology", 3.90)));
    printResult("Add 202", addStudent(database, 202, Student("John Miller", "Economics", 3.10)));

    std::cout << "\nHash table after insertions:\n";
    database.print();

    std::cout << '\n';
    database.printStatistics();

    printSection("3. Duplicate ID and search");

    printResult("Add duplicate 101", addStudent(database, 101, Student("Another Alice", "Physics", 4.00)));

    printStudent(database, 115);
    std::cout << "\n";
    printStudent(database, 999);

    printSection("4. Update students");

    printResult("Update 108", updateStudent(database, 108, Student("Bob Smith", "Data Science", 3.65)));
    printResult("Update 999", updateStudent(database, 999, Student("Missing Student", "Unknown", 0.00)));

    printStudent(database, 108);

    std::cout << '\n';
    database.printStatistics();

    printSection("5. Remove from a probe sequence");

    printResult("Remove 108", removeStudent(database, 108));

    std::cout << "\nHash table after removing 108:\n";
    database.print();

    std::cout << '\n';
    database.printStatistics();

    std::cout << "\nSearch after the deleted position:\n";
    printStudent(database, 115);

    printSection("6. Reuse a deleted position");

    printResult("Add 122", addStudent(database, 122, Student("Daniel Brown", "Engineering", 3.55)));

    std::cout << "\nHash table after adding 122:\n";
    database.print();

    std::cout << '\n';
    database.printStatistics();

    printSection("7. Missing removal");
    printResult("Remove 999", removeStudent(database, 999));

    printSection("8. Fill the table");

    printResult("Add 7", addStudent(database, 7, Student("Grace Lee", "Physics", 3.70)));
    printResult("Add 14", addStudent(database, 14, Student("Henry Wilson", "Chemistry", 3.20)));
    printResult("Add 21", addStudent(database, 21, Student("Isabella Moore", "History", 3.90)));
    printResult("Add 28 to full table", addStudent(database, 28, Student("James Taylor", "English", 3.30)));

    std::cout << "\nFinal hash table:\n";
    database.print();

    std::cout << '\n';
    database.printStatistics();

    return 0;
}
