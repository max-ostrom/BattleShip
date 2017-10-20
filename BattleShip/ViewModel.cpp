#include "ViewModel.h"

ViewModel::ViewModel()
{
    for (int i = 0; i < STANDART_FIELD; i++)
    {
        for (int j = 0; j < STANDART_FIELD; j++)
        {
            userField_[i][j] = ' ';
            computerField_[i][j] = ' ';
        }
    }
}

ViewModel::~ViewModel()
{
}

void ViewModel::setUserField
(const int i_index, const int j_index, const char symb)
{
    userField_[i_index][j_index] = symb;
}

void ViewModel::setComputerField
(const int i_index, const int j_index, const char symb)
{
    computerField_[i_index][j_index] = symb;
}

char ViewModel::getUserField
(const int i_index, const int j_index) const
{
    return userField_[i_index][j_index];
}

char ViewModel::getcomputerField
(const int i_index, const int j_index) const
{
    return computerField_[i_index][j_index];
}
