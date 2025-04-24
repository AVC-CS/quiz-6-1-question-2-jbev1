#include <iostream>
#include <fstream>

using namespace std;

int writeFile(int);
int readFile(int);


int writeFile(string filename)
{
    int employeeNum, id;
    string name, depart;
    double salary;
    ofstream ofs;

    ofs.open(filename);
    if (!ofs)
    {
        cout << "File Open Error\n";
        exit(0);
    }

    cin >> employeeNum;
    ofs << employeeNum << endl;

    for (int i = 0; i < employeeNum; i++)
    {
        cin >> id >> name >> depart >> salary;
        ofs << id << " " << name << " " << depart << " " << salary << endl;
    }

    ofs.close();
    return employeeNum;
}

int readFile(string filename)
{
    int total, avg, id, iterations;
    double salary;
    string name, depart;
    total = 0;
    avg = 0;
    ifstream ifs;

    ifs.open("employee.txt");
    if (!ifs)
    {
        cout << "File Open Error\n";
        exit(0);
    }

    ifs >> iterations;

    cout << "ID     Name    Department  Salary" << endl;

    for (int i = 0; i < iterations; i++)
    {
        ifs >> id >> name >> depart >> salary;
        cout << id << " " << name << " " << depart << " " << salary << endl;
        total += salary;
    }
    avg = (total / iterations);
    cout << total << " " << avg;
    return iterations;
}