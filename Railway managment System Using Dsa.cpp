#include <iostream>
#include <fstream>
using namespace std;

class Railway {
private:
    class Node {
    public:
        int id, date;
        string name;
        string traintype;
        Node* next;
    };

public:
    Node* head = 0;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void show();
    void writeToFile();
};

void Railway::menu() {
    int choice;
    cout << "\n";
    cout << "\t __Welcome to Lahore Railway__" << endl;
    cout << "\n\t___Railway Managment System___" << endl;
    cout << "" << endl;
    cout << "\n\t Press 1 Allocate a Train";
    cout << "\n\t Press 2 to Search Train ( with room id)";
    cout << "\n\t Press 3 to Update Train record";
    cout << "\n\t Press 4 to Delete a Train ";
    cout << "\n\t Press 5 to Show Records";
    cout << "\n\t Press 6 to Save Data  ";

    cout << "\n\nEnter your choice :" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        insert();
        menu();
    case 2:
        search();
        menu();
    case 3:
        update();
        menu();
    case 4:
        del();
        menu();
    case 5:
        show();
        menu();
    case 6:
        writeToFile();
        menu();
    default:
        cout << "invalid";
    }
}

void Railway::insert() {
    cout << "\n\t___Railway Managment System__";
    Node* new_node = new Node;
    cout << "\nEnter the Train ID : " << endl;
    cin >> new_node->id;
    cout << "\nEnter Customer Name : " << endl;
    cin >> new_node->name;
    cout << "\nEnter Allocated Date : " << endl;
    cin >> new_node->date;
    cout << "\nEnter Train Type [First Class (F) /Middle Class  (M)] :" << endl;
    cin >> new_node->traintype;

    if (head == 0) {
        head = new_node;
    } else {
        Node* ptr = head;
        while (ptr->next != 0) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout << "\n\n\t\t New Passenger Record Inserted Successfully";
}

void Railway::search() {
    cout << "\n\t____Railway Managment System__";
    int t_id;
    if (head == 0) {
        cout << "the list is empty";
    } else {
        cout << "\n\nPlzz Enter the Train Id  :  ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != 0) {
            if (t_id == ptr->id) {
                cout << "\n\nTrain Id   " << ptr->id;
                cout << "\n\nCustomer name    " << ptr->name;
                cout << "\n\nTrain Allocatd date   " << ptr->date;
                cout << "\n\nTrain Type    " << ptr->traintype;
            }
            ptr = ptr->next;
        }
    }
}

void Railway::update() {
    cout << "\n\t____Railway Managment System__";
    int t_id;
    if (head == 0) {
        cout << "the list is empty";
    } else {
        cout << "\n\n Train Id: ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != 0) {
            if (t_id == ptr->id) {
                cout << "\n\nTRAIN Id  :  ";
                cin >> ptr->id;

                cout << "\n\nCustomer name : ";
                cin >> ptr->name;

                cout << "\n\nAllocated date  :  ";
                cin >> ptr->date;

                cout << "\n\nTrain type :  ";
                cin >> ptr->traintype;

                cout << "\n\n\t\t updated succesfuuly  : ";
            }
            ptr = ptr->next;
        }
    }
}

void Railway::del() {
    cout << "\n\t____Railway Managment System__";
    int t_id;
    if (head == 0) {
        cout << "the list is empty";
    } else {
        cout << "\n\n Train Id : ";
        cin >> t_id;
        if (t_id == head->id) {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Deleted Train record sucessfully" << endl;
        } else {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != 0) {
                if (t_id == ptr->id) {
                    pre->next = ptr->next;
                    delete ptr;

                    cout << "Delete Train reccord sucessfully" << endl;
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void Railway::show() {
    Node* ptr = head;
    int result, days, price;
    while (ptr != 0) {
        cout << "\n\nTrain Id         " << ptr->id;
        cout << "\n\ncustomer name   " << ptr->name;
        cout << "\n\nAllocated date  " << ptr->date;
        cout << "\n\nTrain type       " << ptr->traintype;

        cout << endl
             << "Enter Train Arrive Time: ";
        cin >> days;
        cout << endl
             << "Enter price of train ticket: ";
        cin >> price;
        result = price * days;
        cout << endl
             << "Total payable Amount: " << result;
        ptr = ptr->next;
    }
}

void Railway::writeToFile() {
    ofstream file("Railway_data.txt");

    if (!file.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    cout << "The data saved successfully!!" << endl;

    Node* ptr = head;
    while (ptr != 0) {
        file << ptr->id << " "
             << ptr->name << " "
             << ptr->date << " "
             << ptr->traintype << endl;
        ptr = ptr->next;
    }

    file.close();
}

int main() {
    Railway r;
    r.menu();
    return 0;
}

