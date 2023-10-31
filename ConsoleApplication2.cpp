#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class Logger {
public:
    Logger() {
        logFile.open("log.txt", ios::app);
        log("Программа запущена.");
    }
    ~Logger() {
        log("Программа завершена."");
        logFile.close();
    }
    void log(const string& message) {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        string userName = "userName";
        logFile << "Пользователь" << userName << " " << message << " в" << timeStr;
    }

private:
    ofstream logFile;
};

class Student {
public:
    Student(Logger& logger) : log(logger) {
        log.log("создан объект Student.");
    }

    ~Student() {
        log.log("Объект Student уничтожен.");
    }
private:
    Logger& log;
};
class Group {
public:
    Group(Logger& logger) : log(logger) {
        log.log("Создан объкт Group."");
    }
    ~Group() {
        log.log("Объект Group уничтожен.");
    }
private:
    Logger& log;
};

int main() {
    Logger programLogger;
    Student student1(programLogger);
    Student student2(programLogger);
    Group group(programLogger);
    int x = 10;
    int y = 0;
    int result = x / y;
    return 0;
}
