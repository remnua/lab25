//Trees
//#include <iostream>
//
//class Tree {
//public:
//    virtual void draw() const = 0;
//};
//
//class Tree1 : public Tree {
//public:
//    void draw() const override {
//        std::cout << "/\\" << std::endl;
//        std::cout << "//\\\\" << std::endl;
//    }
//};
//
//class Tree2 : public Tree {
//public:
//    void draw() const override {
//        std::cout << "/\\" << std::endl;
//        std::cout << "/**\\" << std::endl;
//    }
//};
//
//class Tree3 : public Tree {
//public:
//    void draw() const override {
//        std::cout << "/\\" << std::endl;
//        std::cout << "/++\\" << std::endl;
//    }
//};
//
//int main() {
//    Tree* treeTable[3];
//    Tree1 tree1;
//    Tree2 tree2;
//    Tree3 tree3;
//
//    treeTable[0] = &tree1;
//    treeTable[1] = &tree2;
//    treeTable[2] = &tree3;
//
//    for (int i = 0; i < 3; i++) {
//        std::cout << "Drawing " << i + 1 << ":" << std::endl;
//        treeTable[i]->draw();
//        std::cout << std::endl;
//    }
//
//    return 0;
//}


#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(const std::string& address) : ipAddress(address) {}

    IPAddress(const IPAddress& other) : ipAddress(other.ipAddress) {}

    virtual void print() const {
        std::cout << ipAddress << std::endl;
    }

protected:
    std::string ipAddress;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const std::string& address, bool isCorrect)
        : IPAddress(address), isCorrect(isCorrect) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        std::cout << (isCorrect ? " - Correct" : " - Not Correct") << std::endl;
    }

private:
    bool isCorrect;
};

int main() {
    std::string ip1, ip2, ip3;

    std::cout << "Enter the first IP address: ";
    std::getline(std::cin, ip1);

    std::cout << "Enter the second IP address: ";
    std::getline(std::cin, ip2);

    std::cout << "Enter the third IP address: ";
    std::getline(std::cin, ip3);

    IPAddress ip(ip1);
    IPAddressChecked ipChecked1(ip2, false);
    IPAddressChecked ipChecked2(ip3, true);

    ip.print();
    ipChecked1.print();
    ipChecked2.print();

    return 0;
}
