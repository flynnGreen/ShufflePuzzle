#pragma once

#include <GameDev2D.h>
#include "Constants.h"

namespace GameDev2D
{
	class Piece
	{
	public:
		Piece(unsigned int index);

		void Update(double delta);
		void Draw();
		void SetIndex(unsigned int index);
		int GetIndex();
		void SetColumn(unsigned int column);
		void SetRow(unsigned int row);
		unsigned int GetColumn();
		unsigned int GetRow();

	private:
		GameDev2D::Sprite m_Sprite;
		unsigned int m_Row;
		unsigned int m_Column;
	};
}