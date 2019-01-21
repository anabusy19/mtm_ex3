#ifndef EX3_MTMVEC_H
#define EX3_MTMVEC_H

#include <vector>
#include <windef.h>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "Complex.h"
#include <algorithm>

using std::size_t;

enum Orientation {vertical, horizontal};

namespace MtmMath {
    template <typename T>
    class MtmVec {
        Orientation oi;
        int size;
        T* vec;
    public:
        bool dimTest(size_t row, size_t column) const {
            if(oi == vertical){
                if (row == size && column == 1) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (row == 1 && column == size) {
                    return true;
                } else {
                    return false;
                }
            }
        }


        bool dataTest(std::vector<T> test_arr) const {
            if (test_arr.size() != size) {
                return false;
            }
            size_t index = 0;
            for (size_t i = 0; i < size; i++) {
                if (vec[i] != test_arr[index]) {
                    return false;
                }
                index++;
            }
            return true;
        }

        int getSize() const {
            return size;
        }

        Orientation getOrientation() const {
            return oi;
        }

        /*
         * Vector constructor, m is the number of elements in it and val is the initial value for the matrix elements
         */
        MtmVec(size_t m, const T& val=T()) : oi(vertical), size(m) {
            if(m <= 0){
                throw MtmMath::MtmExceptions::IllegalInitialization();
            }
            try{
                this->vec = new T[size];
            }
            catch (std::bad_alloc& excepObj){
                throw MtmExceptions::OutOfMemory();
            }

            for (int i = 0; i < size; i++) {
                vec[i] = val;
            }
        }


        MtmVec(const MtmVec& m) : oi(m.oi), size(m.size){
            this->vec = new T[size];
            for (int i = 0; i < size ; ++i) {
                this->vec[i] = m.vec[i];
            }
        }

        /*
         * Function that get function object f and uses it's () operator on each element in the vectors.
         * It outputs the function object's * operator after iterating on all the vector's elements
         */
        template <typename Func>
        T vecFunc(Func& f) const{
            Func copyFunc = f;
            for(int i=0; i<size; i++){
                copyFunc(vec[i]);
            }
            return (*copyFunc);
        }

        /*
         * Resizes a vector to dimension dim, new elements gets the value val.
         * Notice vector cannot transpose through this method.
         */
        void resize(Dimensions dim, const T& val=T()){ // what exceptions should i check here?
            if(dim.getCol() > 1 && dim.getRow() > 1 && this->oi == horizontal ){
                throw MtmMath::MtmExceptions::ChangeMatFail(1, size, dim.getRow(), dim.getCol());
            }
            if(dim.getCol() > 1 && dim.getRow() > 1 && this->oi == vertical ){
                throw MtmMath::MtmExceptions::ChangeMatFail(size, 1, dim.getRow(), dim.getCol());
            }
            if(dim.getCol() == 1 && dim.getRow() != 1 && this->oi == horizontal){
                throw MtmMath::MtmExceptions::ChangeMatFail(1, size, dim.getRow(), dim.getCol());
            }
            if(dim.getRow() == 1 && dim.getCol() != 1 && this->oi == vertical){
                throw MtmMath::MtmExceptions::ChangeMatFail(size, 1, dim.getRow(), dim.getCol());
            }
            if((dim.getCol() == 0 || dim.getRow() == 0) && this->oi == horizontal){
                throw MtmMath::MtmExceptions::ChangeMatFail(1, size, dim.getRow(), dim.getCol());
            }
            if((dim.getCol() == 0 || dim.getRow() == 0 ) && this->oi == vertical){
                throw MtmMath::MtmExceptions::ChangeMatFail(size, 1, dim.getRow(), dim.getCol());
            }
            int new_size = std::max(dim.getCol(), dim.getRow());
            int min_size = std::min(size, new_size);

            T* new_arr = new T[new_size];
            for (int j = 0; j < min_size ; ++j) {
                new_arr[j] = vec[j];
            }
            for (int i = min_size; i < new_size ; ++i) {
                new_arr[i] = val;
            }
            delete[] vec;
            vec = new_arr;
            size = new_size;
            return;
        }

        /*
         * Performs transpose operation on matrix
         */
        void transpose(){
            switch (oi){
                case vertical: oi=horizontal;
                    break;
                case horizontal: oi=vertical;
                    break;
            }
        }

        MtmVec& operator=(MtmVec const& m){
            delete[] vec;
            size = m.size;
            oi = m.oi;
            vec = new T[size];
            for (int i = 0; i < size ; ++i) {
                vec[i] = m.vec[i];
            }
            return (*this);
        }

        const T& operator[](int i) const {
            if(i >= size){
                throw MtmExceptions::AccessIllegalElement();
            }
            return vec[i];
        }
        T& operator[](int i) {
            if(i >= size || i < 0){
                throw MtmExceptions::AccessIllegalElement();
            }
            return vec[i];
        }

        ~MtmVec(){
            delete[] vec;
        }

        MtmVec& operator+=(const MtmVec& v) {
            if((size == 1 && v.size != 1) || (size != 1 && v.size == 1)){
                if(oi == vertical){
                    if(v.oi == vertical){
                        throw MtmExceptions::DimensionMismatch(size,1,v.size,1);
                    } else {
                        throw MtmExceptions::DimensionMismatch(size,1,1,v.size);
                    }
                } else {
                    if(v.oi == vertical){
                        throw MtmExceptions::DimensionMismatch(1,size,v.size,1);
                    } else {
                        throw MtmExceptions::DimensionMismatch(1,size,1,v.size);
                    }
                }
            }
            if(oi != v.oi){
                if(oi == vertical){
                    throw MtmExceptions::DimensionMismatch(size,1,1,v.size);
                }
                else{
                    throw MtmExceptions::DimensionMismatch(1,size,v.size,1);
                }
            }
            if(size != v.size){
                if(oi == vertical){
                    throw MtmExceptions::DimensionMismatch(size,1,v.size,1);
                }
                else{
                    throw MtmExceptions::DimensionMismatch(1,size,1,v.size);
                }
            }
            for (int i = 0; i < size; ++i) {
                vec[i] = vec[i]+v.vec[i];
            }
            return *this;
        }

        MtmVec& operator*=(const T& n) {
            for (int i = 0; i < size ; ++i) {
                vec[i] = vec[i] * n ;
            }
            return *this;
        }

        MtmVec& operator-=(const MtmVec& v) {
            MtmVec<T> new_v(v);
            return (*this += new_v*(-1));
        }

        MtmVec operator-(){
            MtmVec<T> new_v(*this);
            for (int i = 0; i < new_v.getSize() ; ++i) {
                new_v[i] = new_v[i] * (-1) ;
            }
            return new_v;
        }

        // Iterator &n non-zero Iterator

        class iterator{
        protected:
            T* ptr;
            int length,curr_loc;
            MtmVec* objectPtr;
        public:
            iterator(MtmVec* p, T* vec, int len, int cu_lo): ptr(vec),length(len),curr_loc(cu_lo),objectPtr(p){}
            virtual iterator& operator++(){
                // should i check if the curr_loc is >= length?
                curr_loc++;
                return (*this);
            }
            T& operator*() const {
                if(curr_loc >= length){
                    throw MtmMath::MtmExceptions::AccessIllegalElement();
                }
                return ptr[curr_loc];
            }
            bool operator==(const iterator& it2) const {
                return (!((*this) != it2));
            }
            bool operator!=(const iterator& it2) const {
                return (ptr+curr_loc != it2.ptr+(it2.curr_loc));
            }
        };

        iterator begin(){
            return iterator(this, vec, size,0);
        }

        iterator end(){
            return iterator(this, vec, size, size);
        }

        // nonzero_iterator class
        class nonzero_iterator : public MtmVec<T>::iterator{
        public:
            nonzero_iterator(T* vec, int len, int cu_l, bool isBegin, MtmVec* p) : iterator(p, vec, len, cu_l){
                if(isBegin && (this->ptr)[this->curr_loc] == 0){
                    ++(*this);
                }
            }
            iterator& operator++() override {
                this->curr_loc++;
                if(this->curr_loc > this->length-1){
                    return (*this);
                }
                if(this->ptr[this->curr_loc] == 0){
                    ++(*this);
                }
                return (*this);
            }
        };

        nonzero_iterator nzbegin(){
            return nonzero_iterator(vec, size, 0, true, this);
        }

        nonzero_iterator nzend(){
            return nonzero_iterator(vec, size, size, false, this);
        }
    };

    template <typename T>
    MtmVec<T> operator+(const MtmVec<T>& v1, const MtmVec<T>& v2){
        return MtmVec<T>(v1) += v2;
    }

    template <typename T>
    MtmVec<T> operator+(const MtmVec<T>& v1, const T& n){
        if(v1.getOrientation() == vertical){
            return MtmVec<T>(v1) += MtmVec<T>(v1.getSize(),n);
        }
        else{
            MtmVec<T> v2(v1.getSize(),n);
            v2.transpose();
            return MtmVec<T>(v1) += v2;
        }
    }

    template <typename T>
    MtmVec<T> operator+(const T& n, const MtmVec<T>& v1) {
        return v1+n;
    }

    template <typename T>
    MtmVec<T> operator-(const MtmVec<T>& v1, const MtmVec<T>& v2){
        return MtmVec<T>(v1) -= v2;
    }

    template <typename T>
    MtmVec<T> operator-(const MtmVec<T>& v1, const T& n){
        return v1+(-n);
    }

    template <typename T>
    MtmVec<T> operator-(const T& n, const MtmVec<T>& v1) {
        if(v1.getOrientation() == vertical){
            return MtmVec<T>(v1.getSize(),n) -= v1;
        }
        else{
            MtmVec<T> v2(v1.getSize(),n);
            v2.transpose();
            return v2 -= v1;
        }
    }

    template <typename T>
    MtmVec<T> operator*(const MtmVec<T>& v1, const T& n) {
        MtmVec<T> new_v(v1);
        for (int i = 0; i < new_v.getSize() ; ++i) {
            new_v[i] = new_v[i] * n ;
        }
        return new_v;
    }

    template <typename T>
    MtmVec<T> operator*(const T& n, const MtmVec<T>& v1) {
        return v1*n;
    }
}

#endif //EX3_MTMVEC_H
