#ifndef EX3_MTMMATREC_H
#define EX3_MTMMATREC_H

#include <vector>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "MtmMat.h"

using std::size_t;

namespace MtmMath {

    template <typename T>
    class MtmMatSq : public MtmMat<T> {
    public:
        /*
         * Rectangular Matrix constructor, m is the number of rows and columns in the matrix
         * and val is the initial value for the matrix elements
         */
        MtmMatSq (size_t m, const T& val=T()) : MtmMat<T>(Dimensions(m,m),val){}

        MtmMatSq(const MtmMatSq& mm) : MtmMat<T>(mm){}

        MtmMatSq(const MtmMat<T>& m) : MtmMat<T>(m){
            if(m.getRowsNum() != m.getColumnsNum()){
                throw MtmExceptions::IllegalInitialization();
            }
        }

        void reshape(Dimensions newDim) override {
            throw MtmExceptions::ChangeMatFail(this->r, this->c, newDim.getRow(), newDim.getCol());
        }

        virtual void resize(Dimensions dim, const T& val=T()){
            if(dim.getCol() != dim.getRow()){
                throw MtmExceptions::ChangeMatFail(this->r, this->c, dim.getRow(), dim.getCol());
            }
            MtmMat<T>::resize(dim,val);
            return;
        }

        virtual ~MtmMatSq() = default;

    };

}

#endif //EX3_MTMMATREC_H
