#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Admin{
private:
    string adminId;
    int adminPw;
public:
    Admin(string ID,int PW){
        adminId = ID;
        adminPw = PW;
    }
    
    string getAdminId(){return adminId;}
    int getAdminPw(){return adminPw;}
   
    void setAdminId(string ID);
    void setAdminPw(int pw);
    
    bool adminIdControl();
    bool adminPwControl();
};

void Admin::setAdminId(string ID){
    if(adminIdControl() == false){
        cout << "Invalid ID" << endl;
    }
    else{
        adminId = ID;
    }
}

void Admin::setAdminPw(int PW){
    if(adminPwControl() == false){
        cout << "Invalid Password" << endl;
    }
    else{
        adminPw = PW;
    }
}

bool Admin::adminIdControl(){
    if(adminId == "Admin"){
        return true;
    }
    else{
        return false;
    }
}

bool Admin::adminPwControl(){
    if(adminPw == 1111){
        return true;
    }
    else{
        return false;
    }
}

class FitnessCostumer{
private:
    string costumerName,costumerSurname,costumerDepartment,costumerProgram,costumerCreatingTime;
    int costumerAge,costumerID,costumerExerciseTime,costumerPayment;
public:
    // constructor methods
    FitnessCostumer(string name = "",string surname = "",string department = "",int age = 0,int ID = 0,string program = "",int exercise = 0,string costumerCreatingTime = "",int payment = 0){
        setCostumerName(name);
        setCostumerSurname(surname);
        setCostumerDepartment(department);
        setCostumerAge(age);
        setCostumerID(ID);
        setCostumerProgram(program);
        setCostumerExerciseTime(exercise);
        setCostumerCreatingTime(costumerCreatingTime);
        setCostumerPayment(payment);
    }
    
    // GET - METHODS
    string getCostumerName(){return costumerName;}
    string getCostumerSurname(){return costumerSurname;}
    string getCostumerDepartment(){return costumerDepartment;}
    string getCostumerProgram(){return costumerProgram;}
    string getCostumerCreatingTime(){return costumerCreatingTime;}
    int getCostumerAge(){return costumerAge;}
    int getCostumerID(){return costumerID;}
    int getCostumerExerciseTime(){return costumerExerciseTime;}
    int getCostumerPayment(){return costumerPayment;}
    
    // SET - METHODS
    void setCostumerName(string);
    void setCostumerSurname(string);
    void setCostumerDepartment(string);
    void setCostumerProgram(string);
    void setCostumerCreatingTime(string);
    void setCostumerAge(int);
    void setCostumerID(int);
    void setCostumerExerciseTime(int);
    void setCostumerPayment(int);
    
    // CONTROL
    static bool costumerNameSurnameControl(string);
    static bool costumerDepartmentControl(string);
    static bool costumerAgeControl(int);
    
    // FONCTIONALITY
    static void addCostumer(vector <FitnessCostumer> &newClass);
    static void deleteCostumer(vector <FitnessCostumer> &newClass,int ID);
    static void showAllCostumer(vector <FitnessCostumer> &newClass);
    static void findByIdProgram(vector <FitnessCostumer> &newClass,int ID);
    static void findByIdInformation(vector <FitnessCostumer> &newClass,int ID);
    static void findByIdExerciseTime(vector <FitnessCostumer> &newClass,int ID);
    static void findByIdPayment(vector <FitnessCostumer> &newClass,int ID);
};

void FitnessCostumer::setCostumerPayment(int payment){
    string error = "Payment could not be determined due to incorrect keying";
    
    string depart1 = "Body";
    string depart2 = "Pilates";
    string depart3 = "Kickboks";
    
    if(costumerDepartment == depart1){
        payment = (int) 1500;
        costumerPayment = payment;
    }
    else if(costumerDepartment == depart2){
        payment = (int) 3000;
        costumerPayment = payment;
    }
    else if(costumerDepartment == depart3){
        payment = (int) 5000;
        costumerPayment = payment;
    }
    else{
        costumerPayment = payment;
    }
}

void FitnessCostumer::setCostumerCreatingTime(string creatingTime){
    srand((int) time(0));
    time_t now = time(0);
    char* dt = ctime(&now);
    creatingTime = dt;
    costumerCreatingTime = creatingTime;
}

void FitnessCostumer::setCostumerExerciseTime(int exerciseTime){
    srand((int) time(NULL));
    int exerciseRandTime = rand() % 10 + 1;
    if(exerciseRandTime == 0){
        exerciseRandTime += 1;
    }
    exerciseTime = exerciseRandTime;
    exerciseRandTime = costumerExerciseTime;
    costumerExerciseTime = exerciseTime;
}

void FitnessCostumer::setCostumerProgram(string program){
    string programBody = " 1 Day) Chest \n 2 Day) Back \n 3 Day) Leg \n 4 Day) Triceps \n 5 Day) Biceps \n 6 Day) Shoulder ";
    string programPilates = " 1 Day) Pilates principles \n 2 Day) Pilates basic moves \n 3 Day) Basic mat pilates \n 4 Day) Whole body stretch \n 5 Day) Base pilates with tape";
    string programKickBoks = " 1 Day) Front Kick \n 2 Day) Back Kick \n 3 Day) Head Kick \n 4 Day) Rotary Kick \n 5 Day) Break";
    
    string depart1 = "Body";
    string depart2 = "Pilates";
    string depart3 = "Kickboks";
    
    if(costumerDepartment == depart1){
        program = programBody;
        programBody = costumerProgram;
        costumerProgram = program;
    }
    else if(costumerDepartment == depart2){
        program = programPilates;
        programPilates = costumerProgram;
        costumerProgram = program;
    }
    else if(costumerDepartment == depart3){
        program = programKickBoks;
        programKickBoks = costumerProgram;
        costumerProgram = program;
    }
    costumerProgram = program;
    
}

void FitnessCostumer::setCostumerID(int ID){
    srand((int) time(NULL));
    ID = rand() % 1000;
    if(ID == 0){
        ID += 1;
    }
    costumerID = ID;
}

void FitnessCostumer::setCostumerName(string cosName){
    if(costumerNameSurnameControl(cosName) == false){
        costumerName = "";
    }
    else{
        costumerName = cosName;
    }
}

void FitnessCostumer::setCostumerSurname(string cosSurname){
    if(costumerNameSurnameControl(cosSurname) == false){
        costumerSurname = "";
    }
    else{
        costumerSurname = cosSurname;
    }
}

void FitnessCostumer::setCostumerDepartment(string cosDepartment){
    if(costumerDepartmentControl(cosDepartment) == false){
        costumerDepartment = "";
    }
    else{
        costumerDepartment = cosDepartment;
    }
}

void FitnessCostumer::setCostumerAge(int cosAge){
    if(costumerAgeControl(cosAge) == false){
        costumerAge = 0;
    }
    else {
        costumerAge = cosAge;
    }
    
}

bool FitnessCostumer::costumerAgeControl(int cosAge){
    if((cosAge < 0) || (cosAge > 90)){
        return false;
    }
    return true;
}

bool FitnessCostumer::costumerNameSurnameControl(string cosNameOrSurname){
    for(unsigned i=0;i<cosNameOrSurname.length();i++){
        if(!((cosNameOrSurname.at(i) >= 'A' && cosNameOrSurname.at(i) <= 'Z') || (cosNameOrSurname.at(i) >= 'a' && cosNameOrSurname.at(i) <= 'z'))){
            return false;
        }
    }
    return true;
};

bool FitnessCostumer::costumerDepartmentControl(string cosDepartment){
    for(unsigned i=0;i<cosDepartment.length();i++){
        if(!((cosDepartment.at(i) >= 'A' && cosDepartment.at(i) <= 'Z') || (cosDepartment.at(i) >= 'a' && cosDepartment.at(i) <= 'z'))){
            return false;
        }
    }
    return true;
};

void FitnessCostumer::addCostumer(vector <FitnessCostumer> &newClass){
    string tempName,tempSurname,tempDepartment,tempProgram;
    int newClassSize;int tempAge;
    
    cout << "How many people do you want to add ?: ";
    cin >> newClassSize;
    
    while(newClassSize <= 0){
        cout << "Number of invalid contacts enter the correct number of people: ";
        cin >> newClassSize;
        cout << endl;
    }
    
    for(int i=0;i<newClassSize;i++){
        cin.ignore();
        cout << "Enter the Costumer Name:" << i + 1 << ": ";
        getline(cin,tempName);
        cout << "Enter the Costumer Surname:" << i + 1 << ": ";
        getline(cin,tempSurname);
        cout << "Enter the Costumer Department:" << i + 1 << ": ";
        getline(cin,tempDepartment);
        cout << "Enter the Costumer Age:" << i + 1 << ": ";
        cin >> tempAge;
        FitnessCostumer newCostumer(tempName,tempSurname,tempDepartment,tempAge);
        newClass.push_back(newCostumer);
        cout << endl;
    }
};

void FitnessCostumer::showAllCostumer(vector <FitnessCostumer> &newClass){
    if(newClass.empty()){
        cout << "---------------------------------" << endl;
        cout << "There is no one registered." << endl;
        cout << "---------------------------------" << endl;
    }
    else{
        cout << "All Fitness Costumer Information" << endl << endl;
        for(unsigned int i=0;i<newClass.size();i++){
            cout << "Name: " << newClass[i].getCostumerName() << endl;
            cout << "Surname: " << newClass[i].getCostumerSurname() << endl;
            cout << "Department: " << newClass[i].getCostumerDepartment() << endl;
            cout << "Age:" << newClass[i].getCostumerAge() << endl;
            cout << "ID:" << newClass[i].getCostumerID() << endl;
            cout << "---------------------------Program---------------------------" << endl;
            cout << newClass[i].getCostumerProgram() << endl;
            cout << "---------------------------Program End-----------------------" << endl;
            cout << "Training Time: " << newClass[i].getCostumerExerciseTime() << " PM" << endl;
            cout << "Account Creating Time: " << newClass[i].getCostumerCreatingTime();
            cout << "Monthly Payment: " << newClass[i].getCostumerPayment() << endl;
            cout << endl;
        }
    }
};

void FitnessCostumer::findByIdInformation(vector <FitnessCostumer> &newClass,int ID){
    for(unsigned int i=0;i<newClass.size();i++){
        if(newClass[i].getCostumerID() == ID) {
            cout << "Name: " << newClass[i].getCostumerName() << endl;
            cout << "Surname: " << newClass[i].getCostumerSurname() << endl;
            cout << "Department: " << newClass[i].getCostumerDepartment() << endl;
            cout << "Age:" << newClass[i].getCostumerAge() << endl;
            cout << "ID:" << newClass[i].getCostumerID() << endl;
            cout << "---------------------------Program---------------------------" << endl;
            cout << newClass[i].getCostumerProgram() << endl;
            cout << "---------------------------Program End-----------------------" << endl;
            cout << "Training Time: " << newClass[i].getCostumerExerciseTime() << " PM" << endl;
            cout << "Account Creating Time: " << newClass[i].getCostumerCreatingTime();
            cout << "Monthly Payment: " << newClass[i].getCostumerPayment() << endl;
            cout << endl;
        }
    }
}

void FitnessCostumer::findByIdProgram(vector <FitnessCostumer> &newClass,int ID){
    for(unsigned int i=0;i<newClass.size();i++){
        if(newClass[i].getCostumerID() == ID) {
            cout << "---------------------------Program Start---------------------------" << endl;
            cout << newClass[i].getCostumerProgram() << endl;
            cout << "---------------------------Program End-----------------------" << endl;
        }
    }
}

void FitnessCostumer::findByIdExerciseTime(vector <FitnessCostumer> &newClass,int ID){
    for(unsigned int i=0;i<newClass.size();i++){
        if(newClass[i].getCostumerID() == ID) {
            cout << "---------------------------Exercise Time Start---------------------------" << endl;
            cout << "Your exercise starts at this time: " <<  newClass[i].getCostumerExerciseTime() << " PM" << endl;
            cout << "---------------------------Exercise Time End-----------------------" << endl;
        }
    }
}

void FitnessCostumer::findByIdPayment(vector <FitnessCostumer> &newClass,int ID){
    for(unsigned int i=0;i<newClass.size();i++){
        if(newClass[i].getCostumerID() == ID) {
            cout << "---------------------------Payment Start---------------------------" << endl;
            cout << "Your Department: " << newClass[i].getCostumerDepartment() << endl;
            cout << "Monthly Payment Your: " <<  newClass[i].getCostumerPayment() << " PM" << endl;
            cout << "---------------------------Payment End-----------------------" << endl;
        }
    }
}

void FitnessCostumer::deleteCostumer(vector <FitnessCostumer> &newClass,int ID){
    for(unsigned int i=0;i<newClass.size();i++){
        if(newClass[i].getCostumerID() == ID) {
            newClass.erase(newClass.begin() + i);
        }
    }
}
