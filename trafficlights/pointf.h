#ifndef POINTF_H
#define POINTF_H

#include <qmath.h>
#include <QPointF>

class PointPolar;

class Point
{
public:
    Point(){

    }
    virtual Point& operator+=(const Point& rhs) = 0;
    virtual Point& operator-=(const Point& rhs) = 0;
    virtual Point& operator*=(qreal m) = 0;
    virtual Point& operator/=(qreal d) = 0;
    virtual operator QPointF() const  = 0;
    virtual Point& rotation(qreal alpha) =0;
    virtual Point& projectionTo(const Point& p) const =0;
    static inline qreal dotProduct(const Point& lhs, const Point& rhs)
    { return lhs.x() * rhs.x() + lhs.y() * rhs.y(); }
    static inline qreal vectorProduct(const Point& lhs, const Point& rhs)
    { return lhs.x() * rhs.y() - lhs.y() * rhs.x(); }
    static qreal trimArgiment(qreal arg);
    static inline qreal angle(const Point& p,const Point& q) {return trimArgiment(q.ang()-p.ang());}

//protected:
    virtual qreal x() const = 0;
    virtual qreal y() const = 0;
    virtual qreal ang() const = 0;
    virtual qreal rad() const = 0;
    virtual qreal length() const = 0;

};

class PointF : public Point
{
    qreal xp, yp;
public:
    PointF();
    qreal ang() const;
    qreal rad() const;
    PointF(const Point &other);
    PointF(qreal x, qreal y);
    PointF& rotation(qreal alpha);
    PointF& projectionTo(const Point& p) const;
    PointF& operator+=(const Point& rhs);
    PointF& operator-=(const Point& rhs);
    PointF& operator*=(qreal m);
    PointF& operator/=(qreal d);

    inline qreal x() const {return xp;}
    inline qreal y() const {return yp;}
    void setX(qreal xv) {xp = xv;}
    void setY(qreal yv) {yp = yv;}

    inline qreal length() const { return sqrt(xp * xp + yp * yp); }

    operator QPointF() const { return QPointF(x(),y()); }
    operator PointPolar() const;
};

const PointF& operator+(const PointF& lhs, const PointF& rhs);
const PointF& operator-(const PointF& lhs, const PointF& rhs);
const PointF& operator*(const PointF& lhs, qreal m);
const PointF& operator*(qreal m, const PointF& rhs);
const PointF& operator/(const PointF& lhs, qreal d);

class PointPolar : public Point
{
    qreal a, r;
public:
    PointPolar();
    PointPolar(const Point &other);
    PointPolar(qreal a, qreal r);
    qreal x() const;
    qreal y() const;
    PointPolar& rotation(qreal alpha);
    PointF& projectionTo(const Point& p) const;
    PointPolar& operator+=(const Point& rhs);
    PointPolar& operator-=(const Point& rhs);
    PointPolar& operator*=(qreal m);
    PointPolar& operator/=(qreal d);

    inline qreal ang() const {return a;}
    inline qreal rad() const {return r;}

    void setAng(qreal av) {a = av;}
    void setRad(qreal rv) {r = rv;}

    inline qreal length() const { return r; }

    operator QPointF() const { return QPointF(x(),y()); }
    operator PointF() const { return PointF(x(),y()); }
};

const PointPolar& operator+(const PointPolar& lhs, const PointPolar& rhs);
const PointPolar& operator-(const PointPolar& lhs, const PointPolar& rhs);
const PointPolar& operator*(const PointPolar& lhs, qreal m);
const PointPolar& operator*(qreal m, const PointPolar& rhs);
const PointPolar& operator/(const PointPolar& lhs, qreal d);

#endif // POINTF_H
