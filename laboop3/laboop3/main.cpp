//
//  main.cpp
//  laboop3
//
//  Created by Nikita Makeev on 10/5/20.
//

#include <time.h>
#include <iostream>
#include <sys/time.h>
using namespace std;

class Coordinates{
    private:
        int m_x,m_y,m_z;
    public:
    
    Coordinates(){};
    Coordinates(const int x,const int y,const int z): m_x(x), m_y(y), m_z(z){}
    void show( void );
    
    Coordinates operator+(Coordinates other){
        Coordinates temp;
        temp.m_x = m_x+other.m_x;
        temp.m_y = m_y+other.m_y;
        temp.m_z = m_z+other.m_z;

        return temp;
    }
    Coordinates operator +(int value){
    Coordinates temp = *this;

    temp.m_x = temp.m_x + value;
    temp.m_y = temp.m_y + value;
    temp.m_z = temp.m_z + value;

    return temp;
    }
    const Coordinates operator-(Coordinates other){
        Coordinates temp;
        temp.m_x  = m_x -other.m_x ;
        temp.m_y = m_y-other.m_y;
        temp.m_z = m_z-other.m_z;

        return temp;
    }
    Coordinates operator -(int value){
    Coordinates temp = *this;

    temp.m_x = temp.m_x - value;
    temp.m_y = temp.m_y - value;
    temp.m_z = temp.m_z - value;

    return temp;
    }
    const Coordinates& operator=(const Coordinates& other){
        
        if(this != &other)this->m_x = other.m_x;
        if(this != &other)this->m_y = other.m_y;
        if(this != &other)this->m_z = other.m_z;
        return *this;
    }
    friend bool operator ==(const Coordinates &left, const Coordinates &rigt);
    friend bool operator !=(const Coordinates &first, const Coordinates &other);
    friend Coordinates operator+=(Coordinates& left, const Coordinates& right);
    friend Coordinates operator-=(Coordinates& left, const Coordinates& right);
};

    void Coordinates::show( void ){
        
    cout << m_x << ",";
    cout << m_y << ",";
    cout << m_z << "\n";
}

    bool operator == (const Coordinates &left, const Coordinates &rigt){
    
        return (left.m_x == rigt.m_x &&
                left.m_y == rigt.m_y &&
                left.m_z == rigt.m_z);
    }
 
    bool operator != (const Coordinates &first, const Coordinates &other){
        return !(first == other);
    }

    Coordinates operator += (Coordinates& left, const Coordinates& right) {
        
        left.m_x += right.m_x;
        left.m_y += right.m_y;
        left.m_z += right.m_z;
        
        return left;
    }
    Coordinates operator -= (Coordinates& left, const Coordinates& right) {
        
        left.m_x -= right.m_x;
        left.m_y -= right.m_y;
        left.m_z -= right.m_z;
        
        return left;
    }
    int main(){
        Coordinates a(4,2,6), a1(2,4,8), c(0,0,0);
        a.show();
        a1.show();
        c = a+a1;
        c.show();
        a.show();
        a1.show();
        c -= a1;
        c.show();
        c += a;
        c.show();
        c += a1;
        c.show();
        a = c;
        a.show();
        a = a + 1;
        a.show();
        (a1!=c)?cout<<"coordinates are not equal \n":cout<<"coordinates are equal \n";
        a = c;
        (a!=c)?cout<<"coordinates are not equal \n":cout<<"coordinates are equal \n";
    return 0;
}

