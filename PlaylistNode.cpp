#include <iostream>
using namespace std;

#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
  this->uniqueID = uniqueID;
  this->songName = songName;
  this->artistName = artistName;
  this->songLength = songLength;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
  PlaylistNode* temp = nullptr;

  temp = this->nextNodePtr; // temp holds value of next
  this->nextNodePtr = nodeLoc; // new next is the location specified
  nodeLoc->nextNodePtr = temp; // next after specified location is old next
}

void PlaylistNode::SetNext(PlaylistNode*& nextNode) {
  this->nextNodePtr = nextNode;
}

string PlaylistNode::GetID() const {
  return this->uniqueID; // previously return uniqueID
}

string PlaylistNode::GetSongName() const {
  return this->songName;
}

string PlaylistNode::GetArtistName() const {
  return this->artistName;
}

int PlaylistNode::GetSongLength() const {
  return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
  return this->nextNodePtr; // value held by nextNodePtr = next location
}

void PlaylistNode::PrintPlaylistNode() {
  cout << "Unique ID: " << GetID() << endl; // previosuyl this->GetID()
  cout << "Song Name: " << GetSongName() << endl;
  cout << "Artist Name: " << GetArtistName() << endl;
  cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
