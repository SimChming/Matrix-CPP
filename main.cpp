#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <utility>

using namespace std;

using Shape = pair<int, int>;

class Matrix{
    protected:
        Shape shape;
        vector<double> content;
    
    public:
        void reshape( Shape shape){
            this -> shape.first=shape.first;
            this -> shape.second=shape.second;
            content.resize(shape.first*shape.second);
        }
        void set( int r,  int c,  double value){
            this -> content[r*this -> shape.second+c]=value;
        }
        void initialize( double value){
            for(int i=0;i<this -> shape.first*this -> shape.second;i++){
                this -> content[i]=value;
            }
        }
        void randomize( double min,  double max){
            for(int i=0;i<this -> shape.first*this -> shape.second;i++){
                this -> content[i]=min+(max-min)*((double)rand()/RAND_MAX);
            }
        }
        double get( int r,  int c){
            return this -> content[r*this -> shape.second+c];
        }
        Shape getshape(){
            return this -> shape;
        }
        void print(){
            for(int i=0;i<this -> shape.first;i++){
                for(int j=0;j<this -> shape.second;j++){
                    cout<<setw(10)<<setiosflags(ios::left)<<setfill('0')<<this -> content[i*this -> shape.second+j]<<" ";
                }
                cout<<endl;
            }
        }
        Matrix T(){
            Matrix B;
            B.reshape(make_pair(this -> getshape().second, this -> getshape().first));
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
        throw invalid_argument("The adding Matries aren't matching!");
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
        throw invalid_argument("The adding Matries aren't matching!");
    }
    Matrix C;
    C.reshape(make_pair(A.getshape().first, B.getshape().second));
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



class Network{
    protected:
        vector<Matrix> weights;
        vector<Matrix> biases;
        vector<Matrix> activations;
        vector<Matrix> z_values;
        vector<Matrix> deltas;
        vector<Matrix> nabla_w;
        vector<Matrix> nabla_b;
        Matrix input;
        Matrix output;
        double learning_rate;
        int hidden_layers_num;
    public:
        void initialize(const int input_size, const int output_size,  const int hidden_layers_num, const int *hidden_layer_size, const double learning_rate){
            this -> hidden_layers_num=hidden_layers_num;
            this -> learning_rate=learning_rate;
            input.reshape(make_pair(input_size,1));
            output.reshape(make_pair(output_size,1));
            for(int i=0;i<hidden_layers_num+1;i++){
                weights.push_back(Matrix());
                biases.push_back(Matrix());
                if(!i){
                    weights[i].reshape(make_pair(input_size, hidden_layer_size[i]));
                    biases[i].reshape(make_pair(1, hidden_layer_size[i]));
                }
                else if(i==hidden_layers_num){
                    weights[i].reshape(make_pair(hidden_layer_size[i], output_size));
                    biases[i].reshape(make_pair(1, output_size));
                }
                else{
                    weights[i].reshape(make_pair(hidden_layer_size[i], hidden_layer_size[i+1]));
                    biases[i].reshape(make_pair(1, hidden_layer_size[i]));
                }
                weights[i].randomize(-1, 1);
                biases[i].randomize(-1, 1);
            }
        }
        void forward_spread(Matrix inputs){
            for (int i=0;i<hidden_layers_num+1;i++){
                
            }
        }
};

int main(){

    return 0;
}