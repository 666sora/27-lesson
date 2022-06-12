#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

enum TaskType {
    NONE = -1,
    A = 0,
    B = 1,
    C = 2
};

TaskType returnTaskType(int type) {
    switch (type) {
        case 0: return A;
        case 1: return B;
        case 2: return C;
        default: return NONE;
    }
}

class Ceo {
    std::string nameCeo = "";
    
    int taskMain = 0;

    public:
        void setName() {
            std::cout << "Input name of CEO: ";
            std::cin >> nameCeo;
        }
        std::string getName() {
            return nameCeo;
        }

        void setTask() {
            std::cout << "Input main task: ";
            std::cin >> taskMain;
        }
        int getTask() {
            return taskMain;
        } 
};

class Employee {
    std::string nameEmployee = "";


    TaskType currentTaskType = NONE;

    public:
        void setName() {
            std::cin >> nameEmployee;
        }
        std::string getName() {
            return nameEmployee;
        }

        void setTaskType(TaskType inTaskType) {
            currentTaskType = inTaskType;
        }
        bool isBusy() {
            return (currentTaskType == NONE ? false : true);
        }
};

class TeamLeader {
    std::string nameTL = "";

    int sequenceNumber = 0;

    int hash = 0;

    public:
        void setName() {
            std::cin >> nameTL;
        }
        std::string getName() {
            return nameTL;
        }

        void setSequenceNumber(int inIndex) {
            sequenceNumber = inIndex;
        }

        void setHash(int inTaskMain) {
            hash = inTaskMain + sequenceNumber;
        }
        int getHash() {
            return hash;
        }
};

class Team {
    TeamLeader teamLeader;
    std::vector<Employee> employee;

    int countOfEmployees = 0;
    
    public:
        void setCountOfEmployees(int inIndex) {
            std::cout << "Input count of employees in " << inIndex + 1 << " team: ";
            std::cin >> countOfEmployees;
        }
        int getCountOfEmployees() {
            return countOfEmployees;
        }

        int returnNotBusyIndex() {
            for (int i = 0; i < countOfEmployees; i++) {
                if (!(employee[i].isBusy())) return i;
            }
            return -1;
        }

        void customizeTeam(int inIndex) {
             std::cout << "Input name of team leader in " << inIndex + 1 << " team: ";
            teamLeader.setName();
            teamLeader.setSequenceNumber(inIndex);

            employee.resize(countOfEmployees);
            for (int i = 0; i < getCountOfEmployees(); i++) {
                std::cout << "Input name of employee in " << inIndex + 1 << " team: ";
                employee[i].setName();
            }
        }

        void startWorking(int inMainTask) {
            if (countOfEmployees == 0) return;
            teamLeader.setHash(inMainTask);
            std::srand(teamLeader.getHash());
            int taskCount = std::rand() % (countOfEmployees + 1) + 1;
            while (taskCount != 0) {
                if (returnNotBusyIndex() == -1) break;
                std::cout << employee[returnNotBusyIndex()].getName() << " employee getting task" << std::endl;
                employee[returnNotBusyIndex()].setTaskType(returnTaskType(std::rand() % 3));
                taskCount--;
            }
        }
};

int returnNotBusyIndex(std::vector<Team*> team) {
    for (int i = 0; i < team.size(); i++) {
        if (team[i]->returnNotBusyIndex() != -1) {
            return i;
        }
    }
    return -1;
}

int main() {
    Ceo ceo;
    ceo.setName();
    ceo.setTask();
    std::cout << ceo.getName() << " determines a main task" << std::endl;

    int countOfTeams;
    std::cout << "Input count of teams: ";
    std::cin >> countOfTeams;
    std::vector<Team*> team;
    for (int i = 0; i < countOfTeams; i++) {
        Team* tempTeam = new Team;
        team.push_back(tempTeam);
    }

    for (int i = 0; i < countOfTeams; i++) {
        team[i]->setCountOfEmployees(i);
        team[i]->customizeTeam(i);
    }

    int index = 0;
    while (index != -1) {
        index = returnNotBusyIndex(team);
        if (index == -1) continue;
        team[index]->startWorking(ceo.getTask());
    }

    for (auto t: team) {
        delete t;
    }
}

/*
Реализуйте симуляцию работы компании. В компании существует 
вертикальное управление с иерархией. Есть основные рабочие, 
подчинённые, разбитые на команды. У каждой команды есть 
менеджер среднего звена. Всей компанией руководит глава 
компании. У всех сотрудников, включая руководителя, есть имена.
Глава компании выполняет стратегическое управление. 
Он определяет основной вектор движения — задачи верхнего 
уровня. Менеджеры среднего звена разбивают эти задачи 
на подзадачи и раздают их своим подчинённым. Подчинённые выполняют работу.
Реализация данной логики должна проходить упрощённым 
образом. Указания главы компании поступают из стандартного 
ввода и являются не более чем целочисленными идентификаторами.
Данные идентификаторы служат зерном для генератора 
случайных чисел. Каждый из менеджеров, принимая себе 
эту целочисленную команду, добавляет к ней свой порядковый 
номер и вызывает с результирующей суммой функцию std::srand().
На основе этой суммы вычисляется общее количество задач, 
которое требуется выполнить данной командой, — от 1 до 
количества работников в группе. Всего есть три типа задач 
для работников: A, B и C. Они тоже выбираются случайно 
и распределяются между незанятыми рабочими.
При старте программы пользователь указывает в стандартном 
вводе количество команд и количество работников в каждой из команд.
Далее пользователь вводит целые числа, которые соответствуют 
указаниям руководителя компании. Когда какой-то работник или 
менеджер получил указания или задачу, об этом сообщается в 
стандартный вывод, включая имя работающего сотрудника. 
Программа завершается, когда все работники заняты какими-то задачами.
*/