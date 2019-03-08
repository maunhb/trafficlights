#include "pointf.h"
#include "math.h"

qreal Point::trimArgiment(qreal arg)
{
    while(arg>M_PI) arg-=2*M_PI;
    while(arg<=-M_PI) arg+=2*M_PI;
    return arg;
}

PointF::PointF() : Point()
{
    xp = yp = 0;
}

PointF::PointF( const Point &other) : Point()
{
    xp = ((QPointF)other).x();
    yp = ((QPointF)other).y();
}

PointF::PointF(qreal x, qreal y) : Point()
{
    xp = x;
    yp = y;
}

inline qreal PointF::ang() const
{
    return atan2(yp, xp);
}

inline qreal PointF::rad() const
{
    return sqrt(xp*xp+yp*yp);
}

PointF::operator PointPolar() const
{
    return *(new PointPolar(ang(),rad()));
}

PointF& PointF::rotation(qreal alpha)
{
    qreal s=sin(alpha);
    qreal c=cos(alpha);
    qreal x=xp*c-yp*s;
    yp=s*xp+yp*c;
    xp=x;
    return *this;
}

//Projection to p
PointF& PointF::projectionTo(const Point& p) const
{
    qreal k=PointF::dotProduct(p, *this);
    qreal l=p.length();
    PointF* projection;
    if(l==0) projection=new PointF(0,0);
    else projection= new PointF(p.x()*k/(l*l),p.y()*k/(l*l));
    return *projection;
}


inline PointF& PointF::operator+=(const Point& rhs)
{
    xp += ((QPointF)rhs).x();
    yp += ((QPointF)rhs).y();
    return *this;
}

const PointF& operator+(const PointF& lhs, const PointF& rhs)
{
    return *(new PointF(lhs.x()+rhs.x(), lhs.y()+rhs.y()));
}

const PointF& operator-(const PointF& lhs, const PointF& rhs)
{
    return *(new PointF(lhs.x()-rhs.x(), lhs.y()-rhs.y()));
}

const PointF& operator*(const PointF& lhs, qreal m)
{
    return *(new PointF(lhs.x()*m, lhs.y()*m));
}

const PointF& operator*(qreal m, const PointF& rhs)
{
    return *(new PointF(rhs.x()*m, rhs.y()*m));
}

const PointF& operator/(const PointF& lhs, qreal d)
{
    return *(new PointF(lhs.x()/d, lhs.y()/d));
}


PointF& PointF::operator-=(const Point& rhs)
{
    xp -= ((QPointF)rhs).x();
    yp -= ((QPointF)rhs).y();
    return *this;
}

PointF& PointF::operator*=(qreal m)
{
    xp *= m;
    yp *= m;
    return *this;
}


PointF& PointF::operator/=(qreal d)
{
    xp /= d;
    yp /= d;
    return *this;
}

/////////////////////////////////////////////////////////////
////////////////////// PointPolar: //////////////////////////
/////////////////////////////////////////////////////////////


inline qreal PointPolar::x() const
{
    return r * cos(a);
}

inline qreal PointPolar::y() const
{
    return r * sin(a);
}

PointPolar::PointPolar()
{
    a = r = 0;
}

PointPolar::PointPolar(const Point &other)
{
    a = other.ang();
    r = other.rad();
}

PointPolar::PointPolar(qreal a, qreal r)
{
    PointPolar::a = a;
    PointPolar::r = r;
}

PointPolar& PointPolar::rotation(qreal alpha)
{
    a=trimArgiment(a+alpha);
    return *this;
}

PointF& PointPolar::projectionTo(const Point& p) const
{
    PointF r(*this);
    return r.projectionTo(p);
}



inline PointPolar& PointPolar::operator+=(const Point& rhs)
{
    (*this) = (*this) + rhs;
    return *this;
}

inline PointPolar& PointPolar::operator-=(const Point& rhs)
{
    (*this) = (*this) - rhs;
    return *this;
}

inline PointPolar& PointPolar::operator*=(qreal m)
{
    (*this) = (*this) * m;
    return *this;
}

inline PointPolar& PointPolar::operator/=(qreal d)
{
    (*this) = (*this) / d;
    return *this;
}

const PointPolar& operator+(const PointPolar& lhs, const PointPolar& rhs)
{
    qreal da = rhs.ang() - lhs.ang();
    qreal nr = sqrt(lhs.rad()*lhs.rad() + rhs.rad()*rhs.rad() +
                    2 * lhs.rad() * rhs.rad() * cos(da) );
    qreal na = lhs.ang() + atan2(rhs.rad() * sin(da), lhs.rad() + rhs.rad()*cos(da));
    return *(new PointPolar(na, nr));
}

const PointPolar& operator-(const PointPolar& lhs, const PointPolar& rhs)
{
    PointPolar r2(rhs.ang() + M_PI, rhs.rad());
    return lhs + r2;
}

const PointPolar& operator*(const PointPolar& lhs, qreal m)
{
    return *(new PointPolar(lhs.ang(), lhs.rad() * m));
}

const PointPolar& operator*(qreal m, const PointPolar& rhs)
{
    return *(new PointPolar(rhs.ang(), rhs.rad() * m));
}

const PointPolar& operator/(const PointPolar& lhs, qreal d)
{
    return *(new PointPolar(lhs.ang(), lhs.rad() / d));
}

