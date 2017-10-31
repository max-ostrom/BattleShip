#ifndef Controller_H
#define Controller_H

#include "../../BattleShipLibrary/Model/GameModel.h"
#include "IController.h"
#include "IViewModel.h"
namespace BattleShip
{
    class Controller final :
        public IController
    {
    public:
        // main game loop
        void run() override;
        explicit Controller(BattleShip::IGame& gameModel, shared_ptr<IViewModel> viewModel);
    private:
        //here user input coords 
        void userAtack();
        void computerAtack();
        void input() override;
        bool isKeyPressed(const int& key) const;

        shared_ptr<IViewModel> viewModel_;

        BattleShip::IGame& Model_;
        vector<int> coordAtack = { 0,0 };
        bool turn = true;
    };
}
#endif
