#gcc -o app ./main.cpp commission_wage_worker.cpp hourly_wage_worker.cpp company.cpp vector.cpp -lstdc++ && ./main
#gcc -c ./main.cpp ./vector.cpp ./hourly_wage_worker.cpp ./commission_wage_worker.cpp ./company.cpp
#gcc -o app ./main.o commission_wage_worker.o hourly_wage_worker.o company.o vector.o
#./app
#g++ ./main.cpp commission_wage_worker.cpp hourly_wage_worker.cpp company.cpp vector.cpp -o app
#clang++ -v -std=c++11 main.cpp commission_wage_worker.cpp hourly_wage_worker.cpp company.cpp vector.cpp -o app