#include <iostream>
int main(int argc,char** argv){
  std::cout << "argc = " << argc << std::endl ;
  if(argc!=3){
    std::cerr << "Usage like ... \n ./showsol1 3.2 4" << std::endl ;
    return EXIT_FAILURE ;
  }
  for(int i=0; i< argc ;i++){
    std::cout << "argv[" << i << "]= " << argv[i] << std::endl;
  }
  std::cout << argv[1] << " + " << argv[2] << " = " << atof(argv[1]) + atof(argv[2]) << std::endl;
  return EXIT_SUCCESS ;
}
