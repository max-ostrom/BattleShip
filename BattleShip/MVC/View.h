#ifndef View_H
#define View_H

#include <memory>

#include "../../BattleShipLibrary/Patterns/Observer/Observable.h"
#include "../../BattleShipLibrary/Model/GameModel.h"
#include "ViewModel.h"
namespace BattleShip
{
    class View final :
        public Observer, public BattleShip::ITime
    {
    public:
        View(const IViewModel& game);
        void update() const override;
        void setStartTime(clock_t start) override;
        const clock_t& getStartTime() const override;
    private:
        const IViewModel& Model_;
        clock_t startGame_;
    };
}
#endif
