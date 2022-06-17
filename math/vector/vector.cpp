#include<iostream>
#include"vector.h"
#include<cmath>

using namespace _vector;

vector::vector(){
    data_3d = new three_demension_vector;
    data_2d = nullptr;

    this->data_3d->x = 0;
    this->data_3d->y = 0;
    this->data_3d->z = 0;
}

vector::vector(vector_type type){
    if(type == three_demension){
        data_3d = new three_demension_vector;
        data_2d = nullptr;

        this->data_3d->x = 0;
        this->data_3d->y = 0;
        this->data_3d->z = 0;
    }else if(type == two_demension){
        data_3d = nullptr;
        data_2d = new two_demension_vector;

        this->data_2d->x = 0;
        this->data_2d->y = 0;
    }else{
        data_3d = nullptr;
        data_2d = nullptr;
    }
}

vector::vector(const vector &a){
    if(a.data_2d){
        data_2d = new two_demension_vector;
        data_2d->x = a.data_2d->x;
        data_2d->y = a.data_2d->y;
        data_3d = nullptr;
    }else if(a.data_3d){
        data_3d = new three_demension_vector;
        data_3d->x = a.data_3d->x;
        data_3d->y = a.data_3d->y;
        data_3d->z = a.data_3d->z;
        data_2d = nullptr;
    } else {
        data_3d = nullptr;
        data_2d = nullptr;
    }
}

vector::vector(double x, double y, double z){
    data_3d = new three_demension_vector;
    data_2d = nullptr;

    this->data_3d->x = x;
    this->data_3d->y = y;
    this->data_3d->z = z;
}

vector::vector(double x, double y){
    data_2d = new two_demension_vector;
    data_3d = nullptr;

    this->data_2d->x = x;
    this->data_2d->y = y;
}

vector::vector(const two_demension_vector &a){
    data_2d = new two_demension_vector;
    data_3d = nullptr;

    this->data_2d->x = a.x;
    this->data_2d->y = a.y;
}

vector::vector(const three_demension_vector &a){
    data_3d = new three_demension_vector;
    data_2d = nullptr;

    this->data_3d->x = a.x;
    this->data_3d->y = a.y;
    this->data_3d->z = a.z;
}

vector::~vector(){
    if(data_3d){
        delete data_3d;
    }
    if(data_2d){
        delete data_2d;
    }
}

vector vector::operator+(const vector &a){
    vector result;
    if(this->data_2d && a.data_2d){
        result.data_2d = new two_demension_vector;
        result.data_2d->x = this->data_2d->x + a.data_2d->x;
        result.data_2d->y = this->data_2d->y + a.data_2d->y;
        result.data_3d = nullptr;
    }else if(this->data_3d && a.data_3d){
        result.data_3d = new three_demension_vector;
        result.data_3d->x = this->data_3d->x + a.data_3d->x;
        result.data_3d->y = this->data_3d->y + a.data_3d->y;
        result.data_3d->z = this->data_3d->z + a.data_3d->z;
        result.data_2d = nullptr;
    }else{
        result.data_3d = nullptr;
        result.data_2d = nullptr;
    }
    return result;
}

double vector::operator*(const vector &a){
    double result = 0;
    if(this->data_2d && a.data_2d){
        result = this->data_2d->x * a.data_2d->x + this->data_2d->y * a.data_2d->y;
    }else if(this->data_3d && a.data_3d){
        result = this->data_3d->x * a.data_3d->x + this->data_3d->y * a.data_3d->y + this->data_3d->z * a.data_3d->z;
    }
    return result;
}

vector vector::operator*(const double &a){
    vector result;
    if(this->data_2d){
        result.data_2d = new two_demension_vector;
        result.data_2d->x = this->data_2d->x * a;
        result.data_2d->y = this->data_2d->y * a;
        result.data_3d = nullptr;
    }else if(this->data_3d){
        result.data_3d = new three_demension_vector;
        result.data_3d->x = this->data_3d->x * a;
        result.data_3d->y = this->data_3d->y * a;
        result.data_3d->z = this->data_3d->z * a;
        result.data_2d = nullptr;
    }else{
        result.data_3d = nullptr;
        result.data_2d = nullptr;
    }
    return result;
}

vector vector::operator-(const vector &a){
    vector result;
    if(this->data_2d && a.data_2d){
        result.data_2d = new two_demension_vector;
        result.data_2d->x = this->data_2d->x - a.data_2d->x;
        result.data_2d->y = this->data_2d->y - a.data_2d->y;
        result.data_3d = nullptr;
    }else if(this->data_3d && a.data_3d){
        result.data_3d = new three_demension_vector;
        result.data_3d->x = this->data_3d->x - a.data_3d->x;
        result.data_3d->y = this->data_3d->y - a.data_3d->y;
        result.data_3d->z = this->data_3d->z - a.data_3d->z;
        result.data_2d = nullptr;
    }else{
        result.data_3d = nullptr;
        result.data_2d = nullptr;
    }
    return result;
}

vector vector::operator=(const vector &a){
    if(this->data_2d){
        delete this->data_2d;
    }
    if(this->data_3d){
        delete this->data_3d;
    }
    if(a.data_2d){
        this->data_2d = new two_demension_vector;
        this->data_2d->x = a.data_2d->x;
        this->data_2d->y = a.data_2d->y;
        this->data_3d = nullptr;
    }else if(a.data_3d){
        this->data_3d = new three_demension_vector;
        this->data_3d->x = a.data_3d->x;
        this->data_3d->y = a.data_3d->y;
        this->data_3d->z = a.data_3d->z;
        this->data_2d = nullptr;
    } else {
        this->data_3d = nullptr;
        this->data_2d = nullptr;
    }
    return *this;
}

vector vector::operator^(const vector &a){
    vector result;
    if(this->data_2d && a.data_2d){
        return vector(two_demension);
    }else if(this->data_3d && a.data_3d){
        result.data_3d = new three_demension_vector;
        result.data_3d->x = this->data_3d->y * a.data_3d->z - this->data_3d->z * a.data_3d->y;
        result.data_3d->y = this->data_3d->z * a.data_3d->x - this->data_3d->x * a.data_3d->z;
        result.data_3d->z = this->data_3d->x * a.data_3d->y - this->data_3d->y * a.data_3d->x;
        result.data_2d = nullptr;
    }else{
        result.data_3d = nullptr;
        result.data_2d = nullptr;
    }
    return result;
}

double vector::length(){
    double result = 0;
    if(this->data_2d){
        result = sqrt(this->data_2d->x * this->data_2d->x + this->data_2d->y * this->data_2d->y);
    }else if(this->data_3d){
        result = sqrt(this->data_3d->x * this->data_3d->x + this->data_3d->y * this->data_3d->y + this->data_3d->z * this->data_3d->z);
    }
    return result;
}

double vector::cos(vector &a){
    double result = 0;
    if(this->data_2d && a.data_2d){
        result = (this->data_2d->x * a.data_2d->x + this->data_2d->y * a.data_2d->y) / (this->length() * a.length());
    }else if(this->data_3d && a.data_3d){
        result = (this->data_3d->x * a.data_3d->x + this->data_3d->y * a.data_3d->y + this->data_3d->z * a.data_3d->z) / (this->length() * a.length());
    }
    return result;
}

double vector::sin(vector &a){
    double result = this->cos(a);
    result = sqrt(1 - result * result);
    return result;
}

double vector::angle(vector &a){
    double result = 0;
    if(this->data_2d && a.data_2d){
        result = acos((this->data_2d->x * a.data_2d->x + this->data_2d->y * a.data_2d->y) / (this->length() * a.length()));
    }else if(this->data_3d && a.data_3d){
        result = acos((this->data_3d->x * a.data_3d->x + this->data_3d->y * a.data_3d->y + this->data_3d->z * a.data_3d->z) / (this->length() * a.length()));
    }
    result *= 180 / PI;
    return result;
}

double vector::radius(vector &a){
    double result = 0;
    if(this->data_2d && a.data_2d){
        result = acos((this->data_2d->x * a.data_2d->x + this->data_2d->y * a.data_2d->y) / (this->length() * a.length()));
    }else if(this->data_3d && a.data_3d){
        result = acos((this->data_3d->x * a.data_3d->x + this->data_3d->y * a.data_3d->y + this->data_3d->z * a.data_3d->z) / (this->length() * a.length()));
    }
    return result;
}

double vector::tan(vector &a){
    double result = 0;
    result = this->sin(a) / this->cos(a);
    return result;
}
