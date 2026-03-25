#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song* next;
    Song* prev;
};

void addSong(Song*& head, Song*& current, string title, string artist, int r1, r2, r3)
{

}

void changeSong(Song*& current, int i)
{
    if (i == 0)
    {

    }
    else
    {

    }
}

void removeCurrent(Song*& head, Song*& current)
{

}

void display(Song* head, Song* current)
{

}

int main()
{
    Song* head = nullptr;
    Song* current = nullptr;

    addSong(head, current, "Let It Happen", "Tame Impala", 9, 10, 9);
    addSong(head, current, "Smells Like Teen Spirit", "Nirvana", 8, 9, 10);
    addSong(head, current, "Hotel California", "Eagles", 8, 9, 8);

    current = head;

    string input;

    while (1)
    {
        cout << "Input: ";
        cin >> input;
        cout << "\n";

        if (input == "EXIT")
        {
            break;
        }
        else if (input == "NEXT")
        {
            changeSong(current, 0);
        }
        else if (input == "PREV")
        {
            changeSong(current, 1)
        }
        else if (input == "REMOVE")
        {
            removeCurrent(head, current);
        }

        display(head, current);
    }

    return 0;
}
