#pragma once
#include <string>

class NoteList;
namespace CFugue {
	class Player;
}

class Player {
	CFugue::Player* m_player;
public:
	Player();
	void play(NoteList* notes);
	void exportMid(NoteList* notes, std::string&filename);
};