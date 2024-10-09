#include <iostream>

using namespace std;

class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string title, string artist) {
        this->title = title;
        this->artist = artist;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = nullptr;
    }

    // Add a new song to the end of the playlist
    void addSong(string title, string artist) {
        Node* newNode = new Node(title, artist);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Traverse the playlist forwards
    void playNext() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        cout << "Playing: " << current->title << " by " << current->artist << endl;
    }

    // Traverse the playlist backwards
    void playPrevious() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (head->prev != nullptr) {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current = current->prev;
            cout << "Playing: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "Cannot play previous song. This is the first song." << endl;
        }
    }

    // Delete a song from the playlist
    void deleteSong(string title) {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                if (current->prev == nullptr) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current->next == nullptr) {
                    current->prev->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Song deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Song not found." << endl;
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Bohemian Rhapsody", "Queen");
    playlist.addSong("Stairway to Heaven", "Led Zeppelin");
    playlist.addSong("Hotel California", "Eagles");

    playlist.playNext();
    playlist.playPrevious();
    playlist.playNext();
    playlist.playPrevious();

    playlist.deleteSong("Stairway to Heaven");

    playlist.playNext();
    playlist.playPrevious();

    return 0;
}