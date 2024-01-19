#include<iostream>
#include<fstream>

using namespace std;

class shopping {

private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t___________________________________\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t      Supermarket Main Menu         \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t___________________________________\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t|   1)Admin    |\n";
    cout << "\t\t\t\t|              |\n";
    cout << "\t\t\t\t|   2)Buyer    |\n";
    cout << "\t\t\t\t|              |\n";
    cout << "\t\t\t\t|   3)Exit     |\n";
    cout << "\t\t\t\t|              |\n";
    cout << "\t\t\t  Please select!  ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\t\t\t please login \n";
        cout << "\t\t\t  Enter Email \n";
        cin >> email;

        cout << "\t\t\t Password    \n";
        cin >> password;

        if (email.compare("harshsukhija2002@gmail.com") == 0 && password.compare("harsh@0824") == 0) {
    admin();
} else {
    cout << "invalid email/password";
}

        
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
    default:
        cout << "please select from the given options";
    }

    goto m;
}

void shopping::admin() {
    m:
    int choice;
    cout << "\n\n\t\t\t    admin menu";
    cout << "\n\t\t\t|___1) Add the product____|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___2) Modify the product__|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___3) Delete the product__|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___4) Back to main menu___|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\n\t Please enter your choice";
    cin >> choice;

    switch (choice) {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice!";
    }

    goto m;
}

void shopping::buyer() {
    m:
    int choice;
    cout << "\t\t\t  Buyer\n";
    cout << "______________ \n";
    cout << "\t\t\t 1) Buy product \n";
    cout << "                 \n";
    cout << "\t\t\t 2) Go back  \n";
    cout << "                 \n";
    cout << "\t\t\t Enter your choice:";

    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "invalid choice";
    }
    goto m;
}

void shopping::add() {
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t  Add new product";
    cout << "\n\n\t\t Product code of the product";
    cin >> pcode;
    cout << "\n\n Name of the product";
    cin >> pname;
    cout << "\n\n\t price of the product";
    cin >> price;
    cout << "\n\n\t discount on product";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::out | ios::app);
        data << " " << pcode << pname << " " << price << "" << dis << "\n";
        data.close();
    } else {
        data >> c >> n >> p >> d;

        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1) {
            goto m;
        } else {
            data.open("database.txt", ios::out | ios::app);
            data << " " << pcode << pname << " " << price << "" << dis << "\n";
            data.close();
        }
        cout << "\n\n\t\t Record inserted!";
    }
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t  modify the record";
    cout << "\n\t\t\t   Product code :";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist!";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t product new code:";
                cin >> c;
                cout << "\n\t\t Name of the product:";
                cin >> n;
                cout << "\n\t\t Price:";
                cin >> p;
                cout << "\n\t\t Discount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n Record not Found sorry!";
        }
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product Code";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File does not exist";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\n\t Product deleted successfully";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n Record Not found";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_______________________________\n";
    cout << "ProNO\t\tName\t\tPrice\n";
    cout << "\n\n|_______________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() {
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();

        list();
        cout << "\n\n_____________________________\n";
        cout << "\n                               \n";
        cout << "\n   Please  place the order     \n";
        cout << "\n                               \n";
        cout << "\n\n_____________________________\n";
        do {
            cout << "\n\n Enter Product code:";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity:";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes then press y else no";
            cin >> choice;
        } while (choice == 'y');
        cout << "\n\n\t\t\t___________RECEIPT________\n";
        cout << "\nProduct no \t product Name\t product quantity\tprice\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    discount = amount - (amount * dis / 100);
                    total = total + discount;
                    cout << "\n" << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << discount;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }

    cout << "\n\n______________________________";
    cout << "\n Total amount: " << total;
}

int main() {
    shopping s;
    s.menu();
}
