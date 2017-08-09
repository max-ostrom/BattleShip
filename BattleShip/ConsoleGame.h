#pragma once
#include "Game.h"
class ConsoleGame :
	public Game
{
public:
	ConsoleGame();
	virtual ~ConsoleGame();
	virtual void run() override;
protected:
	virtual void endOfGame(const clock_t& startGame) const  override;
	virtual void reprintField() const override;


	virtual bool isKeyPressed(const int& key) const override;

};

