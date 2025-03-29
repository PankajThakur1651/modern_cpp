C++03
1 => default constructor (generated only if no constructor is declared by user)
2 => copy constructor  (generated only if no 5 and 6 declared by user)
3=> copy assignment operator (generated only if no 5 and 6 declared by user)
4 => Destructor 

C++11
5 => Move constructor (generated only id 2,3,4,6 not declared by user)
6 => Move assignment operator (generated only id 2,3,4,5 not declared by user)