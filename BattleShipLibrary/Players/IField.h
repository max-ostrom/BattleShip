#ifndef IField_H
#define IField_H
namespace BattleShip
{
    class IField
    {
    public:
        virtual char getField(const int i, const int j) const = 0;
        virtual char getEnemyField(const int i, const int j) const = 0;
        virtual void setField(const int i, const int j) = 0;
        virtual void setEnemyField(const int i, const  int j, IField* p) = 0;
        virtual ~IField() {}
    };
}
#endif
