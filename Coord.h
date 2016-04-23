//
//  Coord.h
//  CS_Homework_2
//
//  Created by Zegao Liu on 16/4/22.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#ifndef Coord_h
#define Coord_h

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};



#endif /* Coord_h */
