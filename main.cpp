#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
  cout << playlistTitle << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;

  cout << endl << "Choose an option:" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if (option == 'a') {
     string songID;
     string temp;
     string songName;
     string songArtist;
     int songLength;
     PlaylistNode* currNode = nullptr;

     cout << "ADD SONG" << endl;
     cout << "Enter song\'s unique ID:" << endl;
     cin >> songID;
     cout << "Enter song\'s name:" << endl;
     getline(cin, temp);
     getline(cin, songName);
     cout << "Enter artist\'s name:" << endl;
     getline(cin, songArtist);
     cout << "Enter song\'s length (in seconds):" << endl;
     cin >> songLength;
     cout << endl << endl;

     //currNode = headNode;
     //currNode->SetNext(headNode);
     currNode = new PlaylistNode(songID, songName, songArtist, songLength);
     headNode->InsertAfter(currNode);
     headNode = currNode;
   }
  else if (option == 'd') {
    PlaylistNode* tempNode = nullptr;
    PlaylistNode* tempNode2 = nullptr;
    bool keepGoing = true;
    string songID;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song\'s unique ID:" << endl;
    cin >> songID;

    headNode = headNode->GetNext();
    while (headNode != nullptr && keepGoing) {
      while (headNode->GetID() != songID){
        tempNode = headNode;
        headNode = headNode->GetNext();
      }
      if (headNode->GetID() == songID) {
        tempNode2 = headNode->GetNext();
        tempNode->SetNext(tempNode2);
        cout << "\"" << headNode->GetSongName() << "\" removed." << endl << endl;
        //headNode = headNode->GetNext();
        headNode = tempNode;
        keepGoing = false;
      }
      if (keepGoing == false) {
         while (headNode != nullptr) {
            headNode = headNode->GetNext();
         }
      }
    }
   }
  else if (option == 's') {
    int songNum = 1;
    string artistName;
    string temp;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist\'s name:" << endl;
    getline(cin, temp);
    getline(cin, artistName);
    cout << endl;
    headNode = headNode->GetNext();
    while (headNode != nullptr) {
      if (headNode->GetArtistName() == artistName) {
        cout << songNum << "." << endl;
        headNode->PrintPlaylistNode();
        cout << endl;
      }
      headNode = headNode->GetNext();
      songNum = songNum + 1;
    }
   }
  else if (option == 't') {
    int timeTotal = 0;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    headNode = headNode->GetNext();
    while (headNode != nullptr) {
      timeTotal = timeTotal + headNode->GetSongLength();
      headNode = headNode->GetNext();
    }
    cout << "Total time: " << timeTotal <<  " seconds" << endl;
   }
  else if (option == 'o') {
    int songNum = 1;
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

    if (headNode->GetNext() == nullptr) {
      cout << "Playlist is empty" << endl << endl;
    }

    else {
      headNode = headNode->GetNext();
      while (headNode != nullptr) {
        cout << songNum << "." << endl;
        headNode->PrintPlaylistNode();
        headNode = headNode->GetNext();
        songNum = songNum + 1;
      }
    }

   }
  else if (option == 'q') {
    option = 'q';
   }

   return headNode;
}

int main() {
  char choice;
  int numSong = 0;
  string playlistTitle;
  PlaylistNode* headNode = nullptr;
  PlaylistNode* lastNode; // = nullptr;
  //PlaylistNode* tempNode; // = nullptr;

  headNode = new PlaylistNode();
  lastNode = headNode;

  cout << "Enter playlist\'s title:" << endl << endl;
  getline(cin, playlistTitle);

  PrintMenu(playlistTitle);
  cin >> choice;

  while (choice != 'q') {
    while (choice != 'a' && choice != 'd' && choice != 's' && choice != 't' && choice != 'o' && choice != 'q') {
      cout << "Invalid choice." << endl;
      PrintMenu(playlistTitle);
      cin >> choice;
    }
    if (choice != 'a' && choice != 'q') {
      ExecuteMenu(choice, playlistTitle, headNode);
      //previously headNode
      numSong = numSong + 1;
      if (choice == 'd') {
        numSong = numSong - 1;
      }
    }
    else if (choice == 'd') {
       lastNode = ExecuteMenu(choice, playlistTitle, lastNode); ///////
    }
    else {
      lastNode = ExecuteMenu(choice, playlistTitle, lastNode); // overwrite the pointer to the head node of the playlist with the returned pointer
    }
    if (numSong == 1) {
      headNode = lastNode;
    }
    PrintMenu(playlistTitle);
    cin >> choice;
  }

   return 0;
}
