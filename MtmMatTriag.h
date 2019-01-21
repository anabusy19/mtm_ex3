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
         bool pubGetIsUpper() const {
             return is_upper;
         }
        /*
         * Triangular Matrix constructor, m is the number of rows and columns in the matrix,
         * val is the initial value for the matrix elements and isUpper_ is whether it is upper
         * Rectangular matrix (true means it is)
         */
        MtmMatTriag<T> (size_t m, const T& val=T(), bool isUpper_t=true) : MtmMatSq<T>(m,0) , is_upper(isUpper_t){
            if(is_upper){
                for (int i = 0; i < m ; ++i) {
                    for (int j = i; j < m ; ++j) {
                        this->matrix[i][j] = val;
                    }
                }
            }
            else{
                for (int i = 0; i < m ; ++i) {
                    for (int j = 0; j <= i ; ++j) {
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
            for (int i = 0; i < ms.getRowsNum(); ++i) {
                for (int j = 0; j < i ; ++j) {
                    if(this->matrix[i][j] != 0){
                        not_upper = true;
                    }
                }
            }
            for (int i = 0; i < ms.getRowsNum(); ++i) {
                for (int j = i+1 ; j < ms.getColumnsNum() ; ++j) {
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

        // do I need to add operator= ?
        virtual void resize(Dimensions dim, const T& val=T()) {
            if(dim.getCol() != dim.getRow()){
                throw MtmExceptions::ChangeMatFail(this->r, this->c, dim.getRow(), dim.getCol());
            }

            T** new_mat = new T*[dim.getRow()] ;
            for( int i = 0 ; i < dim.getRow() ; i++ ) {
                new_mat[i] = new T[dim.getCol()];
            }
            for (int i = 0; i < dim.getRow() ; ++i) {
                for (int j = 0; j < dim.getCol() ; ++j) {
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
            for (int k = 0; k < this->r ; ++k) {
                delete[] this->matrix[k];
            }
            delete[] this->matrix;
            this->matrix = new_mat;
            this->r = dim.getRow();
            this->c = dim.getCol();
            return;
        }
        virtual T& getElement(const int i, const int j){
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
            if(is_upper){
                is_upper = false;
            } else{
                is_upper = true;
            }
            MtmMat<T>::transpose();
        }

        ~MtmMatTriag() = default;
    };
//    template <typename T>
//    MtmMat<T> operator+(const MtmMatTriag<T>& m, const T& n) {
//        return MtmMat<T>(m) += MtmMat<T>(Dimensions(m.getRowsNum(),m.getColumnsNum()),n);
//    }
//
//    template <typename T>
//    MtmMat<T> operator+(const T& n, const MtmMatTriag<T>& m) { // why it doesn't identify the up one?
//        return MtmMat<T>(m) += MtmMat<T>(Dimensions(m.getRowsNum(),m.getColumnsNum()),n);
//    }

}

#endif //EX3_MTMMATTRIAG_H