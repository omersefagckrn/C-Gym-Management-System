#include "main.h"

int main(){
    int choice;

    std::vector <FitnessCostumer> myCostumerClass;
    
    FitnessCostumer fitnessCostumerObject;
    
    menu3:
    cout << "------------------------Fitness Center Management System------------------------" << endl;
    cout << "Admin or Costumer(Admin: 1,Costumer: 2,Exit: 3): ";
    cin >> choice;
    
    while(choice > 3 || choice < 0){
        cout << "invalid choice " << "(" << choice << ")!" << " pls try enter: ";
        cin >> choice;
    }
    
    switch(choice){
        case 1:{
        menu:
            int tempAdminPW;
            string tempAdminID;
            
            cout << "Enter Admin ID: ";
            cin >> tempAdminID;
            cin.ignore();
            cout << "Enter Admin PW: ";
            cin >> tempAdminPW;
            
            cout << endl;

            Admin admin(tempAdminID,tempAdminPW);

            if(admin.adminIdControl() && admin.adminPwControl()){
                int choice;
                menu2:
                cout << "Welcome to the admin panel." << endl;
                cout << "1: Add Costumer." << endl;
                cout << "2: Show All Costumer" << endl;
                cout << "3: Back to main menu" << endl;
                cout << "4: Delete Costumer" << endl;
                cout << "5: Exit" << endl;
                cout << "Which process do you prefer ?: ";
                cin >> choice;
                cout << endl;
                switch (choice) {
                    case 1:
                        fitnessCostumerObject.addCostumer(myCostumerClass);
                        goto menu2;
                        break;
                    case 2:
                        fitnessCostumerObject.showAllCostumer(myCostumerClass);
                        goto menu2;
                        break;
                    case 3:
                        goto menu3;
                        break;
                    case 4:
                        int tempID;
                        cout << "Which id do you want to delete?: ";
                        cin >> tempID;
                        cout << endl;
                        if(tempID == 0){
                            cout << "invalid ID " << endl << endl;
                            goto menu4;
                        }
                        fitnessCostumerObject.deleteCostumer(myCostumerClass,tempID);
                        goto menu2;
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout << "Invalid Choice" << endl;
                        goto menu2;
                        break;
                }
                break;
            }
            else{
                cout << "Invalid ID - PW please try logging in again." << endl;
                goto menu;
                break;
            }
        }
        case 2:
            menu4:
            int choice2,tempID;
            cout << endl;
            cout << "Welcome to the user panel." << endl;
            cout << "1) Get Only Program." << endl;
            cout << "2) Get User All Information." << endl;
            cout << "3) Get Exercise Time." << endl;
            cout << "4) Get Payment Monthly." << endl;
            cout << "5) Go to main menu." << endl;
            cout << "6) Exit." << endl;
            cout << "Which process do you prefer ?: ";
            cin >> choice2;
            cout << endl << endl;
            
            switch (choice2) {
                case 1:
                    cout << "Please enter the ID: ";
                    cin >> tempID;
                    cout << endl;
                    if(tempID == 0){
                        cout << "invalid ID!!!" << endl << endl;
                        goto menu4;
                    }
                    fitnessCostumerObject.findByIdProgram(myCostumerClass,tempID);
                    goto menu4;
                    break;
                case 2:
                    cout << "Please enter the ID: ";
                    cin >> tempID;
                    cout << endl;
                    if(tempID == 0){
                        cout << "invalid ID!!!" << endl << endl;
                        goto menu4;
                    }
                    fitnessCostumerObject.findByIdInformation(myCostumerClass,tempID);
                    goto menu4;
                case 3:
                    cout << "Please enter the ID: ";
                    cin >> tempID;
                    cout << endl;
                    if(tempID == 0){
                        cout << "invalid ID!!!" << endl << endl;
                        goto menu4;
                    }
                    fitnessCostumerObject.findByIdExerciseTime(myCostumerClass,tempID);
                    goto menu4;
                    break;
                case 4:
                    cout << "Please enter the ID: ";
                    cin >> tempID;
                    cout << endl;
                    if(tempID == 0){
                        cout << "invalid ID!!!" << endl << endl;
                        goto menu4;
                    }
                    fitnessCostumerObject.findByIdPayment(myCostumerClass,tempID);
                    goto menu4;
                    break;
                case 5:
                    goto menu3;
                    break;
                case 6:
                    exit(0);
                default:
                    cout << "Invalid Choice!!!" << endl;
                    goto menu4;
                    break;
            }
            break;
        case 3:
            cout << "Exit By By..." << endl;
            exit(0);
            break;
        default:
            break;
    }
    
    return 0;
}
