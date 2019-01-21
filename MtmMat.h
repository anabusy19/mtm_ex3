#ifndef EX3_MTMMAT_H
#define EX3_MTMMAT_H


#include <vector>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "MtmVec.h"

using std::size_t;

namespace MtmMath {

    template <typename T>
    class MtmMat {
    protected:
        T** matrix;
        int r,c;
    public:
        int getRowsNum() const {
            return r;
        }

        int getColumnsNum() const {
            return c;
        }

        int Rows(){
            return r;
        }
        int Columns(){
            return c;
        }

        bool dimTest(size_t row, size_t column) const {
            if (row == r && column == c) {
                return true;
            } else {
                return false;
            }
        }

        bool dataTest(std::vector<T> test_arr) const {
            size_t row = r;
            size_t column = c;
            if (test_arr.size() != row * column) {
                return false;
            }
            size_t index = 0;
            for (size_t i = 0; i < column; i++) {
                for (size_t j = 0; j < row; j++) {
                    if (matrix[j][i] != test_arr[index]) {
                        return false;
                    }
                    index++;
                }
            }
            return true;
        }

        void printData() const {
             size_t row = r;
             size_t column = c;
             for (size_t i = 0; i < row; i++) {
                 for (size_t j = 0; j < column; j++) {
//                     std::cout << matrix[i][j] ;
                 }
                 std::cout << std::endl;
             }
             std::cout << std::endl;
             return;
         }
        /*
         * Matrix constructor, dim_t is the dimension of the matrix and val is the initial value for the matrix elements
         */
        explicit MtmMat(Dimensions dim_t, const T& val=T()) : r(dim_t.getRow()), c(dim_t.getCol()){
            if(dim_t.getRow() <= 0 || dim_t.getCol() <=0){
                throw MtmExceptions::IllegalInitialization();
            }
            try {
                matrix = new T *[r];
                for (int i = 0; i < r; i++) {
                    matrix[i] = new T[c];
                }
            }
            catch (std::bad_alloc& excepObj){
                throw MtmExceptions::OutOfMemory();
            }
            // initializing the matrix with the default value
            for(int i=0; i < r ; i++){
                for(int j=0; j < c ; j++){
                    matrix[i][j] = val;
                }
            }
        }

        MtmMat(const MtmMat& m) : MtmMat(Dimensions(m.r , m.c),0){
            for (int i = 0; i < r ; ++i) {
                for (int j = 0; j < c ; ++j) {
                    matrix[i][j] = m.matrix[i][j];
                }
            }
        }


        explicit MtmMat(const MtmVec<T>& v):MtmMat(Dimensions(((v.getOrientation() == vertical) ? v.getSize() : 1 ) , ((v.getOrientation() == horizontal) ? v.getSize() : 1)),0){
            int s=0;
            for (int i = 0; i < r ; ++i) {
                for (int j = 0; j < c ; ++j) {
                    matrix[i][j] = v[s];
                    s++;
                }
            }
        }

        /*
         * Function that get function object f and uses it's () operator on each element in the matrix columns.
         * It outputs a vector in the size of the matrix columns where each element is the final output
         * by the function object's * operator
         */
        template <typename Func>
        MtmVec<T> matFunc(Func& f) const{
            MtmVec<T> mV(c, 0);
            for(int i=0; i<c; i++){
                Func copyFunc = f;
                for(int j=0; j<r; j++){
                    copyFunc(matrix[j][i]);
                }
                mV[i] = (*copyFunc);
            }
            return mV;
        }

        /*
         * resizes a matrix to dimension dim, new elements gets the value val.
         */
        virtual void resize(Dimensions dim, const T& val=T()){ // i didn't understand what is the exceptions we should check here
            T** new_mat = new T*[dim.getRow()] ;
            for( int i = 0 ; i < dim.getRow() ; i++ ) {
                new_mat[i] = new T[dim.getCol()];
            }
            for (int i = 0; i < dim.getRow() ; ++i) {
                for (int j = 0; j < dim.getCol() ; ++j) {
                    if(i<r && j<c){
                        new_mat[i][j] = matrix[i][j];
                    } else {
                        new_mat[i][j] = val;
                    }
                }
            }
            for (int k = 0; k < r ; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
            matrix = new_mat;
            r = dim.getRow();
            c = dim.getCol();
            return;
        }

        /*
         * reshapes matrix so linear elements value are the same without changing num of elements.
         */
        virtual void reshape(Dimensions newDim){
            if(newDim.getCol()*newDim.getRow() != r*c ){
                throw MtmExceptions::ChangeMatFail(r, c, newDim.getRow(), newDim.getCol());
            }
            T** new_mat = new T*[newDim.getRow()] ;
            for( int i = 0 ; i < newDim.getRow() ; i++ ) {
                new_mat[i] = new T[newDim.getCol()];
            }
            T* tmp_arr = new T[r*c];
            int count = 0;
            for (int i = 0; i < c ; ++i) {
                for (int j = 0; j < r ; ++j) {
                    tmp_arr[count] = matrix[j][i];
                    count++;
                }
            }
            count = 0;
            for (int i = 0; i < newDim.getCol() ; ++i) {
                for (int j = 0; j < newDim.getRow() ; ++j) {
                    new_mat[j][i] = tmp_arr[count];
                    count++;
                }
            }
            delete[] tmp_arr;
            for (int k = 0; k < r ; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
            c = newDim.getCol();
            r = newDim.getRow();
            matrix = new_mat;
            return;
        }

        /*
         * Performs transpose operation on matrix
         */
        virtual void transpose(){
            T** tr_mat = new T*[c] ;

            for( int i = 0 ; i < c ; i++ ) {
                tr_mat[i] = new T[r];
            }

            for(int i=0; i < r ; i++){
                for(int j=0; j < c ; j++){
                    tr_mat[j][i] = matrix[i][j];
                }
            }
            for (int k = 0; k < r ; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
            size_t tmp = c;
            c = r;
            r = tmp;
            matrix = tr_mat;
            return;
        }

        MtmMat& operator=(const MtmMat& m) {
            for (int k = 0; k < r ; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
            r = m.r ;
            c = m.c ;

            matrix = new T*[m.r] ;
            for( int i = 0 ; i < m.r ; i++ ) {
                matrix[i] = new T[m.c];
            }
            for (int i = 0; i < r ; ++i) {
                for (int j = 0; j < c ; ++j) {
                    matrix[i][j] = m.matrix[i][j];
                }
            }
            return (*this);
        }
        virtual T& getElement(const int i, const int j){
            return matrix[i][j];
        }
        class Inner{
            T** inn_arr;
            int row, col, num_cols;
            MtmMat* ptr;
        public:
            Inner(MtmMat<T>* pointer, T** arr, const int i, const int num_of_cols) : ptr(pointer), inn_arr(arr) , row(i) ,col(0), num_cols(num_of_cols){}
            Inner(T** arr, const int i, const int num_of_cols) : ptr(NULL), inn_arr(arr) , row(i) ,col(0), num_cols(num_of_cols){}
            const T& operator[](const int j) const{
                if(j >= num_cols || j < 0){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
                return inn_arr[row][j];
            }

            T& operator[](const int j) {
                if(j >= num_cols || j < 0){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
                return ptr->getElement(row,j);
            }
        };

        Inner operator[](const int i) {
            if(i >= r || i < 0){
                throw MtmMath::MtmExceptions::AccessIllegalElement();
            }
            return Inner(this,matrix, i, c);
        }

        const Inner operator[](const int i) const{
            if(i >= r || i < 0){
                throw MtmMath::MtmExceptions::AccessIllegalElement();
            }
            return Inner(matrix, i, c);
        }

        virtual ~MtmMat(){
            for (int k = 0; k < r ; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
        }

        class iterator{
        protected:
            T** ptr;
            int num_of_rows, num_of_columns;
            int curr_row, curr_column;
            MtmMat* objectPtr;
        public:
            iterator(MtmMat* p, T** matrix, int r, int c, int cu_r, int cu_l): ptr(matrix),num_of_rows(r),num_of_columns(c),curr_row(cu_r),curr_column(cu_l),objectPtr(p){}
            virtual iterator& operator++(){
                curr_row++;
                if(curr_row > num_of_rows-1) {
                    curr_row = 0;
                    curr_column++;
                }
                return (*this);
            }
            T& operator*() const {
                if(curr_column >= num_of_columns){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
                return objectPtr->getElement(curr_row, curr_column);
            }
            bool operator==(const iterator& it2) const {
                return (!((*this) != it2));
            }
            bool operator!=(const iterator& it2) const {
                return (ptr+curr_column*num_of_rows+curr_row != it2.ptr+(it2.curr_column*it2.num_of_rows+it2.curr_row));
            }
        };

        iterator begin(){
            return iterator(this, matrix, r, c, 0, 0);
        }

        iterator end(){
            return iterator(this, matrix, r, c, 0, c);
        }

        // nonzero_iterator class
        class nonzero_iterator : public MtmMat<T>::iterator{
        public:
            nonzero_iterator(T** matrix, int r, int c, int cu_r, int cu_c, bool isBegin, MtmMat* p) : iterator(p, matrix, r, c, cu_r, cu_c){
                if(isBegin && (this->ptr)[this->curr_row][this->curr_column] == 0){
                    ++(*this);
                }
            }
            iterator& operator++() override {
                this->curr_row++;
                if(this->curr_row > this->num_of_rows-1){
                    this->curr_row = 0 ;
                    this->curr_column++;
                    if(this->curr_column > this->num_of_columns-1){
                        return (*this);
                    }
                }

                if(this->ptr[this->curr_row][this->curr_column] == 0){
                    ++(*this);
                }
                return (*this);
            }
        };

        nonzero_iterator nzbegin(){
            return nonzero_iterator(matrix, r, c, 0, 0, true,this);
        }

        nonzero_iterator nzend(){
            return nonzero_iterator(matrix, r, c, 0, c, false,this);
        }


        // OPERATORS


        MtmMat& operator+=(const MtmMat& m2) {
            if(r != m2.r || c != m2.c){
                throw MtmExceptions::DimensionMismatch(r,c,m2.r,m2.c);
            }
            for (int i = 0; i < r ; ++i) {
                for (int j = 0; j < c ; ++j) {
                    matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
                }
            }
            return *this;
        }

        MtmMat& operator-=(const MtmMat& m2) {
            if(r != m2.r || c != m2.c){
                throw MtmExceptions::DimensionMismatch(r,c,m2.r,m2.c);
            }
            for (int i = 0; i < r ; ++i) {
                for (int j = 0; j < c ; ++j) {
                    matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
                }
            }
            return *this;
        }

        MtmMat operator-() {
            MtmMat<T> new_matrix(*this);
            for (int i = 0; i < new_matrix.getRowsNum() ; ++i) {
                for (int j = 0; j < new_matrix.getColumnsNum() ; ++j) {
                    new_matrix[i][j] = new_matrix[i][j] * (-1) ;
                }
            }
            return new_matrix;
        }

        friend MtmMat<T> operator*(const MtmMat<T>& m1, const MtmMat<T>& m2) {
            if(m1.getColumnsNum() != m2.getRowsNum()){
                throw MtmExceptions::DimensionMismatch(m1.getRowsNum(),m1.getColumnsNum(),m2.getRowsNum(),m2.getColumnsNum());
            }
            MtmMat<T> new_matrix(Dimensions(m1.getRowsNum(),m2.getColumnsNum()),0);
            for (int i = 0; i < m1.getRowsNum() ; ++i) {
                for (int j = 0; j < m2.getColumnsNum() ; ++j) {
                    T sum = 0;
                    for (int k = 0; k < m1.getColumnsNum(); ++k) {
                        sum = sum +  m1.matrix[i][k]*m2.matrix[k][j];
                    }
                    new_matrix.matrix[i][j] = sum;
                }
            }
            return new_matrix;
        }

    };

    template <typename T>
    MtmMat<T> operator+(const MtmMat<T>& m, const T& n) {
        return MtmMat<T>(m) += MtmMat<T>(Dimensions(m.getRowsNum(),m.getColumnsNum()),n);
    }

    template <typename T>
    MtmMat<T> operator+(const T& n, const MtmMat<T>& m) { // why it doesn't identify the up one?
        return m+n;
    }

    template <typename T>
    MtmMat<T> operator+(const MtmMat<T>& m1, const MtmMat<T>& m2) {
        if(m1.getRowsNum() != m2.getRowsNum() || m1.getColumnsNum() != m2.getColumnsNum()){
            throw MtmExceptions::DimensionMismatch(m1.getRowsNum(), m1.getColumnsNum(), m2.getRowsNum(), m2.getColumnsNum());
        }
        return MtmMat<T>(m1) += m2;
    }

    template <typename T>
    MtmMat<T> operator+(const MtmMat<T>& m1, const MtmVec<T>& v) {
        return m1+MtmMat<T>(v);
    }

    template <typename T>
    MtmMat<T> operator+(const MtmVec<T>& v, const MtmMat<T>& m1) {
        return MtmMat<T>(v)+m1;
    }

    template <typename T>
    MtmMat<T> operator-(const MtmMat<T>& m, const T& n) {
        return MtmMat<T>(m) -= MtmMat<T>(Dimensions(m.getRowsNum(),m.getColumnsNum()),n);
    }

    template <typename T>
    MtmMat<T> operator-( const T& n, const MtmMat<T>& m) {
        return MtmMat<T>(Dimensions(m.getRowsNum(),m.getColumnsNum()),n) -= m;
    }

    template <typename T>
    MtmMat<T> operator-(const MtmMat<T>& m1, const MtmMat<T>& m2) {
        return MtmMat<T>(m1) -= m2;
    }

    template <typename T>
    MtmMat<T> operator-(const MtmMat<T>& m1, const MtmVec<T>& v) {
        return m1-MtmMat<T>(v);
    }

    template <typename T>
    MtmMat<T> operator-(const MtmVec<T>& v, const MtmMat<T>& m1) {
        return MtmMat<T>(v)-m1;
    }

    template <typename T>
    MtmMat<T> operator*(const MtmMat<T>& m, const T& n) {
        MtmMat<T> new_matrix(m);
        for (int i = 0; i < new_matrix.getRowsNum() ; ++i) {
            for (int j = 0; j < new_matrix.getColumnsNum() ; ++j) {
                new_matrix[i][j] = new_matrix[i][j] * n ;
            }
        }
        return new_matrix;
    }

    template <typename T>
    MtmMat<T> operator*(const T& n, const MtmMat<T>& m) {
        return m*n;
    }

    template <typename T>
    MtmMat<T> operator*(const MtmVec<T>& v1, const MtmVec<T>& v2) { // i think i should delete the refence in the return value
        MtmMat<T> m1(v1);
        MtmMat<T> m2(v2);
        return m1*m2;
    }

    template <typename T>
    MtmMat<T> operator*(const MtmVec<T>& v1, const MtmMat<T>& m2) { // i think i should delete the refence in the return value
        return MtmMat<T>(v1)*m2;
    }

    template <typename T>
    MtmMat<T> operator*(const MtmMat<T>& m1, const MtmVec<T>& v2) { // i think i should delete the refence in the return value
        return m1*MtmMat<T>(v2);
    }

}


#endif //EX3_MTMMAT_H