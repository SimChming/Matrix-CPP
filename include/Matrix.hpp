#ifndef MATRIX_HPP
#define MATRIX_HPP

#ifndef VECTOR_HPP
#include <vector>
#define VECTOR_HPP
#endif

#ifndef UTILITY_HPP
#include <utility>
#define UTILITY_HPP
#endif

#ifndef IOMANIP_HPP
#include <iomanip>
#define IOMANIP_HPP
#endif

#ifndef IOSTREAM_HPP
#include <iostream>
#define IOSTREAM_HPP
#endif


using Shape = std::pair<int, int>;

class Matrix{
    protected:
        Shape shape;
        std::vector<double> content;
    
    public:
        void reshape(Shape shape){
            this -> shape.first=shape.first;
            this -> shape.second=shape.second;
            content.resize(shape.first*shape.second);
        }
        void set(int r, int c, double value){
            this -> content[r*this -> shape.second+c]=value;
        }
        void initialize(double value){
            for(int i=0;i<this -> shape.first*this -> shape.second;i++){
                this -> content[i]=value;
            }
        }
        void randomize(double min, double max){
            for(int i=0;i<this -> shape.first*this -> shape.second;i++){
                this -> content[i]=min+(max-min)*((double)rand()/RAND_MAX);
            }
        }
        double get(int r, int c){
            return this -> content[r*this -> shape.second+c];
        }
        Shape getshape(){
            return this -> shape;
        }
        void print(){
            for(int i=0;i<this -> shape.first;i++){
                for(int j=0;j<this -> shape.second;j++){
                    std::cout<<std::setw(10)<<std::setiosflags(std::ios::left)<<std::setfill('0')<<this -> content[i*this -> shape.second+j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
        Matrix T(){
            Matrix B;
            B.reshape(std::make_pair(this -> getshape().second, this -> getshape().first));
            for(int i=0;i<B.getshape().first;i++){
                for(int l=0;l<B.getshape().second;l++){
                    B.set(i, l, this -> get(l, i));
                }
            }
            return B;
        }
};


Matrix operator+ (Matrix A, Matrix B){
    Matrix C;
    C.reshape(A.getshape());
    int x,y;
    if(A.getshape()!=B.getshape()){
        throw std::invalid_argument("The adding Matries aren't matching!");
    }
    for (int i=0;i<A.getshape().first*A.getshape().second;i++){
        x = i/A.getshape().second;
        y = i%A.getshape().second;
        C.set(x, y, A.get(x, y) + B.get(x, y));
    }
    return C;
}

Matrix operator* (Matrix A, Matrix B){
    if (A.getshape().second!=B.getshape().first){
        throw std::invalid_argument("The adding Matries aren't matching!");
    }
    Matrix C;
    C.reshape(std::make_pair(A.getshape().first, B.getshape().second));
    C.initialize(0);
    for (int i=0;i<C.getshape().first;i++){
        for (int l=0;l<C.getshape().second;l++){
            for (int n=0;n<A.getshape().second;n++){
                C.set(i, l, C.get(i, l) + A.get(i, n) * B.get(n, l));
            }
        }
    }
    return C;
};

#endif