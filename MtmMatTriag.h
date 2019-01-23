#ifndef EX3_MTMMATTRIAG_H
#define EX3_MTMMATTRIAG_H


#include <vector>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "MtmMatSq.h"

using std::size_t;

namespace MtmMath {
    template <typename T>
    class MtmMatTriag : public MtmMatSq<T> {
        bool is_upper;
    public:
        /*
         * Triangular Matrix constructor, m is the number of rows and columns in the matrix,
         * val is the initial value for the matrix elements and isUpper_ is whether it is upper
         * Rectangular matrix (true means it is)
         */
        MtmMatTriag<T> (size_t m, const T& val=T(), bool isUpper_t=true) : MtmMatSq<T>(m,0) , is_upper(isUpper_t){
            if(is_upper){
                for (size_t i = 0; i < m ; ++i) {
                    for (size_t j = i; j < m ; ++j) {
                        this->matrix[i][j] = val;
                    }
                }
            }
            else{
                for (size_t i = 0; i < m ; ++i) {
                    for (size_t j = 0; j <= i ; ++j) {
                        this->matrix[i][j] = val;
                    }
                }
            }

        }

        MtmMatTriag(const MtmMatTriag& mt) : MtmMatSq<T>(mt) , is_upper(mt.is_upper){}

        MtmMatTriag(const MtmMat<T>& ms) : MtmMatSq<T>(ms) {
            if(ms.getColumnsNum() != ms.getRowsNum()){
                throw MtmExceptions::IllegalInitialization();
            }
            bool not_upper = false, not_down = false;
            for (size_t i = 0; i < ms.getRowsNum(); ++i) {
                for (size_t j = 0; j < i ; ++j) {
                    if(this->matrix[i][j] != 0){
                        not_upper = true;
                    }
                }
            }
            for (size_t i = 0; i < ms.getRowsNum(); ++i) {
                for (size_t j = i+1 ; j < ms.getColumnsNum() ; ++j) {
                    if(this->matrix[i][j] != 0){
                        not_down = true;
                    }
                }
            }
            if(not_down && not_upper){
                throw MtmExceptions::IllegalInitialization();
            }
            if(!not_down && !not_upper){
                is_upper = true;
            } else if(!not_upper){
                is_upper = true;
            } else{
                is_upper = false;
            }
        }

        virtual void resize(Dimensions dim, const T& val=T()) {
            if(dim.getCol() != dim.getRow()){
                throw MtmExceptions::ChangeMatFail(this->r, this->c, dim.getRow(), dim.getCol());
            }

            T** new_mat = new T*[dim.getRow()] ;
            for(size_t i = 0 ; i < dim.getRow() ; i++ ) {
                new_mat[i] = new T[dim.getCol()];
            }
            for (size_t i = 0; i < dim.getRow() ; ++i) {
                for (size_t j = 0; j < dim.getCol() ; ++j) {
                    if(is_upper){
                        if(j>=i && i<this->r && j<this->c){
                            new_mat[i][j] = this->matrix[i][j];
                        }
                        else if(j>=i){
                            new_mat[i][j] = val;
                        } else {
                            new_mat[i][j] = 0;
                        }
                    } else{
                        if(j<=i && i<this->r && j<this->c){
                            new_mat[i][j] = this->matrix[i][j];
                        }
                        else if(j<=i){
                            new_mat[i][j] = val;
                        } else {
                            new_mat[i][j] = 0;
                        }
                    }
                }
            }
            for (size_t k = 0; k < this->r ; ++k) {
                delete[] this->matrix[k];
            }
            delete[] this->matrix;
            this->matrix = new_mat;
            this->r = dim.getRow();
            this->c = dim.getCol();
        }
        virtual T& getElement(const size_t i, const size_t j){
            if(is_upper){
                if(i > j){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
            }else{
                if(i < j){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
            }
            return this->matrix[i][j];
        }

        void transpose() override {
            is_upper = !is_upper;
            MtmMat<T>::transpose();
        }

        ~MtmMatTriag() = default;
    };
}

#endif //EX3_MTMMATTRIAG_H