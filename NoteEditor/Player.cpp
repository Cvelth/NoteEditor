#include "Player.hpp"
#include "NoteList.hpp"

#define _UNICODE
#include "CFugueLib.h"

Player::Player() {
	m_player = new CFugue::Player();
}

void Player::play(NoteList * notes) {
	m_player->Play(notes->getMidi().c_str());
}

void Player::exportMid(NoteList * notes, std::string & filename) {
	m_player->SaveAsMidiFile(notes->getMidi().c_str(), filename.c_str());
}
