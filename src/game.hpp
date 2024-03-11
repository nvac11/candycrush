#pragma once


class game
{
    private:
        struct data
        {
            int score;
            int remainingplay;
        };
        
    public:
        game();
        ~game();

        int getscore();
        int getnbcoup();
        void augmenterscore();
        void coupsuivant();


};