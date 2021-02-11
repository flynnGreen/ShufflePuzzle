#include "Piece.h"

namespace GameDev2D
{
	Piece::Piece(unsigned int index) :
		m_Sprite(),
		m_Row(0),
		m_Column(0)
	{
		SetIndex(index);
		std::string filename = std::to_string(index);
		LoadTexture(filename);
		m_Sprite.SetTexture(filename);
	}
		void Piece::Update(double delta)
		{
			float x = m_Column * PIECE_SIZE;
			float y = GetScreenHeight() - (m_Row * PIECE_SIZE) - PIECE_SIZE;

			m_Sprite.SetPosition(x, y);
		}

		void Piece::Draw()
		{
			m_Sprite.Draw();
		}


		void Piece::SetIndex(unsigned int index)
		{
			m_Row = index / COLUMN_NUM;
			m_Column = index % ROW_NUM;
		}


		int Piece::GetIndex()
		{
			int index = m_Row * COLUMN_NUM + m_Column;
			return index;
		}


		void Piece::SetColumn(unsigned int column)
		{
			m_Column = column;
		}


		void Piece::SetRow(unsigned int row)
		{
			m_Row = row;
		}


		unsigned int Piece::GetColumn()
		{
			return m_Column;
		}


		unsigned int Piece::GetRow()
		{
			return m_Row;
		}
}