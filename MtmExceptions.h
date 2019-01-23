#ifndef EX3_MTMEXCEPTIONS_H
#define EX3_MTMEXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>
#include <cstring>
#include "Auxilaries.h"

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
            size_t r_1,c_1,r_2,c_2;
            char* str;
        public:
            DimensionMismatch(size_t r1, size_t c1, size_t r2, size_t c2) : r_1(r1), c_1(c1), r_2(r2), c_2(c2){
                std::string tmp = "MtmError: Dimension mismatch: " ;
                Dimensions d1(r1,c1);
                Dimensions d2(r2,c2);
                tmp += d1.to_string();
				tmp += " ";
                tmp += d2.to_string();
                const char* str2 = tmp.c_str();
                this->str = new char[tmp.size()+1];
                strcpy(str,str2);
            }
            virtual const char* what() const throw() {
                return str;
            }
            ~DimensionMismatch() throw() {
                delete[](str);
            }

        };

        /*
         * Exception for error for changing matrix/vector shape in reshape and resize, needs to output
         * "MtmError: Change matrix shape failed from: (<mat row>,<mat col>) (<new mat row>,<new mat col>)"
         * in what() class function
         */
        class ChangeMatFail : public MtmExceptions {
            size_t r_1,c_1,r_2,c_2;
            char* str;
        public:
            ChangeMatFail(size_t r, size_t c, size_t attemped_R, size_t attemped_C):r_1(r),c_1(c),r_2(attemped_R),c_2(attemped_C){
                std::string tmp = "MtmError: Change matrix shape failed from ";
                Dimensions d1(r,c);
                Dimensions d2(attemped_R,attemped_C);
                tmp += d1.to_string();
				tmp += " to ";
                tmp += d2.to_string();
                const char* str2 = tmp.c_str();
                this->str = new char[tmp.size()+1];
                strcpy(str,str2);
            }
            virtual const char* what() const throw() {
                return str;
            }
            ~ChangeMatFail() throw() {
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
