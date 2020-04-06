#ifndef CHOICE_H_
#define CHOICE_H_

#include "wx/wx.h"
#include <string>


// Choice represented by int.
typedef int Choice;

// Which object a player chooses each round.
enum { ROCK, PAPER, SCISSORS, NONE };

/**
 * Convert a chosen object to a wxString.
 * @param choice the object to convert.
 * @return the wxString.
 */
wxString choice_to_wxString(Choice choice);

/**
 * Converts a chosen object into a string
 * @param choice the object to convert
 * @return the string
 */
std::string choice_to_String(Choice choice);

/**
 * Converts the outcome of the round into a wxString
 * @param the string of the outcome
 * @return the wxString
 */
wxString outcome_to_wxString(std::string str);

/**
 * Converts the player's score into a wxString
 * @param the score
 * @return the wxString
 */
wxString score_to_wxString(int score);

#endif /* CHOICE_H_ */
