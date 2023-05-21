#ifndef POINT_HPP
#define POINT_HPP



namespace ariel{

class Point {
    public:
        Point(double dotx, double doty);
        virtual ~Point(){};
        double getX() const;
        double getY() const;
        double setX(double dotx) {return this->_dotx=dotx;}
        double setY(double doty){return this->_doty=doty;}
        double distance(const Point& other)const;
        static Point moveTowards(const Point& source, const Point& target, double distance);
        void print();

    private:
        double _dotx;
        double _doty;
    };

}
#endif