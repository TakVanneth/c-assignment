#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
    int i, j;
    string IdSearch, Idupdate;
    int manyStaff, manyCustomer;
    bool found = false;
class staffManagement
{
protected:
    static const int a = 50; // add to class allow add array
    string name[a], age[a], contact[a], gender[a], id[a], position[a];
    int count;
public:
    staffManagement() : count(0) {} // add to class allow add array
    void insertStaff()
    {
    cout <<"\nHow many staff do you went to add ? Enter: ";
    cin >>manyStaff;
        if(count + manyStaff <= a){
            for (j = 0 ; j < manyStaff ; j++){
                cout << "\nStaff #" << count + j + 1 << " Information:\n";
                cout << "\nStaff's name: ";
                cin.ignore();
                getline(cin, name[count + j]);
                cout <<"\nId:";
                cin >> id[count + j];
                cout << "\nGender: ";
                cin >> gender[count + j];
                cout << "\nage: ";
                cin >> age[count + j];
                cout << "\ncontact: ";
                cin.ignore();getline(cin, contact[count + j]);
                cout << "\nPosition: ";
                getline(cin, position[count + j]);
            }
        count += manyStaff;
        }else{
            cout <<"\nDatabase have limited.\n";
        }
        
    }
    void displayStaff()
    {
         if (count == 0)
    {
        cout << "\nNo staff information available." << endl;
        return;
    }
        for(i = 0 ; i < count ; i++){
        cout << "\nStaff #" << i + 1 << " Information:\n";
        cout << "\nName: " << name[i] << endl;
        cout << "\nid: " << id[i] << endl;
        cout << "\nGender: " << gender[i] << endl;
        cout << "\nAge: " << age[i] << endl;
        cout << "\nContact: " << contact[i] << endl;
        cout << "\nPosition: " << position[i] << endl;
        }
    }
    void searchByIdStaff(){
    cout <<"\nEnter the Id to search:"; cin >> IdSearch;
    // bool found = false;
        for(i = 0 ; i < count ; i++){
            if(id[i] == IdSearch){
                cout << "\nName: " << name[i] << endl;
                cout << "\nid: " << id[i] << endl;
                cout << "\nGender: " << gender[i] << endl;
                cout << "\nAge: " << age[i] << endl;
                cout << "\nContact: " << contact[i] << endl;
                cout << "\nPosition: " << position[i] << endl;
                found = true;
            }
            if(!found){
                cout << "\nNo staff with ID " << IdSearch << " found in database.\n";
            }
        }
    }
    void updateByIdStaff(){
    cout <<"\nEnter the Id to updates:"; cin >> Idupdate;
        // bool found = false;
        for (i = 0 ; i < count ; i++){
            if(id[i] == Idupdate){
                cout << "\nNew Name: ";
                cin.ignore();getline(cin, name[i]);
                cout << "\nNew id: ";
                cin >> id[i];
                cout << "\nNew Gender: ";
                cin >> gender[i];
                cout << "\nNew Age: ";
                cin >> age[i];
                cout << "\nNew Contact: ";
                cin.ignore();getline(cin, contact[i]);
                cout << "\nNew Position: ";
                cin.ignore();getline(cin, position[i]);
                found = true;
            }
            if(!found){
                cout << "\nNo staff with ID " << IdSearch << " found in database.\n";
            }
        }
    }
    void saveToFileStaff(const string& filename)
    {
        fstream addFile(filename, ios::app);
        if (!addFile)
        {
            cout << "\nError opening the file for writing." << endl;
            return;
        }

        addFile << count << endl; // Save the number of staff members

        for (int i = 0; i < count; ++i)
        {
            // addFile << name[i] << endl;
            // addFile << id[i] << endl;
            // addFile << gender[i] << endl;
            // addFile << age[i] << endl;
            // addFile << contact[i] << endl;
                    addFile << left
                << setw(25) << name[i]
                << setw(25) << id[i]
                << setw(15) << gender[i]
                << setw(25) << age[i]
                << setw(15) << contact[i]
                << setw(25) << position[i]
                << endl;       
        }

        cout << "\nStaff information saved to " << filename << endl;
    }
// Delete
    void deleteByIdStaff(){
        cout << "\nEnter the Id to delete: ";
        cin >> IdSearch;
        for (size_t i = 0; i < count; i++)
        {
            if(id[i] == IdSearch){
                found = true;
                break;
            }
        }
        if(found){
            for (size_t j = i; j < count - 1; j++)
            {
                id[j] = id[j + 1];
            }
            count--;
            cout << "\nStaff with ID " << IdSearch << " has been deleted.\n";
        }
        else
    {
        cout << "\nNo staff with ID " << IdSearch << " found in the database.\n";
    }
    }

//
};
// Customer 
class customerManagement : public staffManagement {
        protected:
            string customer_name[a], customer_age[a], customer_contact[a], customer_gender[a], customer_id[a];
            int customer_count;

        public:
            customerManagement() : customer_count(0) {} // Initialize customer_count

        void insertCustomer() {
            cout << "\nHow many customers do you want to add? Enter: ";
            cin >> manyCustomer;
            if (customer_count + manyCustomer <= a) {
                for (j = 0; j < manyCustomer; j++) {
                    cout << "\nCustomer #" << customer_count + j + 1 << " Information:\n";
                    cout << "\nCustomer's name: ";
                    cin.ignore();
                    getline(cin, customer_name[customer_count + j]);
                    cout << "\nId:";
                    cin >> customer_id[customer_count + j];
                    cout << "\nGender: ";
                    cin >> customer_gender[customer_count + j];
                    cout << "\nage: ";
                    cin >> customer_age[customer_count + j];
                    cout << "\ncontact: ";
                    cin.ignore();
                    getline(cin, customer_contact[customer_count + j]);
                }
                customer_count += manyCustomer;
            } else {
                cout << "\nDatabase has limited.\n";
            }
        }

        void displayCustomer() {
            if (customer_count == 0) {
                cout << "\nNo Customer information available." << endl;
                return;
            }
            for (i = 0; i < customer_count; i++) {
                cout << "\nCustomer #" << i + 1 << " Information:\n";
                cout << "\nName: " << customer_name[i] << endl;
                cout << "\nid: " << customer_id[i] << endl;
                cout << "\nGender: " << customer_gender[i] << endl;
                cout << "\nAge: " << customer_age[i] << endl;
                cout << "\nContact: " << customer_contact[i] << endl;
            }
        }
    void searchByIdCustomer(){
    cout <<"\nEnter the Id to search:"; cin >> IdSearch;
    // bool found = false;
        for(i = 0 ; i < customer_count ; i++){
            if(id[i] == IdSearch){
                cout << "\nName: " << name[i] << endl;
                cout << "\nid: " << id[i] << endl;
                cout << "\nGender: " << gender[i] << endl;
                cout << "\nAge: " << age[i] << endl;
                cout << "\nContact: " << contact[i] << endl;
                found = true;
            }
            if(!found){
                cout << "\nNo Customer with ID " << IdSearch << " found in database.\n";
            }
        }
    }
    void updateByIdCustomer() {
        cout << "\nEnter the Customer Id to update: ";
        cin >> Idupdate;

        for (i = 0; i < customer_count; i++) {
            if (customer_id[i] == Idupdate) {
                cout << "\nNew Name: ";
                cin.ignore();
                getline(cin, customer_name[i]);
                cout << "\nNew id: ";
                cin >> customer_id[i];
                cout << "\nNew Gender: ";
                cin >> customer_gender[i];
                cout << "\nNew Age: ";
                cin >> customer_age[i];
                cout << "\nNew Contact: ";
                cin.ignore();
                getline(cin, customer_contact[i]);
                found = true;
            }
        }

        if (!found) {
            cout << "\nNo Customer with ID " << Idupdate << " found in database.\n";
        }
    }
    void saveToFileCustomer(const string& filename)
    {
        fstream addFile(filename, ios::app);
        if (!addFile)
        {
            cout << "\nError opening the file for writing." << endl;
            return;
        }

        addFile << customer_count << endl; // Save the number of staff members

        for (int i = 0; i < customer_count ; ++i)
        {
                    addFile << left
                << setw(25) << customer_name[i]
                << setw(25) << customer_id[i]
                << setw(15) << customer_gender[i]
                << setw(25) << customer_age[i]
                << setw(15) << customer_contact[i]
                << endl;       
        }

        cout << "\nCustomer information saved to " << filename << endl;
    }
void deleteByIdCustomer() {
    cout << "\nEnter the Id to delete: ";
    cin >> IdSearch;
    found = false;

    for (size_t i = 0; i < customer_count; i++) {
        if (customer_id[i] == IdSearch) { // Compare with customer_id array
            found = true;
            break;
        }
    }

    if (found) {
        for (size_t j = i; j < customer_count - 1; j++) {
            // Shift customer data to remove the deleted entry
            customer_name[j] = customer_name[j + 1];
            customer_id[j] = customer_id[j + 1];
            customer_gender[j] = customer_gender[j + 1];
            customer_age[j] = customer_age[j + 1];
            customer_contact[j] = customer_contact[j + 1];
        }
        customer_count--;
        cout << "\nCustomer with ID " << IdSearch << " has been deleted.\n";
    } else {
        cout << "\nNo customer with ID " << IdSearch << " found in the database.\n";
    }
}

};

void login()
{
    string username, password;
start:
    cout << "\nEnter your username:";
    cin >> username;
    cout << "\nEnter your password:";
    cin >> password;
    if (username == "admin" && password == "123")
    {
        system("clear");
    cout << "\nSuccessfully logged in\n";
    }else{
        system("clear");
        cout << "\nInvalid Password. Please try again\n";
        goto start;
    }
}

int main()
{
    int choice, ch1, ch2, ch3, ch4;
    login();
    customerManagement it;
    do
    {
    home:
        cout <<"\n1. Staff Management\n";
        cout <<"\n2. Customer Management\n";
        cout <<"\n3. BIU Mobile\n";
        cout <<"\n4. About Us\n";
        cout <<"\n5. Exit\n";
        cout <<"\nEnter your choice: ";
        cin >> choice;
        system("clear");
        if (choice == 1) // Staff Management
        {            
            // staffManagement it;
            do
            {
            system("clear");
                cout << "\n1. Insert Staff Information\n";
                cout << "\n2. Display Staff Information\n";
                cout << "\n3. Search Staff Information\n";
                cout << "\n4. Update Staff Information\n";
                cout << "\n5. Save Staff Information\n";
                cout << "\n6. Delete Staff Information\n";
                cout << "\n7. Exit to Main Menu\n";
                cout << "\nEnter your choice: ";
                cin >> ch1;
                system("clear");
                switch (ch1)
                {
                case 1:
                    it.insertStaff();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    it.displayStaff();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 3:
                    it.searchByIdStaff();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    it.updateByIdStaff();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 5:
                    it.saveToFileStaff("staff_info.txt");
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 6:
                    it.displayStaff(); // Display staff before deleting
                    it.deleteByIdStaff();
                    it.displayStaff(); // Display staff after deleting
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 7:
                goto home;
                default:
                    cout << "\nInvalid choice\n";
                    break;
                }
            } while (true);
        }
        else if (choice == 2)
        {
            // Handle customer management
            do
            {
                  system("clear");
                cout << "\n1. Insert Customer Information\n";
                cout << "\n2. Display Customer Information\n";
                cout << "\n3. Search Customer Information\n";
                cout << "\n4. Update Customer Information\n";
                cout << "\n5. Save Customer Information\n";
                cout << "\n6. Delete Customer Information\n";
                cout << "\n7. Exit to Main Menu\n";
                cout << "\nEnter your choice: ";
                cin >> ch2;
                system("clear");
                switch (ch2)
                {
                case 1:
                    it.insertCustomer();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    it.displayCustomer();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 3:
                    it.searchByIdCustomer();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    it.updateByIdCustomer();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 5:
                    it.saveToFileCustomer("customer_info.txt");
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                case 6:
                    it.displayCustomer(); // Display staff before deleting
                    it.deleteByIdCustomer();
                    it.displayCustomer(); // Display staff after deleting
                    cout << "\nPress Enter to continue...";
                    cin.ignore();cin.get();
                    break;
                case 7:
                goto home;
                default:
                cout << "\nInvalid choice\n";
                    break;
                }
            } while (true);
            
        }
        else if (choice == 3)
        {
            // Handle BIU Mobile
        }
        else if (choice == 4)
        {
            // Handle About Us
        }
        else if (choice == 5)
        {
            cout << "\nExiting program...\n";
            break;
        }
        else
        {
            cout << "\nInvalid choice\n";
        }

    } while (true);

    return 0;
}
