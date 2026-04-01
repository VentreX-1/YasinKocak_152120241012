#include <iostream>
#include <string>
using namespace std;

struct Package 
{
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier 
{
    string courierName;
    string vehicleType;
};

Package* topStack = NULL;

const int SIZE = 5;
Courier queueArr[SIZE];
int front = -1;
int rear = -1;

void pushPackage(string id, string city, int d1, int d2, int d3) 
{
    Package* newP = new Package;
    newP->packageID = id;
    newP->destinationCity = city;
    newP->dimensions[0] = d1;
    newP->dimensions[1] = d2;
    newP->dimensions[2] = d3;
    newP->next = topStack;
    topStack = newP;
}

void popPackage() 
{
    if (topStack == NULL) 
    {
        return;
    }
    Package* temp = topStack;
    topStack = topStack->next;
    delete temp;
}

void enqueueCourier(string name, string type) 
{
    if ((rear + 1) % SIZE == front) 
    {
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queueArr[rear].courierName = name;
    queueArr[rear].vehicleType = type;
}

void dequeueCourier() 
{
    if (front == -1) 
    {
        return;
    }
    if (front == rear) 
    {
        front = rear = -1;
    } 
    else 
    {
        front = (front + 1) % SIZE;
    }
}

void dispatch() 
{
    if (topStack == NULL || front == -1) 
    {
        return;
    }
    cout << "Courier: " << queueArr[front].courierName << " package : " << topStack->packageID << endl;
    popPackage();
    dequeueCourier();
}

void displayPackages() 
{
    Package* temp = topStack;
    while (temp != NULL)
    {
        cout << temp->packageID << " " << temp->destinationCity << endl;
        temp = temp->next;
    }
}

void displayCouriers() 
{
    if (front == -1) return;
    int i = front;
    while (1)
    {
        cout << queueArr[i].courierName << " " << queueArr[i].vehicleType << endl;
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
}

int main() 
{
    pushPackage("P1", "Afyon", 10, 20, 30);
    pushPackage("P2", "Eskisehir", 5, 5, 5);

    enqueueCourier("Yasin", "Truck");
    enqueueCourier("Emre", "Car");

    displayPackages();
    cout << "---\n";
    displayCouriers();

    cout << "--- dispatch ---\n";
    dispatch();

    displayPackages();
    cout << "---\n";
    displayCouriers();


    return 0;
}