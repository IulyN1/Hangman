#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qboxlayout.h>

class GUI: public QWidget
{
private:
	QPushButton* btnA = new QPushButton{ "A" };
	QPushButton* btnB = new QPushButton{ "B" };
	QPushButton* btnC = new QPushButton{ "C" };
	QPushButton* btnD = new QPushButton{ "D" };
	QPushButton* btnE = new QPushButton{ "E" };
	QPushButton* btnF = new QPushButton{ "F" };
	QPushButton* btnG = new QPushButton{ "G" };
	QPushButton* btnH = new QPushButton{ "H" };
	QPushButton* btnI = new QPushButton{ "I" };
	QPushButton* btnJ = new QPushButton{ "J" };
	QPushButton* btnK = new QPushButton{ "K" };
	QPushButton* btnL = new QPushButton{ "L" };
	QPushButton* btnM = new QPushButton{ "M" };
	QPushButton* btnN = new QPushButton{ "N" };
	QPushButton* btnO = new QPushButton{ "O" };
	QPushButton* btnP = new QPushButton{ "P" };
	QPushButton* btnQ = new QPushButton{ "Q" };
	QPushButton* btnR = new QPushButton{ "R" };
	QPushButton* btnS = new QPushButton{ "S" };
	QPushButton* btnT = new QPushButton{ "T" };
	QPushButton* btnU = new QPushButton{ "U" };
	QPushButton* btnV = new QPushButton{ "V" };
	QPushButton* btnW = new QPushButton{ "W" };
	QPushButton* btnX = new QPushButton{ "X" };
	QPushButton* btnY = new QPushButton{ "Y" };
	QPushButton* btnZ = new QPushButton{ "Z" };
	QPushButton* btnPlay = new QPushButton{ "Play" };
	QLabel* result = new QLabel{"Result: "};
	int mistakes = 0;
	QLabel* hangman = new QLabel;
	QHBoxLayout* lyWord = new QHBoxLayout;
	QStringList words = {"WATER","FOOD","HANGMAN","LEGEND","CODING","LOVE","MICROSOFT","WINDOWS"};
	QString currentWord;

	// Function that initializes the GUI components
	void initGui();

	// Function that connects the signals of the GUI components
	void connectSignals();

	// Function that sets the initial state of the GUI
	void setInitialState();

	// Function that checks if the letter is in the current word
	// let - character
	void checkLetter(char let);
public:
	GUI() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

