//
// Created by Freddy on 21/11/2020.
//

#ifndef RESERVATIONDEVOLS_VOL_H
#define RESERVATIONDEVOLS_VOL_H


class Vol {
public:
    Vol();
    Vol(int numero, int nombrePlacesMaximal, int prix);

private:
    int numero{};
    int nombrePlacesMaximal{};
    int prix{};
};


#endif //RESERVATIONDEVOLS_VOL_H
