#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int randomMidBranch() {
    std::srand(std::time(nullptr));
    return std::rand() % 2 + 2;
}

int randomBigBranch() {
    std::srand(std::time(nullptr));
    return std::rand() % 3 + 3;
}

class Branch;

class Branch {
    std::string nameElf = "None";   

    Branch* parent = nullptr;

    public:
        void setParent(Branch* inParent) {
            parent = inParent;
        }
        Branch* getParent() {
            return parent; 
        }
        Branch* getTopBranch() {
            if (parent == nullptr) return nullptr; 
            if (parent->parent == nullptr) return this;
            return parent->getTopBranch();
        }

        void setName() {
            std::cin >> nameElf;
        }
        std::string getName() {
            return nameElf;
        }
};

int main() {
    std::vector<Branch*> tree;
    for (int i = 0; i < 5; i++) {
        Branch* temp_tree = new Branch;
        tree.push_back(temp_tree);
    }

    std::vector<std::vector<Branch*>> bigBranch;
    bigBranch.resize(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < randomBigBranch(); j++) {
            Branch* temp_bigBranch = new Branch;
            bigBranch[i].push_back(temp_bigBranch);
            std::cout << "Input elf name for " << i + 1 << " tree, " << j + 1 << " big branch: ";
            bigBranch[i][j]->setName();
            bigBranch[i][j]->setParent(tree[i]);
        }
    }

    std::vector<std::vector<std::vector<Branch*>>> midBranch;
    midBranch.resize(5);
    for (int i = 0; i < 5; i++) {
        midBranch[i].resize(bigBranch[i].size());
        for (int j = 0; j < midBranch[i].size(); j++) {
            for (int k = 0; k < randomMidBranch(); k++) {
                Branch* temp_midBranch = new Branch;
                midBranch[i][j].push_back(temp_midBranch);
                std::cout << "Input elf name for " << i + 1 << " tree, " << j + 1 << " big branch, " << k + 1 << " mid branch: ";
                midBranch[i][j][k]->setName();
                midBranch[i][j][k]->setParent(bigBranch[i][j]);
            }
        }
    }

    std::string nameFind;
    std::cout << "Input name of elf: ";
    std::cin >> nameFind;

    bool bigBranchFind = false;
    Branch* branchFind = nullptr;
    for (int i = 0; i < 5; i++) {
        if (branchFind != nullptr) break;
        for (int j = 0; j < bigBranch[i].size(); j++) {
            if (bigBranch[i][j]->getName() == nameFind) {
                branchFind = bigBranch[i][j];
                bigBranchFind = true;
                break;
            }
        }
    }

    if (branchFind == nullptr) {
        for (int i = 0; i < 5; i++) {
            if (branchFind != nullptr) break;
            for (int j = 0; j < midBranch[i].size(); j++) {
                if (branchFind != nullptr) break;
                for (int k = 0; k < midBranch[i][j].size(); k++) {
                    if (midBranch[i][j][k]->getName() == nameFind) {
                        branchFind = midBranch[i][j][k];
                        break;
                    }
                }
            }
        }
    }

    if (branchFind == nullptr) {
        std::cout << "Cannot find";
    }
    else {
        branchFind = branchFind->getTopBranch();
        std::cout << "Neighbours: " << std::endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < midBranch[i].size(); j++) {
                for (int k = 0; k < midBranch[i][j].size(); k++) {
                    if (midBranch[i][j][k]->getParent() == branchFind 
                            && midBranch[i][j][k]->getName() != "None"
                            && midBranch[i][j][k]->getName() != nameFind) {
                        std::cout << midBranch[i][j][k]->getName() << std::endl;
                    }
                }
            }
        }
        if (!bigBranchFind) {
            std::cout << branchFind->getName() << std::endl;
        }
    }
    
    for (auto va: tree) {
        delete va;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < bigBranch[i].size(); j++) {
            delete bigBranch[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < midBranch[i].size(); j++) {
            for (int k = 0; k < midBranch[i][j].size(); k++) {
                delete midBranch[i][j][k];
            }
        }
    }
}

/*
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях. 
Нужно расселить эльфов по веткам деревьев, 
а затем подсчитать общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, каждое из которых генерируется с помощью 
случайных чисел, заданных в указанных далее диапазонах. 
На каждом дереве есть 3–5 основных больших ветвей. На каждой 
большой ветке расположены ещё 2-3 средние ветки. Дома эльфов 
построены на больших и на средних ветках. 
Более мелкие ветви не рассматриваются в этой задаче.
В начале программы пользователь размещает в каждом доме по одному 
эльфу. Делается это с помощью последовательного перебора всех 
имеющихся домов и запроса имени заселяемого эльфа через 
стандартный ввод. Если было введено None в 
качестве имени, то дом пропускается и не заселяется никем.
После этого требуется найти определённого эльфа по имени. Имя 
искомого эльфа вводится через стандартный ввод. Для найденного 
эльфа нужно вывести общее количество эльфов, живущих вместе с ним 
на одной большой ветви. Это и будет искомое количество соседей.
*/