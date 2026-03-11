#include <iostream>
#include <string>

using namespace std;

struct node {
    string data;
    struct node* next;
};

void addWord(string word)
{

}

void undo()
{

}

void display()
{

}

int main()
{
    string input;

    while (1)
    {
        cout << "Input: ";
        cin >> input;

        if (input == "EXIT")
        {
            break;
        }
        else if (input == "UNDO")
        {
            undo();
        }
        else
        {
            addWord(input);
        }

        display();
    }

    return 0;
}
