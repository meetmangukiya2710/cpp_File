#include <iostream>
using namespace std;
 
class Computer {
public:
    void setCPU(const string& cpu) {
        cpu_ = cpu;
    }
 
    void setRAM(const string& ram) {
        ram_ = ram;
    }
 
    void setStorage(const string& storage) {
        storage_ = storage;
    }
 
    void displayInfo() const {
        cout << "Computer Configuration:"
                  << "\nCPU: " << cpu_
                  << "\nRAM: " << ram_
                  << "\nStorage: " << storage_ << "\n\n";
    }
 
private:
    string cpu_;
    string ram_;
    string storage_;
};
 
class Builder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual Computer getResult() = 0;
};
 
class GamingComputerBuilder : public Builder {
private:
    Computer computer_;
 
public:
    void buildCPU() {
        computer_.setCPU("Gaming CPU");
    }
 
    void buildRAM() {
        computer_.setRAM("16GB DDR4");
    }
 
    void buildStorage() {
        computer_.setStorage("1TB SSD");
    }
 
    Computer getResult() {
        return computer_;
    }
};
 
class ComputerDirector {
public:
    void construct(Builder& builder) {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
    }
};
 
int main() {
    GamingComputerBuilder gamingBuilder;
    ComputerDirector director;
 
    director.construct(gamingBuilder);
    Computer gamingComputer = gamingBuilder.getResult();
 
    gamingComputer.displayInfo();
 
    return 0;
}
