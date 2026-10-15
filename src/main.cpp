#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <utility>
#include "Matrix.hpp"

using namespace std;

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