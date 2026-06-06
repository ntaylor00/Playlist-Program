#ifndef PLAYLIST_NODE_H
#define PLAYLIST_NODE_H

#include <string>
using namespace std;

class PlaylistNode{

public:
  PlaylistNode();
  PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
  void InsertAfter(PlaylistNode* nodeLoc);
  void SetNext(PlaylistNode*& nextNode);
  string GetID() const;
  string GetSongName() const;
  string GetArtistName() const;
  int GetSongLength() const;
  PlaylistNode* GetNext() const;
  void PrintPlaylistNode();

private:
  string uniqueID;
  string songName;
  string artistName;
  int songLength;
  PlaylistNode* nextNodePtr;

};

#endif
