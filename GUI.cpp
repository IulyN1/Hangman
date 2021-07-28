#include "GUI.h"
#include <qboxlayout.h>
#include <time.h>

void GUI::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	QHBoxLayout* lyPlay = new QHBoxLayout;
	lyPlay->addWidget(btnPlay);
	lyPlay->addStretch();
	ly->addLayout(lyPlay);

	QHBoxLayout* lyHang = new QHBoxLayout;
	lyHang->addWidget(hangman);
	lyHang->addLayout(lyWord);
	ly->addLayout(lyHang);

	QHBoxLayout* lyBtns1 = new QHBoxLayout;
	lyBtns1->addWidget(btnA);
	lyBtns1->addWidget(btnB);
	lyBtns1->addWidget(btnC);
	lyBtns1->addWidget(btnD);
	lyBtns1->addWidget(btnE);
	lyBtns1->addWidget(btnF);
	lyBtns1->addWidget(btnG);
	lyBtns1->addWidget(btnH);
	lyBtns1->addWidget(btnI);
	lyBtns1->addWidget(btnJ);
	lyBtns1->addWidget(btnK);
	lyBtns1->addWidget(btnL);
	lyBtns1->addWidget(btnM);

	QHBoxLayout* lyBtns2 = new QHBoxLayout;
	lyBtns2->addWidget(btnN);
	lyBtns2->addWidget(btnO);
	lyBtns2->addWidget(btnP);
	lyBtns2->addWidget(btnQ);
	lyBtns2->addWidget(btnR);
	lyBtns2->addWidget(btnS);
	lyBtns2->addWidget(btnT);
	lyBtns2->addWidget(btnU);
	lyBtns2->addWidget(btnV);
	lyBtns2->addWidget(btnW);
	lyBtns2->addWidget(btnX);
	lyBtns2->addWidget(btnY);
	lyBtns2->addWidget(btnZ);

	ly->addLayout(lyBtns1);
	ly->addLayout(lyBtns2);
	ly->addWidget(result);
}

void GUI::checkLetter(char let) {
	bool found = false;
	for (int i = 0; i < currentWord.length(); i++) {
		if (let == currentWord[i]) {
			found = true;
			auto letter = qobject_cast<QLabel*>(lyWord->itemAt(i+1)->widget());
			QString txt = let;
			letter->setText(txt);
		}
	}
	if (!found) {
		mistakes++;
	}
	switch (mistakes) {
	case 0:
		hangman->setPixmap(QPixmap("resources/hangman1.png"));
		break;
	case 1:
		hangman->setPixmap(QPixmap("resources/hangman2.png"));
		break;
	case 2:
		hangman->setPixmap(QPixmap("resources/hangman3.png"));
		break;
	case 3:
		hangman->setPixmap(QPixmap("resources/hangman4.png"));
		break;
	case 4:
		hangman->setPixmap(QPixmap("resources/hangman5.png"));
		break;
	case 5:
		hangman->setPixmap(QPixmap("resources/hangman6.png"));
		break;
	case 6:
		hangman->setPixmap(QPixmap("resources/hangman7.png"));
		break;
	}
	if (mistakes == 6) {
		result->setText("Result: You lost!");
	}
	int aux = 0;
	for (int i = 0; i < currentWord.length(); i++) {
		auto letter = qobject_cast<QLabel*>(lyWord->itemAt(i + 1)->widget());
		if (letter->text() == "_") {
			aux++;
		}
	}
	if (aux == 0) {
		result->setText("Result: You won!");
	}
}

void GUI::connectSignals() {
	srand(time(NULL));
	connect(btnPlay, &QPushButton::clicked, this, [=]() {
		mistakes = 0;
		hangman->setPixmap(QPixmap("resources/hangman1.png"));
		result->setText("Result:");

		int num = rand() % words.size();
		currentWord = words[num];

		QLayoutItem* item;
		while ((item = lyWord->takeAt(0)) != NULL) {
			delete item->widget();
			delete item;
		}

		lyWord->addStretch();
		for (int i = 0; i < currentWord.length(); i++) {
			QLabel* letter = new QLabel{"_"};
			letter->setStyleSheet("QLabel{font-size: 30px;}");
			lyWord->addWidget(letter);
		}
		lyWord->addStretch();
		});

	connect(btnA, &QPushButton::clicked, this, [=]() {
		checkLetter('A');
		});
	connect(btnB, &QPushButton::clicked, this, [=]() {
		checkLetter('B');
		});
	connect(btnC, &QPushButton::clicked, this, [=]() {
		checkLetter('C');
		});
	connect(btnD, &QPushButton::clicked, this, [=]() {
		checkLetter('D');
		});
	connect(btnE, &QPushButton::clicked, this, [=]() {
		checkLetter('E');
		});
	connect(btnF, &QPushButton::clicked, this, [=]() {
		checkLetter('F');
		});
	connect(btnG, &QPushButton::clicked, this, [=]() {
		checkLetter('G');
		});
	connect(btnH, &QPushButton::clicked, this, [=]() {
		checkLetter('H');
		});
	connect(btnI, &QPushButton::clicked, this, [=]() {
		checkLetter('I');
		});
	connect(btnJ, &QPushButton::clicked, this, [=]() {
		checkLetter('J');
		});
	connect(btnK, &QPushButton::clicked, this, [=]() {
		checkLetter('K');
		});
	connect(btnL, &QPushButton::clicked, this, [=]() {
		checkLetter('L');
		});
	connect(btnM, &QPushButton::clicked, this, [=]() {
		checkLetter('M');
		});
	connect(btnN, &QPushButton::clicked, this, [=]() {
		checkLetter('N');
		});
	connect(btnO, &QPushButton::clicked, this, [=]() {
		checkLetter('O');
		});
	connect(btnP, &QPushButton::clicked, this, [=]() {
		checkLetter('P');
		});
	connect(btnQ, &QPushButton::clicked, this, [=]() {
		checkLetter('Q');
		});
	connect(btnR, &QPushButton::clicked, this, [=]() {
		checkLetter('R');
		});
	connect(btnS, &QPushButton::clicked, this, [=]() {
		checkLetter('S');
		});
	connect(btnT, &QPushButton::clicked, this, [=]() {
		checkLetter('T');
		});
	connect(btnU, &QPushButton::clicked, this, [=]() {
		checkLetter('U');
		});
	connect(btnV, &QPushButton::clicked, this, [=]() {
		checkLetter('V');
		});
	connect(btnW, &QPushButton::clicked, this, [=]() {
		checkLetter('W');
		});
	connect(btnX, &QPushButton::clicked, this, [=]() {
		checkLetter('X');
		});
	connect(btnY, &QPushButton::clicked, this, [=]() {
		checkLetter('Y');
		});
	connect(btnZ, &QPushButton::clicked, this, [=]() {
		checkLetter('Z');
		});
}

void GUI::setInitialState() {
	hangman->setPixmap(QPixmap("resources/hangman1.png"));
}