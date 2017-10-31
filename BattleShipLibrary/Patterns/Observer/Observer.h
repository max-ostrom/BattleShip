#ifndef Observer_H
#define Observer_H
namespace BattleShip
{
    class Observer
    {
    public:
        virtual void update()const = 0;
        virtual ~Observer() {}
    };
}
#endif
