#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class Logger {
public:
    Logger() {
        logFile.open("log.txt", ios::app);
        log("Ïðîãðàììà çàïóùåíà.");
    }
    ~Logger() {
        log("Ïðîãðàììà çàâåðøåíà.");
        logFile.close();
    }
    void log(const string& message) {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        string userName = "userName";
        logFile << "Ïîëüçîâàòåëü " << userName << " " << message << " â " << timeStr;
    }

private:
    ofstream logFile;
};

class Student {
public:
    Student(Logger& logger) : log(logger) {
        log.log("Ñîçäàí îáúåêò Student.");
    }

    ~Student() {
        log.log("Îáúåêò Student óíè÷òîæåí.");
    }
private:
    Logger& log;
};
class Group {
public:
    Group(Logger& logger) : log(logger) {
        log.log("Ñîçäàí îáúåêò Group.");
    }
    ~Group() {
        log.log("Îáúåêò Group óíè÷òîæåí.");
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
