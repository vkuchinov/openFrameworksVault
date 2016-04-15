#include "ofClassOne.h"
#include "ofClassTwo.h"

ofClassTwo::ofClassTwo(){
    
}

float ofClassTwo::calculate(ofClassOne* objectA_){
    
    objectA_->value -= 100.0;
    
}