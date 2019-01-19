#ifndef EX3_MTMEXCEPTIONS_H
#define EX3_MTMEXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>
#include <cstring>
#include "Auxilaries.h"

using namespace std;

namespace MtmMath {
    namespace MtmExceptions {
        class MtmExceptions : public std::exception {
        public:
            virtual ~MtmExceptions() throw() {}
        };

        /*
         * Exception for illegal initialization of an object, needs to output
         * "MtmError: Illegal initialization values" in what() class function
         */
        class IllegalInitialization : public MtmExceptions {
        public:
            IllegalInitialization(){}
            virtual const char* what() const throw(){
                return "MtmError: Illegal initialization values";
            }

        };

        /*
         * Exception for Memory allocation failure for an object, needs to output
         * "MtmError: Out of memory" in what() class function
         */
        class OutOfMemory : public MtmExceptions {
        public:
            OutOfMemory(){}
            virtual const char* what() const throw(){
                return "MtmError: Out of memory";
            }
        };

        /*
         * Exception for dimension mismatch during a mathematical function, needs to output
         * "MtmError: Dimension mismatch: (<mat 1 row>,<mat 1 col>) (<mat 2 row>,<mat 2 col>)"
         * in what() class function
         */
        class DimensionMismatch : public MtmExceptions {
            int r_1,c_1,r_2,c_2;
            char* str;
        public:
            DimensionMismatch(int r1, int c1, int r2, int c2) : r_1(r1), r_2(r2), c_1(c1), c_2(c2){
                std::string tmp = "MtmError: Dimension mismatch: (" ;
                tmp = tmp + std::to_string(r_1) + "," + std::to_string(c_1) + ") (";
                tmp += to_string(r_2) + "," + to_string(c_2) + ")";
                const char* str2 = tmp.c_str();
                this->str = new char[tmp.size()+1];
                strcpy(str,str2);
            }
            virtual const char* what() const throw() {
                return str;
            }
            ~DimensionMismatch(){
                delete[](str);
            }

        };

        /*
         * Exception for error for changing matrix/vector shape in reshape and resize, needs to output
         * "MtmError: Change matrix shape failed from: (<mat row>,<mat col>) (<new mat row>,<new mat col>)"
         * in what() class function
         */
        class ChangeMatFail : public MtmExceptions {
            int r_1,c_1,r_2,c_2;
            char* str;
        public:
            ChangeMatFail(int r, int c, int attemped_R, int attemped_C):r_1(r),c_1(c),r_2(attemped_R),c_2(attemped_C){
                string tmp = "MtmError: Change matrix shape failed from ("  + to_string(r_1) + "," + to_string(c_1);
                tmp +=  ") to (";
                tmp += to_string(r_2) + "," + to_string(c_2) + ")";
                const char* str2 = tmp.c_str();
                this->str = new char[tmp.size()+1];
                strcpy(str,str2);
            }
            virtual const char* what() const throw() {
                return str;
            }
            ~ChangeMatFail(){
                delete[](str);
            }
        };

        /*
         * Exception for accessing an illegal element in matrix or vector, needs to output
         * "MtmError: Attempt access to illegal element" in what() class function
         */
        class AccessIllegalElement : public MtmExceptions {
        public:
            AccessIllegalElement(){}
            virtual const char* what() const throw(){
                return "MtmError: Attempt access to illegal element" ;
            }
        };
    }
}


#endif //EX3_MTMEXCEPTIONS_H
