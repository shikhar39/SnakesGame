#include<iostream>
#include<conio.h>

bool gameOver;
const int width = 40, height = 20;
int x, y, xFruit, yFruit, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
bool foundTail;
void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	xFruit = rand() % width;
	yFruit = rand() % height;
	nTail = 0;
	score = 0;
}
void Draw() {
	system("cls");
	for (int i = 0; i < width; i++)
		std::cout << '#';
	std::cout << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				std::cout << '#';
			else if (i == y && j == x)
				std::cout << 'O';
			else if (i == yFruit && j == xFruit)
				std::cout << 'F';
			else {

			foundTail = false;
				for (int k = 0; k < nTail; k++) {
					if (j == tailX[k] && i == tailY[k]) {
						std::cout << 'o';
						foundTail = true;
					}
				}
				if(!foundTail)
					std::cout << ' ';
			}
			
		}
	std::cout << std::endl;
	}
	for (int i = 0; i < width; i++)
		std::cout << '#';
	std::cout << std::endl;

	std::cout << "Score: " << score;
}
void Input() {
	if (_kbhit()) {
		switch (_getch()){
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
		}
	}
}
void Logic() {
	int tempX, tempY, temp2X, temp2Y;
	tempX = x;
	tempY = y;
	for (int i = 0; i < nTail; i++) {
		temp2X = tailX[i];
		temp2Y = tailY[i];
		tailX[i] = tempX;
		tailY[i] = tempY;
		tempX = temp2X;
		tempY = temp2Y;
	}
	switch (dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
	}
	if (x < 0 || x >= width || y < 0 || y > height)
		gameOver = true;
	if (x == xFruit && y == yFruit) {
		score += 10;
		xFruit = rand() % width;
		yFruit = rand() % height;
		nTail++;
	}

}


int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}

	return 0;
}