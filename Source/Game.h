#pragma once

#include <GameDev2D.h>
#include "Piece.h"
#include "Constants.h"

namespace GameDev2D
{
	//Class definition
	class Game
	{
	public:
		Game();  //Constructor

		//Write game logic in the Update method
		void Update(double delta);

		//Render game objects in the Draw method
		void Draw();

		Piece* GetPiece(unsigned int row, unsigned int column);

		bool IsValid(int row, int column);

		bool Won();

		//Input methods
		void HandleLeftMouseClick(float mouseX, float mouseY);
		void HandleRightMouseClick(float mouseX, float mouseY);
		void HandleMouseMove(float mouseX, float mouseY, float previousX, float previousY);
		void HandleKeyPress(Keyboard::Key key);
		void HandleKeyReleased(Keyboard::Key key);
		
	private:
		//Member variables GO HERE
		Piece m_Pieces[PIECE_NUM];
		GameDev2D::Sprite m_Final;
		unsigned int m_OpenRow;
		unsigned int m_OpenColumn;

		unsigned int m_Moves;
	};
}
