#include "Game.h"

namespace GameDev2D
{
	Game::Game() :
		m_Pieces{ 0, 1, 2, 3, 4, 5, 6, 7 },
		m_Final(),
		m_OpenRow(ROW_NUM - 1),
		m_OpenColumn(COLUMN_NUM - 1),
		m_Moves(0)
	{
		std::string finalTexture = std::to_string(PIECE_NUM);
		LoadTexture(finalTexture);
		m_Final.SetTexture(finalTexture);
		m_Final.SetPosition(GetScreenWidth() - PIECE_SIZE, 0);
	}

	void Game::Update(double delta)
	{
		for (int i = 0; i < PIECE_NUM; i++)
		{
			m_Pieces[i].Update(delta);
		}
	}

	void Game::Draw()
	{
		for (int i = 0; i < PIECE_NUM; i++)
		{
			m_Pieces[i].Draw();
		}

		if (Won())
		{
			m_Final.Draw();
		}
	}

	Piece* Game::GetPiece(unsigned int row, unsigned int column)
	{
		for (int i = 0; i < PIECE_NUM; i++)
		{
			if (m_Pieces[i].GetRow() == row && m_Pieces[i].GetColumn() == column)
			{
				return &m_Pieces[i];
			}
		}
		return nullptr;
	}

	bool Game::IsValid(int row, int column)
	{
		return (row >= 0 && row < ROW_NUM && column >= 0 && column < COLUMN_NUM);
	}

	bool Game::Won()
	{
		bool win = false;
		unsigned int correct = 0;

		for (int i = 0; i < PIECE_NUM; i++)
		{
			if (m_Pieces[i].GetIndex() == i)
			{
				correct++;
			}
		}

		if (correct == PIECE_NUM && m_Moves > 0)
		{
			win = true;
		}

		return win;
	}

	void Game::HandleLeftMouseClick(float mouseX, float mouseY)
	{
	
	}

	void Game::HandleRightMouseClick(float mouseX, float mouseY)
	{

	}

	void Game::HandleMouseMove(float mouseX, float mouseY, float previousX, float previousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key key)
	{
		if (key == Keyboard::S)
		{
			m_Moves = 0;

			for (int i = 0; i < PIECE_NUM; i++)
			{
				//Gets two random indices
				int indexA = Math::RandomInt(0, PIECE_NUM - 1);
				int indexB = Math::RandomInt(0, PIECE_NUM - 1);

				//Swaps the pieces
				int cardIndexA = m_Pieces[indexA].GetIndex();
				m_Pieces[indexA].SetIndex(m_Pieces[indexB].GetIndex());
				m_Pieces[indexB].SetIndex(cardIndexA);
			}
		}

		if (key == Keyboard::Left)
		{
			if (!Won())
			{
				if (IsValid(m_OpenRow, m_OpenColumn - 1) == true)
				{
					Piece* p = GetPiece(m_OpenRow, m_OpenColumn - 1);
					p->SetColumn(m_OpenColumn);
					m_OpenColumn--;
					m_Moves++;
				}
			}
		}

		if (key == Keyboard::Right)
		{
			if (!Won())
			{
				if (IsValid(m_OpenRow, m_OpenColumn + 1) == true)
				{
					Piece* p = GetPiece(m_OpenRow, m_OpenColumn + 1);
					p->SetColumn(m_OpenColumn);
					m_OpenColumn++;
					m_Moves++;
				}
			}
		}

		if (key == Keyboard::Up)
		{
			if (!Won())
			{
				if (IsValid(m_OpenRow - 1, m_OpenColumn) == true)
				{
					Piece* p = GetPiece(m_OpenRow - 1, m_OpenColumn);
					p->SetRow(m_OpenRow);
					m_OpenRow--;
					m_Moves++;
				}
			}
		}

		if (key == Keyboard::Down)
		{
			if (!Won())
			{
				if (IsValid(m_OpenRow + 1, m_OpenColumn) == true)
				{
					Piece* p = GetPiece(m_OpenRow + 1, m_OpenColumn);
					p->SetRow(m_OpenRow);
					m_OpenRow++;
					m_Moves++;
				}
			}
		}

		if (key == Keyboard::R)
		{
			m_Moves = 0;

			for (int i = 0; i < PIECE_NUM; i++)
			{
				m_Pieces[i].SetIndex(i);
			}

			m_OpenRow = ROW_NUM - 1;
			m_OpenColumn = COLUMN_NUM - 1;
		}
	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}
}