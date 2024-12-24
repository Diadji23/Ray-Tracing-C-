


Material(){
    color = ( 0.0f , 0.0f , 0.0f ) // initialiser au noir 
    shininess = 0 ; 
}


Material( const Vector3f color , float shininess){
    color_ = color ; 
    shininess_ = shininess ; 
}

~Material() ; 

//methodes 
        