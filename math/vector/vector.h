#include<iostream>

namespace _vector{

    const double PI = 3.14159265358979323846;

    enum vector_type{
        two_demension,
        three_demension
    };

    typedef struct three_demension_vector{
        double x;
        double y;
        double z;
    }three_demension_vector;

    typedef struct two_demension_vector{
        double x;
        double y;
    }two_demension_vector;

    class vector{
        public:
            vector();
            vector(vector_type);
            vector(const vector &);
            vector(double x, double y, double z);
            vector(double x, double y);
            vector(const two_demension_vector &);
            vector(const three_demension_vector &);
            ~vector();

            vector operator+(const vector &a);
            vector operator-(const vector &a);
            vector operator*(const double &a);
            vector operator=(const vector &a);
            double operator*(const vector &a);
            vector operator^(const vector &a);

            double length();
            double angle( vector &a);
            double radius( vector &a);
            double cos(vector &a);
            double sin(vector &a);
            double tan(vector &a);

            friend std::ostream & operator<<(std::ostream &os,const vector &a){
                if(a.data_2d){
                    os<<"("<<a.data_2d->x<<","<<a.data_2d->y<<")\n";
                }else if(a.data_3d){
                    os<<"("<<a.data_3d->x<<","<<a.data_3d->y<<","<<a.data_3d->z<<")\n";
                }else{
                    os<<"Empty\n";
                }
                return os;
            }

        private:
            three_demension_vector *data_3d;
            two_demension_vector *data_2d;
    };
    
}