//#include <iostream>
//
//#include "MtmVec.h"
//#include "MtmMat.h"
//#include "MtmMatSq.h"
//#include "MtmMatTriag.h"
//#include "Complex.h"
//
//#include <assert.h>
//using namespace MtmMath;
//using std::cout;
//using std::endl;
//
//static void printm(MtmMat<int> m){
//
//    for(int i=0; i<m.Rows(); i++){
//
//        for(int j=0; j<m.Columns(); j++){
//
//            std::cout << m[i][j] ;
//            std::cout << " ";
//            if(j==m.Columns()-1)
//                std::cout << std::endl;
//
//        }
//    }
//    std::cout << std::endl;
//}
//
//
//
//bool operator ==(MtmMat<int> &m1, MtmMat<int>& m2){
//
//    if(m1.Rows()!=m2.Rows()||m1.Columns()!=m2.Columns())
//        return false;
//
//    for(int i=0; i<m1.Rows(); i++) {
//        for (int j = 0; j < m2.Columns(); j++) {
//
//            if(m1[i][j]!=m2[i][j])
//                return false;
//
//        }
//    }
//
//    return true;
//
//}
//
//void exceptionsTest() {
//    try {
//        MtmVec<float> v(0,5);
//        assert(false);
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmMat<int> m1(Dimensions(10,100000000000),5);
//        assert(false);
//    }
//    catch (MtmExceptions::OutOfMemory& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmVec<int> v1(3,5);
//        MtmMat<int> m1(Dimensions(3,3),5);
//        MtmMat<int> m3=m1+v1;
//        assert(false);
//    }
//    catch (MtmExceptions::DimensionMismatch& e){
//        cout<< e.what() <<endl;
//    }
//    try {
//        MtmMat<int> m1(Dimensions(3,3),5);
//        m1.reshape(Dimensions(2,3));
//        assert(false);
//    }
//    catch (MtmExceptions::ChangeMatFail& e){
//        cout<< e.what() <<endl;
//    }
//    try {
//        MtmMat<int> m1(Dimensions(3,3),5);
//        m1[4][3]=5;
//        assert(false);
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//    try{
//
//        MtmMatTriag<int>m(5,0);
//        m[1][0]=1;
//
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//
//    try{
//
//        MtmMatTriag<int>m(5,0,false);
//        m[0][1]=1;
//
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//
//    try{
//
//        MtmMatSq<int>m(5,0);
//        m[0][1]=1;
//        m[1][0]=1;
//
//        MtmMatTriag<int>m2(m);
//
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//
//    try{
//
//        MtmMatTriag<int>m(5,0);
//        m[1][0]=1;
//
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//
//    try{
//
//        MtmMatSq<int>m(0,0);
//
//
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmMat<int> m1(Dimensions(0,3),5);
//        assert(false);
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmMat<int> m1(Dimensions(3,0),5);
//        assert(false);
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//}
//
//
//void constructors() {
//    MtmVec<int> v1(5,3);
//    MtmMat<int> m1(Dimensions(3,3),0);
//    MtmMatSq<int> m2(3,1);
//    MtmMatTriag<int> m3(3,1,true);
//}
//
//void dataTypes() {
//    MtmVec<int> v1(5,3);
//    MtmVec<double > v2(5,3);
//    MtmVec<float> v3(5,3);
//    MtmVec<Complex> v4(5,Complex(3,4));
//}
//
//void testOperator(){
//
//    MtmMat<int> m1(Dimensions(2, 5), 0);
//    MtmMat<int> m2(Dimensions(2, 5), 1);
//    m2[1][3] = 4;
//    m2[0][2] = 9;
//    m1[0][0] = 1;
//    m1 = m1 + m2;
//    m2[0][0] += 1;
//    assert(m1 == m2);
//    m1 = m1 + 2;
//    assert(m1[0][0] == 4);
//    assert(m1[1][3] == 6);
//    m1 = m1 - 2;
//    assert(m1 == m2);
//    m1 = 2 + m1;
//    assert(m1[0][0] == 4);
//    assert(m1[1][3] == 6);
//    m1 = -2 + m1;
//    assert(m1 == m2);
//    MtmMat<int> m3(Dimensions(4, 1), 1);
//    m3[1][0] = 2;
//    m3[2][0] = 3;
//    m3[3][0] = 4;
//    MtmMat<int> m4(m3);
//    m3.reshape(Dimensions(1, 4));
//    m3.transpose();
//    assert(m3 == m4);
//    m3.reshape(Dimensions(4, 1));
//    assert(m3 == m4);
//    MtmMat<int> m5(Dimensions(6, 2), 1);
//    MtmMat<int> m6(m5);
//    m6.transpose();
//    m5[5][1] = 3;
//    m5[5][0] = 2;
//    m5[4][0] = 7;
//    m5.reshape(Dimensions(2,6));
//    m6[0][2]=7;m6[1][2]=2; m6[1][5]=3;
//    printm(m6);
//    printm(m5);
//    assert(m5 == m6);
//    m6.transpose();
//    m5.reshape(Dimensions(6, 2));
//    MtmVec<int> v1(3, 1);
//    MtmMat<int> v2(Dimensions(1, 3),1);
//    MtmMat<int> m7(Dimensions(3, 3), 1);
//    m6 = v1 * v2;
//    assert(m6 == m7);
//    m6 = v2 * v1;
//    MtmMat<int> m8(Dimensions(1, 1), 3);
//    assert(m6 == m8);
//    MtmMat<int> m9(Dimensions(2, 3), 1);
//    m9[0][0] = 1;
//    m9[1][0] = 1;
//    m9[0][1] = 2;
//    m9[1][1] = 2;
//    m9[0][2] = 3;
//    m9[1][2] = 3;
//    v1[1] = 2;
//    v1[2] = 3;
//    MtmMat<int> m10(Dimensions(2, 1), 14);
//    m4 = m9 * v1;
//    assert(m4 == m10);
//    MtmMat<int> m11(m9);
//    m11.transpose();
//    m6 = m9 * m11;
//    MtmMat<int> res(Dimensions(2, 2), 14);
//    assert(m6 == res);
//    MtmMat<int> m12(Dimensions(3, 6), 1);
//    m8 = m7 * m12;
//    MtmMat<int> res2(Dimensions(3, 6), 3);
//
//}
//
//void FuncExample() {
//    class maxAbsolute {
//        int currMax;
//    public:
//        maxAbsolute() : currMax(0) {}
//        void operator()(int x) {
//            int absX = x>(-x) ? x : -x;
//            if (currMax<absX) {currMax=absX;}
//        }
//        int operator*() { return  currMax;}
//    };
//
//    MtmVec<int> v(5,0);
//    v[1]=3;v[2]=-7;v[3]=-1;v[4]=2;
//    MtmMat<int> m(Dimensions(2,3),0);
//    m[0][1]=1;m[1][0]=2;
//    m[0][1]=3;m[1][1]=2;
//    m[0][2]=5;m[1][2]=-6;
//    maxAbsolute f;
//    assert (v.vecFunc(f)==7);
//    MtmVec<int> res(m.matFunc(f));
//    assert(res[0]==2 and res[1]==3 and res[2]==6);
//}
//
//void iterators() {
//    MtmMatSq<int> m(2,0);
//    m[1][0]=1;m[1][1]=2;
//
//    int res_it[]={0,1,0,2};
//    int res_nz_it[]={1,2};
//
//    int i=0;
//    for (MtmMatSq<int>::iterator it=m.begin();it!=m.end();++it) {
//        assert (res_it[i]==(*it));
//        ++i;
//    }
//
//    i=0;
//    for (MtmMatSq<int>::nonzero_iterator it=m.nzbegin();it!=m.nzend();++it) {
//
//        int x = *it;
//        assert (res_nz_it[i]==(x));
//        ++i;
//    }
//
//    i=0;
//
//    MtmMatTriag<int> m1(5,1,false);
//
//    int res[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//    for(MtmMatTriag<int>::nonzero_iterator it=m1.nzbegin();it!=m1.end();++it) {
//
//        int t1 = res[i];
//        int t2 = *it;
//        *it=15;
//        assert(t1 == t2 && 15>i);
//        i++;
//        //5
//    }
//
//    MtmMatTriag<int> m2(5,0,false);
//    m2[4][4]=2;
//    MtmMatTriag<int>::nonzero_iterator it=m2.nzbegin();
//    int t = *it;
//    assert(t==2);
//    ++it;
//    assert(it==m2.nzend());
//
//
//}
//
//void testResize(){
//    MtmMat<int> m5(Dimensions(4, 2), 1);
//    m5.resize(Dimensions(4,3),2);
//    assert(m5[0][0] == 1);
//    assert(m5[0][1] == 1);
//    assert(m5[0][2] == 2);
//    assert(m5[1][0] == 1);
//    assert(m5[1][1] == 1);
//    assert(m5[1][2] == 2);
//    assert(m5[2][0] == 1);
//    assert(m5[2][1] == 1);
//    assert(m5[2][2] == 2);
//    assert(m5[3][0] == 1);
//    assert(m5[3][1] == 1);
//    assert(m5[3][2] == 2);
//
//    MtmMatTriag<int> m2(3, 1);
//    m2[0][1] = 2;
//    m2[0][2] = 2;
//    m2[1][2] = 2;
//    m2.resize(Dimensions(4,4),3);
//    assert(m2[0][0] == 1);
//    assert(m2[0][1] == 2);
//    assert(m2[0][2] == 2);
//    assert(m2[1][1] == 1);
//    assert(m2[1][2] == 2);
//    assert(m2[2][2] == 1);
//    assert(m2[0][3] == 3);
//    assert(m2[1][3] == 3);
//    assert(m2[2][3] == 3);
//    assert(m2[3][3] == 3);
//    try{
//        m2.reshape(Dimensions(8,2));
//    }
//    catch (MtmExceptions::ChangeMatFail& e){
//        cout<< e.what() <<endl;
//    }
//    m5 = m2 + 2;
//    assert(m5[0][0] == 3);
//    assert(m5[0][1] == 4);
//    assert(m5[0][2] == 4);
//    assert(m5[1][0] == 2);
//    assert(m5[1][1] == 3);
//    assert(m5[2][2] == 3);
//    assert(m5[3][1] == 2);
//    assert(m5[3][2] == 2);
//    assert(m5[3][3] == 5);
//    m5.transpose();
//    assert(m5[0][1] == 2);
//}
//
//void testMultiply(){
//    MtmVec<int> v1(3, 1);
//    v1.transpose();
//    MtmMat<int> m1(Dimensions(3, 2),2);
//    try{
//        m1.reshape(Dimensions(6,3));
//    }
//    catch (MtmExceptions::ChangeMatFail& e){
//        cout<< e.what() <<endl;
//    }
//    m1.resize(Dimensions(3,3), 3);
//    m1 = v1 * m1;
//    assert(m1[0][0] == 6);
//    assert(m1[0][1] == 6);
//    assert(m1[0][2] == 9);
//    m1 = m1 * 3;
//    assert(m1[0][0] == 18);
//    assert(m1[0][1] == 18);
//    assert(m1[0][2] == 27);
//    m1.transpose();
//    assert(m1[0][0] == 18);
//    assert(m1[1][0] == 18);
//    assert(m1[2][0] == 27);
//}
//
//int main() {
//    constructors();
//    dataTypes();
//    FuncExample();
//    iterators();
//    testOperator();
//    exceptionsTest();
//    testResize();
//    testMultiply();
//    return 0;
//
//}
//////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "MtmVec.h"
#include "MtmMat.h"
#include "MtmMatSq.h"
#include "MtmMatTriag.h"
#include "Complex.h"

#include <assert.h>
using namespace MtmMath;
using std::cout;
using std::endl;

//void exceptionsTest() {
//    try {
//        MtmVec<float> v(0,5);
//        assert(false);
//    }
//    catch (MtmExceptions::IllegalInitialization& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmMat<int> m1(Dimensions(10,100000000000),5);
//        assert(false);
//    }
//    catch (MtmExceptions::OutOfMemory& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        MtmVec<int> v1(3,5);
//        MtmMat<int> m1(Dimensions(3,3),5);
//        MtmMat<int> m3=m1+v1;
//        assert(false);
//    }
//    catch (MtmExceptions::DimensionMismatch& e){
//        cout<< e.what() <<endl;
//    }
//    try {
//        MtmMat<int> m1(Dimensions(3,3),5);
//        m1.reshape(Dimensions(2,3));
//        assert(false);
//    }
//    catch (MtmExceptions::ChangeMatFail& e){
//        cout<< e.what() <<endl;
//    }
//    try {
//        MtmMat<int> m1(Dimensions(3,3),5);
//        m1[4][3]=5;
//        assert(false);
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//}
//
//void constructors() {
//    MtmVec<int> v1(5,3);
//    MtmMat<int> m1(Dimensions(3,3),0);
//    MtmMatSq<int> m2(3,1);
//    MtmMatTriag<int> m3(3,1,true);
//}
//
//void dataTypes() {
//    MtmVec<int> v1(5,3);
//    MtmVec<double > v2(5,3);
//    MtmVec<float> v3(5,3);
//    MtmVec<Complex> v4(5,Complex(3,4));
//}
//
//void FuncExample() {
//    class maxAbsolute {
//        int currMax;
//    public:
//        maxAbsolute() : currMax(0) {}
//        void operator()(int x) {
//            int absX = x>(-x) ? x : -x;
//            if (currMax<absX) {currMax=absX;}
//        }
//        int operator*() { return  currMax;}
//    };
//
//    MtmVec<int> v(5,0);
//    v[1]=3;v[2]=-7;v[3]=-1;v[4]=2;
//    MtmMat<int> m(Dimensions(2,3),0);
//    m[0][1]=1;m[1][0]=2;
//    m[0][1]=3;m[1][1]=2;
//    m[0][2]=5;m[1][2]=-6;
//    maxAbsolute f;
//    assert (v.vecFunc(f)==7);
//    MtmVec<int> res(m.matFunc(f));
//    assert(res[0]==2 and res[1]==3 and res[2]==6);
//}
//
//void iterators() {
//    MtmMatSq<int> m(2,0);
//    m[1][0]=1;m[1][1]=2;
//
//    int res_it[]={0,1,0,2};
//    int res_nz_it[]={1,2};
//
//    int i=0;
//    for (MtmMatSq<int>::iterator it=m.begin();it!=m.end();++it) {
//        assert (res_it[i]==(*it));
//        ++i;
//    }
//
//    i=0;
//    for (MtmMatSq<int>::nonzero_iterator it=m.nzbegin();it!=m.nzend();++it) {
//        assert (res_nz_it[i]==(*it));
//        ++i;
//    }
//
//}
//
//
//
//int main() {
//    exceptionsTest();
//    constructors();
//    dataTypes();
//    FuncExample();
//    iterators();
//}


//////////////////////////////////////////////////////////////

//////////                  TO DO BEFORE RUNNING TESTS                //////////////
 ////////////////////ADD THESE FUNCTIONS TO THE FOLLOWING CLASSES///////////////////
 //////////////////// MAKE SURE YOU RUN THE TEST WITHOUT DNDGBUG ///////////////////
 //////////////////////////////////////MtmVec///////////////////////////////////////


 ///////////////////////////////////MtmMatTriag////////////////////////////////////

         /************************* Testing Functions **************************/
         /*
         /*
          * Print matrix data
          */


// /////////////////////////////////////MtmMat///////////////////////////////////////

//         /*
//          * Test if dimensions match provided values
//          */


//         /*
//          * Test if content in index data matches the appropriate index in the
//          * provided array
//          */

//MtmMat Tests
void mtmMatConstructors() {
    //int
    MtmMat<int> mi0(Dimensions(3,3));
    MtmMat<int> mi1(Dimensions(3,3),0);
    MtmMat<int> mi2(mi1);
    assert(mi1.dimTest(3,3));
    assert(mi2.dimTest(3,3));
    std::vector<int> itest_arr1 = {0,0,0,0,0,0,0,0,0};
    assert(mi1.dataTest(itest_arr1));
    assert(mi2.dataTest(itest_arr1));

    //double
    MtmMat<double> md0(Dimensions(3,3));
    MtmMat<double> md1(Dimensions(3,3),0.1);
    MtmMat<double> md2(md1);
    assert(md1.dimTest(3,3));
    assert(md2.dimTest(3,3));
    std::vector<double> dtest_arr1 = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
    assert(md1.dataTest(dtest_arr1));
    assert(md2.dataTest(dtest_arr1));

    //float
    MtmMat<float> mf0(Dimensions(3,3));
    MtmMat<float> mf1(Dimensions(3,3),6.5);
    MtmMat<float> mf2(mf1);
    assert(mf1.dimTest(3,3));
    assert(mf2.dimTest(3,3));
    std::vector<float> ftest_arr1 = {6.5,6.5,6.5,6.5,6.5,6.5,6.5,6.5,6.5};
    assert(mf1.dataTest(ftest_arr1));
    assert(mf2.dataTest(ftest_arr1));

    //Complex
    MtmMat<Complex> mc0(Dimensions(3,3));
    MtmMat<Complex> mc1(Dimensions(3,3),Complex(2,3));
    MtmMat<Complex> mc2(mc1);
    assert(mc1.dimTest(3,3));
    assert(mc2.dimTest(3,3));
    std::vector<Complex> ctest_arr1 = {Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3)};
    assert(mc1.dataTest(ctest_arr1));
    assert(mc2.dataTest(ctest_arr1));
    return;
}

void mtmMatIntOperators() {
    int scalar = 2;
    std::vector<int> test_arr_0 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> test_arr_1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::vector<int> test_arr_m1 = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    std::vector<int> test_arr_2 = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    std::vector<int> test_arr_m2 = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};
    std::vector<int> test_arr_3 = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    std::vector<int> test_arr_18 = {18,18};

    MtmMat<int> m1(Dimensions(4,4), 0);
    MtmMat<int> m2(Dimensions(4,4), 1);
    MtmMat<int> m3 = m1 + m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 + scalar;
    assert(m3.dataTest(test_arr_2));
    m3 = scalar + m2;
    assert(m3.dataTest(test_arr_3));
    m3 = m1 - m2;
    assert(m3.dataTest(test_arr_m1));
    m3 = scalar - m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 - scalar;
    assert(m3.dataTest(test_arr_m2));
//    m3 = -m3;
//    assert(m3.dataTest(test_arr_2));
    m3 = m1 * 2;
    assert(m3.dataTest(test_arr_0));
    m3 = m2 * 2;
    assert(m3.dataTest(test_arr_2));
    m3 = 3 * m2;
    assert(m3.dataTest(test_arr_3));

    m2 = MtmMat<int>(Dimensions(2,3),2);
    m1 = MtmMat<int>(Dimensions(3,1),3);

    m3 = m2 * m1;
    assert(m3.dimTest(2,1));
    assert(m3.dataTest(test_arr_18));
    assert(m3[0][0] == 18);
    m2[0][0] = 1;
    m2[1][0] = 2;
    m2[0][1] = 3;
    m2[1][1] = 4;
    m2[0][2] = 5;
    m2[1][2] = 6;
    m1[0][0] = 7;
    m1[1][0] = 8;
    m1[2][0] = 9;

    std::vector<int> test_arr_76_100 = {76,100};
    m3 = m2 * m1;
    assert(m3.dimTest(2,1));
    assert(m3.dataTest(test_arr_76_100));
}

void mtmMatComplexOperators() {
    Complex scalar = 2;
    std::vector<Complex> test_arr_0 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<Complex> test_arr_1 = {Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1),Complex(1,1)};
    std::vector<Complex> test_arr_m1 = {Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1),Complex(-1,-1)};
    std::vector<Complex> test_arr_1_1 = {Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1),Complex(1,-1)};
    std::vector<Complex> test_arr_2 = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    std::vector<Complex> test_arr_2_2 = {Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2),Complex(2,2)};
    std::vector<Complex> test_arr_m2 = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};
    std::vector<Complex> test_arr_3_1 = {Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1),Complex(3,1)};
    std::vector<Complex> test_arr_3_3 = {Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3),Complex(3,3)};
    std::vector<Complex> test_arr_39 = {Complex(0,39),Complex(0,39)};

    MtmMat<Complex> m1(Dimensions(4,4), 0);
    MtmMat<Complex> m2(Dimensions(4,4), Complex(1,1));
    MtmMat<Complex> m3 = m1 + m2;
    m3.printData();

    assert(m3.dataTest(test_arr_1)); //1+1i
    m3 = m1 + scalar;
    assert(m3.dataTest(test_arr_2)); //2+0i
    m3 = scalar + m2;
    assert(m3.dataTest(test_arr_3_1)); //3+1i
    m3 = m1 - m2;
    assert(m3.dataTest(test_arr_m1)); //-1-1i
    m3 = scalar - m2;
    assert(m3.dataTest(test_arr_1_1)); //1-1i
    m3 = m1 - scalar;
    assert(m3.dataTest(test_arr_m2)); //-2+0i
//    m3 = -m3;
//    assert(m3.dataTest(test_arr_2)); //2+0i
    m3 = m1 * Complex(2,0);
    assert(m3.dataTest(test_arr_0)); //0+0i
    m3 = m2 * Complex(2,0);
    assert(m3.dataTest(test_arr_2_2)); //2+2i
    m3 = Complex(3,0) * m2;
    assert(m3.dataTest(test_arr_3_3)); //3+3i

    m2 = MtmMat<Complex>(Dimensions(2,3),Complex(2,3));
    m1 = MtmMat<Complex>(Dimensions(3,1),Complex(3,2));

    m3 = m2 * m1;
    assert(m3.dimTest(2,1));
    assert(m3.dataTest(test_arr_39));
    assert(m3[0][0] == Complex(0,39));
    m2[0][0] = Complex(1,1);
    m2[1][0] = Complex(2,2);
    m2[0][1] = Complex(3,3);
    m2[1][1] = Complex(4,4);
    m2[0][2] = Complex(5,5);
    m2[1][2] = Complex(6,6);
    m1[0][0] = Complex(7,7);
    m1[1][0] = Complex(8,8);
    m1[2][0] = Complex(9,9);

    std::vector<Complex> test_arr_152_200 = {Complex(0,152),Complex(0,200)};
    m3 = m2 * m1;
    assert(m3.dimTest(2,1));
    assert(m3.dataTest(test_arr_152_200));
}

void mtmMatIntIterators() {
    //int
    MtmMat<int> m(Dimensions(2,3), 0);
    MtmMat<int>::nonzero_iterator nz_it_0 = m.nzbegin();

//    assert(nz_it_0.pubGetLocation() == 6);
    ++nz_it_0;
    m[1][0] = 1;    //0 2 4
    m[0][1] = 2;    //1 3 5
    m[1][1] = 3;
    m[0][2] = 4;
    m[1][2] = 5;
    MtmMat<int>::iterator it_0 = m.begin();
    MtmMat<int>::iterator it_end = m.end();
//    assert(it_0.pubGetLocation() == 0);
//    assert(it_end.pubGetLocation() == 6);
    for(int i = 0; it_0 != it_end; ++it_0, ++i) {
        assert(*it_0 == i);
    }

    m[1][0] = 0; /// 0 2 4
    m[1][1] = 0; /// 0 0 5
    MtmMat<int>::nonzero_iterator nz_it_1 = m.nzbegin();
    MtmMat<int>::nonzero_iterator nz_it_end = m.nzend();
//    assert(nz_it_1.pubGetLocation() == 2);
//    assert(nz_it_end.pubGetLocation() == 6);
    int test_arr[3] = {2, 4, 5};
    for(int i = 0; nz_it_1 != nz_it_end; ++nz_it_1, i++) {
        assert(*nz_it_1 != 0);
        assert(*nz_it_1 == test_arr[i]);
        test_arr[i]=test_arr[i];
    }

    MtmMat<int>::iterator it_1 = m.begin();
    MtmMat<int>::iterator it_2 = m.begin();
    ++it_1;
    assert(it_1 != it_2);
    ++it_2;
    assert(it_1 == it_2);

    MtmMat<int>::nonzero_iterator nz_it_2 = m.nzbegin();
    MtmMat<int>::nonzero_iterator nz_it_3 = m.nzbegin();
    ++nz_it_2;
    assert(nz_it_2 != nz_it_3);
    ++nz_it_3;
    assert(nz_it_2 == nz_it_3);

    MtmMat<int>::nonzero_iterator nz_it_4 = m.nzbegin();
    for(; nz_it_4 != nz_it_end; ++nz_it_4) {
        *nz_it_4 = 4;
    }
    std::vector<int> test_arr_0_4 = {0,0,4,0,4,4};
    assert(m.dataTest(test_arr_0_4));

    MtmMat<int>::iterator it_3 = m.begin();
    for(; it_3 != it_end; ++it_3) {
        *it_3 = 1;
    }
    std::vector<int> test_arr_1 = {1,1,1,1,1,1};
    assert(m.dimTest(2,3));
    assert(m.dataTest(test_arr_1));
    return;
}

void mtmMatIntMethods() {
    MtmMat<int> m1(Dimensions(4,4), 0);
    MtmMat<int> m2(Dimensions(2,2), 0);
    MtmMat<int> m3(Dimensions(4,4), 0);
    MtmMat<int> m4(Dimensions(2,3), 0);

    MtmMat<int>::iterator it = m1.begin();
    MtmMat<int>::iterator it_end = m1.end();
    for(int i = 0 ;it != it_end; ++it, i++) {
        *it = i;
    }

    m1.reshape(Dimensions(2,8));
    std::vector<int> test_arr_1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    assert(m1.dimTest(2,8));
    assert(m1.dataTest(test_arr_1));
    MtmMat<int>::iterator it_2 = m1.begin();
    for(int i = 0 ;it_2 != m1.end(); ++it_2, i++) {
        assert(*it_2 == i);
    }

    m1.reshape(Dimensions(4,4));
    assert(m1.dimTest(4,4));
    assert(m1.dataTest(test_arr_1));
    MtmMat<int>::iterator it_3 = m1.begin();
    for(int i = 0 ;it_3 != m1.end(); ++it_3, i++) {
        assert(*it_3 == i);
    }

    m2.resize(Dimensions(3,4), 1);
    std::vector<int> test_arr_2 = {0,0,1,0,0,1,1,1,1,1,1,1};
    assert(m2.dimTest(3,4));
    assert(m2.dataTest(test_arr_2));

    m3.resize(Dimensions(2,3), 1);
    std::vector<int> test_arr_3 = {0,0,0,0,0,0};
    assert(m3.dimTest(2,3));
    assert(m3.dataTest(test_arr_3));


    MtmMat<int>::iterator it_4 = m4.begin();
    MtmMat<int>::iterator it_4_end = m4.end();
    for(int i = 0 ;it_4 != it_4_end; ++it_4, i++) {
        *it_4 = i;
    }

    m4.transpose();
    std::vector<int> test_arr_4 = {0,2,4,1,3,5};
    assert(m4.dimTest(3,2));
    assert(m4.dataTest(test_arr_4));

    m4.transpose();
    std::vector<int> test_arr_5 = {0,1,2,3,4,5};
    assert(m4.dimTest(2,3));
    assert(m4.dataTest(test_arr_5));
    return;
}

void mtmMatComplexIterators() {
    MtmMat<Complex> m(Dimensions(2,3), 0);
    MtmMat<Complex>::nonzero_iterator nz_it_0 = m.nzbegin();
//    assert(nz_it_0.pubGetLocation() == 6);
    ++nz_it_0;
    m[1][0] = Complex(1,1);
    m[0][1] = Complex(2,2);
    m[1][1] = Complex(3,3);
    m[0][2] = Complex(4,4);
    m[1][2] = Complex(5,5);
    Complex test_arr_full[6] = {Complex(0,0),Complex(1,1),
                                Complex(2,2),Complex(3,3),
                                Complex(4,4),Complex(5,5)};
    MtmMat<Complex>::iterator it_0 = m.begin();
    MtmMat<Complex>::iterator it_end = m.end();
//    assert(it_0.pubGetLocation() == 0);
//    assert(it_end.pubGetLocation() == 6);
    for(int i = 0; it_0 != it_end; ++it_0, ++i) {
        assert(*it_0 == test_arr_full[i]);
    }
    test_arr_full[0]=5;
    m[1][0] = 0;
    m[1][1] = 0;
    MtmMat<Complex>::nonzero_iterator nz_it_1 = m.nzbegin();
    MtmMat<Complex>::nonzero_iterator nz_it_end = m.nzend();
//    assert(nz_it_1.pubGetLocation() == 2);
//    assert(nz_it_end.pubGetLocation() == 6);
    Complex test_arr[3] = {Complex(2,2), Complex(4,4), Complex(5,5)};
    for(int i = 0; nz_it_1 != nz_it_end; ++nz_it_1, i++) {
        assert(*nz_it_1 != 0);
        assert(*nz_it_1 == test_arr[i]);
    }
    test_arr[0]=0;
    MtmMat<Complex>::iterator it_1 = m.begin();
    MtmMat<Complex>::iterator it_2 = m.begin();
    ++it_1;
    assert(it_1 != it_2);
    ++it_2;
    assert(it_1 == it_2);

    MtmMat<Complex>::nonzero_iterator nz_it_2 = m.nzbegin();
    MtmMat<Complex>::nonzero_iterator nz_it_3 = m.nzbegin();
    ++nz_it_2;
    assert(nz_it_2 != nz_it_3);
    ++nz_it_3;
    assert(nz_it_2 == nz_it_3);

    MtmMat<Complex>::nonzero_iterator nz_it_4 = m.nzbegin();
    for(; nz_it_4 != nz_it_end; ++nz_it_4) {
        *nz_it_4 = 4;
    }
    std::vector<Complex> test_arr_0_4 = {0,0,4,0,4,4};
    assert(m.dataTest(test_arr_0_4));

    MtmMat<Complex>::iterator it_3 = m.begin();
    for(; it_3 != it_end; ++it_3) {
        *it_3 = Complex(1.1,1.1);
    }
    std::vector<Complex> test_arr_1 = {Complex(1.1,1.1),Complex(1.1,1.1),
                                       Complex(1.1,1.1),Complex(1.1,1.1),
                                       Complex(1.1,1.1),Complex(1.1,1.1)};
    assert(m.dimTest(2,3));
    assert(m.dataTest(test_arr_1));
    return;
}

void mtmMatComplexMethods() {
    MtmMat<Complex> m1(Dimensions(4,4), 0);
    MtmMat<Complex> m2(Dimensions(2,2), 0);
    MtmMat<Complex> m3(Dimensions(4,4), 0);
    MtmMat<Complex> m4(Dimensions(2,3), 0);

    MtmMat<Complex>::iterator it = m1.begin();
    MtmMat<Complex>::iterator it_end = m1.end();
    for(int i = 0 ;it != it_end; ++it, i++) {
        *it = i;
    }

    m1.reshape(Dimensions(2,8));
    std::vector<Complex> test_arr_1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    assert(m1.dimTest(2,8));
    assert(m1.dataTest(test_arr_1));
    MtmMat<Complex>::iterator it_2 = m1.begin();
    for(int i = 0 ;it_2 != m1.end(); ++it_2, i++) {
        assert(*it_2 == i);
    }

    m1.reshape(Dimensions(4,4));
    assert(m1.dimTest(4,4));
    assert(m1.dataTest(test_arr_1));
    MtmMat<Complex>::iterator it_3 = m1.begin();
    for(int i = 0 ;it_3 != m1.end(); ++it_3, i++) {
        assert(*it_3 == i);
    }

    m2.resize(Dimensions(3,4), Complex(1,1));
    std::vector<Complex> test_arr_2 = {0,0,Complex(1,1),0,0,Complex(1,1),Complex(1,1),
                                       Complex(1,1),Complex(1,1),Complex(1,1),
                                       Complex(1,1),Complex(1,1)};
    assert(m2.dimTest(3,4));
    assert(m2.dataTest(test_arr_2));

    m3.resize(Dimensions(2,3), 1);
    std::vector<Complex> test_arr_3 = {0,0,0,0,0,0};
    assert(m3.dimTest(2,3));
    assert(m3.dataTest(test_arr_3));


    MtmMat<Complex>::iterator it_4 = m4.begin();
    MtmMat<Complex>::iterator it_4_end = m4.end();
    for(int i = 0 ;it_4 != it_4_end; ++it_4, i++) {
        *it_4 = i;
    }

    m4.transpose();
    std::vector<Complex> test_arr_4 = {0,2,4,1,3,5};
    assert(m4.dimTest(3,2));
    assert(m4.dataTest(test_arr_4));

    m4.transpose();
    std::vector<Complex> test_arr_5 = {0,1,2,3,4,5};
    assert(m4.dimTest(2,3));
    assert(m4.dataTest(test_arr_5));
    return;
}

void mtmMatExceptionsTest() {
    try {
        MtmMat<int> m1(Dimensions(0,5),0);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m2(Dimensions(5,0),0);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    MtmMat<int> m0(Dimensions(1,1),0);
    MtmMat<int> m5(Dimensions(3,3),0);
    MtmMat<int> m6(Dimensions(3,3),0);
    MtmMat<int> m7(Dimensions(3,2),0);

    try {
        m0 = m5 + m7;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 - m7;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m7 * m7;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(3,1));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(2,3));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    MtmMat<int>::iterator it = m5.begin();
    MtmMat<int>::iterator it_end = m5.end();
    for (int i = 0; i < 20; i++, ++it) {}

    try {
        *it = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

//    try {
//        *it_end = 0;
//        assert(false);
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }
//
//    try {
//        cout << *it_end << endl;
//        assert(false);
//    }
//    catch (MtmExceptions::AccessIllegalElement& e){
//        cout<< e.what() <<endl;
//    }

    try {
        m5[0][3] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[3][0] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[0][4] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[4][0] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m1(Dimensions(10,100000000000),5);
        assert(false);
    }
    catch (MtmExceptions::OutOfMemory& e){
        cout<< e.what() <<endl;
    }
}

void mtmMatDataTypes() {
    MtmMat<int> m1(Dimensions(5,3), 5);
    MtmMat<double> m2(Dimensions(5,3),5.5);
    MtmMat<float> m3(Dimensions(5,3), 4534.4);
    MtmMat<Complex> m4(Dimensions(6,6),Complex(6,6));
}

void mtmMatFunc() {
    class maxAbsolute {
        int currMax;
    public:
        maxAbsolute() : currMax(0) {}
        void operator()(int x) {
            int absX = x>(-x) ? x : -x;
            if (currMax<absX) {currMax=absX;}
        }
        int operator*() { return  currMax;}
    };

    MtmMat<int> m(Dimensions(2,3),0);
    m[0][1]=1;m[1][0]=2;
    m[0][1]=3;m[1][1]=2;
    m[0][2]=5;m[1][2]=-6;
    maxAbsolute f;
    MtmVec<int> res(m.matFunc(f));
    assert(res[0]==2 and res[1]==3 and res[2]==6);
}

void mtmMatTest() {
    mtmMatConstructors();
    mtmMatIntIterators();
    mtmMatIntMethods();
    mtmMatComplexIterators();
    mtmMatComplexMethods();
    mtmMatIntOperators();
    mtmMatComplexOperators();
    mtmMatFunc();
    mtmMatExceptionsTest();
    mtmMatDataTypes();
    cout << "mtmMatTest() Done" << endl;
    return;
}

//MtmMatSq Tests
void mtmMatSqAdditional() {
    MtmMatSq<int> m0(3);
    MtmMatSq<int> m1(3,0);
    MtmMatSq<int> m2(m1);
    MtmMat<int> m3(Dimensions(3,3),0);
    MtmMatSq<int> m4(m3);
    assert(m1.dimTest(3,3));
    assert(m2.dimTest(3,3));
    assert(m4.dimTest(3,3));
    std::vector<int> test_arr1 = {0,0,0,0,0,0,0,0,0};
    assert(m1.dataTest(test_arr1));
    assert(m2.dataTest(test_arr1));
    assert(m4.dataTest(test_arr1));
    m4.resize(Dimensions(4,4), 1);
    std::vector<int> test_arr2 = {0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    assert(m4.dimTest(4,4));
    assert(m4.dataTest(test_arr2));
    return;
}

void mtmMatSqConstructors() {
    //int
    MtmMatSq<int> mi0(3);
    MtmMatSq<int> mi1(3,0);
    MtmMatSq<int> mi2(mi1);
    MtmMat<int> mi3(Dimensions(3,3),0);
    MtmMatSq<int> mi4(mi3);

    assert(mi1.dimTest(3,3));
    assert(mi2.dimTest(3,3));
    assert(mi4.dimTest(3,3));
    std::vector<int> itest_arr1 = {0,0,0,0,0,0,0,0,0};
    assert(mi1.dataTest(itest_arr1));
    assert(mi2.dataTest(itest_arr1));
    assert(mi4.dataTest(itest_arr1));

    //double
    MtmMatSq<double> md0(3);
    MtmMatSq<double> md1(3,0.1);
    MtmMatSq<double> md2(md1);
    MtmMat<double> md3(Dimensions(3,3),0.1);
    MtmMatSq<double> md4(md3);
    assert(md1.dimTest(3,3));
    assert(md2.dimTest(3,3));
    assert(md4.dimTest(3,3));
    std::vector<double> dtest_arr1 = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
    assert(md1.dataTest(dtest_arr1));
    assert(md2.dataTest(dtest_arr1));
    assert(md4.dataTest(dtest_arr1));

    //float
    MtmMatSq<float> mf0(3);
    MtmMatSq<float> mf1(3,6.5);
    MtmMatSq<float> mf2(mf1);
    MtmMat<float> mf3(Dimensions(3,3),6.5);
    MtmMatSq<float> mf4(mf3);
    assert(mf1.dimTest(3,3));
    assert(mf2.dimTest(3,3));
    assert(mf4.dimTest(3,3));
    std::vector<float> ftest_arr1 = {6.5,6.5,6.5,6.5,6.5,6.5,6.5,6.5,6.5};
    assert(mf1.dataTest(ftest_arr1));
    assert(mf2.dataTest(ftest_arr1));
    assert(mf4.dataTest(ftest_arr1));

    //Complex
    MtmMatSq<Complex> mc0(3);
    MtmMatSq<Complex> mc1(3,Complex(2,3));
    MtmMatSq<Complex> mc2(mc1);
    MtmMat<Complex> mc3(Dimensions(3,3),Complex(2,3));
    MtmMatSq<Complex> mc4(mc3);
    assert(mc1.dimTest(3,3));
    assert(mc2.dimTest(3,3));
    assert(mc4.dimTest(3,3));
    std::vector<Complex> ctest_arr1 = {Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3)};
    assert(mc1.dataTest(ctest_arr1));
    assert(mc2.dataTest(ctest_arr1));
    assert(mc4.dataTest(ctest_arr1));
    return;
}

void mtmMatSqOperators() {
    int scalar = 2;
    std::vector<int> test_arr_0 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> test_arr_1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::vector<int> test_arr_m1 = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    std::vector<int> test_arr_2 = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    std::vector<int> test_arr_m2 = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};
    std::vector<int> test_arr_3 = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    std::vector<int> test_arr_18 = {18,18,18,18,18,18,18,18,18};

    MtmMatSq<int> m1(4, 0);
    MtmMatSq<int> m2(4, 1);
    MtmMat<int> m3 = m1 + m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 + scalar;
    assert(m3.dataTest(test_arr_2));
    m3 = scalar + m2;
    assert(m3.dataTest(test_arr_3));
    m3 = m1 - m2;
    assert(m3.dataTest(test_arr_m1));
    m3 = scalar - m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 - scalar;
    assert(m3.dataTest(test_arr_m2));
    MtmMatSq<int> m4(4, -2);
//    m3 = -m4;
//    assert(m3.dataTest(test_arr_2));
    m3 = m1 * 2;
    assert(m3.dataTest(test_arr_0));
    m3 = m2 * 2;
    assert(m3.dataTest(test_arr_2));
    m3 = 3 * m2;
    assert(m3.dataTest(test_arr_3));

    m2 = MtmMatSq<int>(3,2);
    m1 = MtmMatSq<int>(3,3);

    m3 = m2 * m1;
    assert(m3.dimTest(3,3));
    assert(m3.dataTest(test_arr_18));
    assert(m3[0][0] == 18);

    m2 = MtmMatSq<int>(2,0);
    m1 = MtmMatSq<int>(2,0);
    m2[0][0] = 1;
    m2[1][0] = 2;
    m2[0][1] = 3;
    m2[1][1] = 4;
    m1[0][0] = 5;
    m1[1][0] = 6;
    m1[0][1] = 7;
    m1[1][1] = 8;

    std::vector<int> test_arr_new = {23, 34, 31, 46};
    m3 = m2 * m1;
    assert(m3.dimTest(2,2));
    assert(m3.dataTest(test_arr_new));
}

void mtmMatSqIterators() {
    MtmMatSq<int> m(2,0);
    MtmMatSq<int>::nonzero_iterator nz_it_0 = m.nzbegin();
//    assert(nz_it_0.pubGetLocation() == 4);
    ++nz_it_0;
    m[1][0] = 1;    //0 2
    m[0][1] = 2;    //1 3
    m[1][1] = 3;

    MtmMatSq<int>::iterator it_0 = m.begin();
    MtmMatSq<int>::iterator it_end = m.end();
//    assert(it_0.pubGetLocation() == 0);
//    assert(it_end.pubGetLocation() == 4);

    for(int i = 0; it_0 != it_end; ++it_0, ++i) {
        assert(*it_0 == i);
    }
    /// 0 2
    m[1][1] = 0; /// 1 0

    MtmMatSq<int>::nonzero_iterator nz_it_1 = m.nzbegin();
    MtmMatSq<int>::nonzero_iterator nz_it_end = m.nzend();

//    assert(nz_it_1.pubGetLocation() == 1);
//    assert(nz_it_end.pubGetLocation() == 4);

    int test_arr[2] = {1, 2};
    for(int i = 0; nz_it_1 != nz_it_end; ++nz_it_1, i++) {
        assert(*nz_it_1 != 0);
        assert(*nz_it_1 == test_arr[i]);
        test_arr[i]=test_arr[i];
    }
    test_arr[0]=0;
    MtmMatSq<int>::iterator it_1 = m.begin();
    MtmMatSq<int>::iterator it_2 = m.begin();
    ++it_1;
    assert(it_1 != it_2);
    ++it_2;
    assert(it_1 == it_2);

    MtmMatSq<int>::nonzero_iterator nz_it_2 = m.nzbegin();
    MtmMatSq<int>::nonzero_iterator nz_it_3 = m.nzbegin();
    ++nz_it_2;
    assert(nz_it_2 != nz_it_3);
    ++nz_it_3;
    assert(nz_it_2 == nz_it_3);

    MtmMatSq<int>::nonzero_iterator nz_it_4 = m.nzbegin();
    for(; nz_it_4 != nz_it_end; ++nz_it_4) {
        *nz_it_4 = 4;
    }
    std::vector<int> test_arr_0_4 = {0,4,4,0};
    assert(m.dataTest(test_arr_0_4));

    MtmMatSq<int>::iterator it_3 = m.begin();
    for(; it_3 != it_end; ++it_3) {
        *it_3 = 1;
    }
    std::vector<int> test_arr_1 = {1,1,1,1};
    assert(m.dimTest(2,2));
    assert(m.dataTest(test_arr_1));

    MtmMat<int>::iterator it_4 = m.begin();
    MtmMat<int>::iterator it_end_4 = m.end();
    for(; it_4 != it_end_4; ++it_4) {
        *it_4 = 0;
    }
    std::vector<int> test_arr_11 = {0,0,0,0};
    assert(m.dimTest(2,2));
    assert(m.dataTest(test_arr_11));

    return;
}

void mtmMatSqMethods() {
    MtmMatSq<int> m1(4, 0);
    MtmMatSq<int> m2(2, 0);
    MtmMatSq<int> m3(4, 0);

    m2.resize(Dimensions(3,3), 1);
    std::vector<int> test_arr_2 = {0,0,1,0,0,1,1,1,1};
    assert(m2.dimTest(3,3));
    assert(m2.dataTest(test_arr_2));

    m3.resize(Dimensions(2,2), 1);
    std::vector<int> test_arr_3 = {0,0,0,0};
    assert(m3.dimTest(2,2));
    assert(m3.dataTest(test_arr_3));


    MtmMat<int>::iterator it = m1.begin();
    MtmMat<int>::iterator it_end = m1.end();
    for(int i = 0 ;it != it_end; ++it, i++) {
        *it = i;
    }
    std::vector<int> test_arr_1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<int> test_arr_1t = {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};
    m1.transpose();
    assert(m1.dimTest(4,4));
    assert(m1.dataTest(test_arr_1t));

    m1.transpose();
    assert(m1.dimTest(4,4));
    assert(m1.dataTest(test_arr_1));
    return;
}

void mtmMatSqDataTypes() {
    MtmMatSq<int> m1(5,5);
    MtmMatSq<double> m2(5,5.5);
    MtmMatSq<float> m3(5, 4534.4);
    MtmMatSq<Complex> m4(6,Complex(6,6));
}

void mtmMatSqExceptionsTest() {
    MtmMatSq<int> m0(1,0);
    MtmMatSq<int> m5(3,0);
    MtmMatSq<int> m6(2,0);

    try {
        m0 = m5 + m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 - m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 * m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(3,1));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(3,3));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.resize(Dimensions(4,5), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m7(Dimensions(4,5),0);
        MtmMatSq<int> m8(m7);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    MtmMatSq<int>::iterator it = m5.begin();
    MtmMatSq<int>::iterator it_end = m5.end();
    for (int i = 0; i < 20; i++, ++it) {}

    try {
        *it = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        *it_end = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it_end << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[0][3] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[3][0] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[0][4] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[4][0] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMatSq<int> m1(-1,5);
        assert(false);
    }
    catch (MtmExceptions::OutOfMemory& e){
        cout<< e.what() <<endl;
    }
}

void mtmMatSqFunc() {
    class maxAbsolute {
        int currMax;
    public:
        maxAbsolute() : currMax(0) {}
        void operator()(int x) {
            int absX = x>(-x) ? x : -x;
            if (currMax<absX) {currMax=absX;}
        }
        int operator*() { return  currMax;}
    };

    MtmMatSq<int> m(3,0);
    m[0][0]=1;m[1][0]=2;m[2][0]=0;
    m[0][1]=3;m[1][1]=2;m[2][1]=1;
    m[0][2]=5;m[1][2]=-6;m[2][2]=-3;
    maxAbsolute f;
    MtmVec<int> res(m.matFunc(f));
    assert(res[0]==2 and res[1]==3 and res[2]==6);
}

void mtmMatSqTest() {
    mtmMatSqAdditional();
    mtmMatSqConstructors();
    mtmMatSqOperators();
    mtmMatSqIterators();
    mtmMatSqMethods();
    mtmMatSqDataTypes();
    mtmMatSqExceptionsTest();
    mtmMatSqFunc();
    cout << "mtmMatSqTest() Done" << endl;
    return;
}


//MtmMatTriag Tests
void mtmMatTriagAdditional() {
    MtmMatTriag<int> m0(3);
    MtmMatTriag<int> m1l(3,1,false);
    MtmMatTriag<int> m1(3,1);
    MtmMatTriag<int> m2(m1);
    std::vector<int> test_arr1 = {1,0,0,2,3,0,4,5,6};
    MtmMatSq<int> m3(3,0);
    MtmMat<int> m4(Dimensions(3,3),0);
    size_t index = 0;
    for(size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 3; j++) {
            m3[j][i] = test_arr1[index];
            m4[j][i] = test_arr1[index];
            index++;
        }
    }
    MtmMatTriag<int> m5(m3);
    MtmMatTriag<int> m6(m4);
    assert(m1.dimTest(3,3));
    assert(m1l.dimTest(3,3));
    assert(m2.dimTest(3,3));
    assert(m5.dimTest(3,3));
    assert(m6.dimTest(3,3));
    std::vector<int> test_arr2 = {1,0,0,1,1,0,1,1,1};
    std::vector<int> test_arr2l = {1,1,1,0,1,1,0,0,1};
    assert(m1l.dataTest(test_arr2l));
    assert(m1.dataTest(test_arr2));
    assert(m2.dataTest(test_arr2));
    assert(m5.dataTest(test_arr1));
    assert(m6.dataTest(test_arr1));
    m1.transpose();

    assert(m1.dimTest(3,3));
    assert(m1.dataTest(test_arr2l));
    m1.transpose();
    assert(m1.dimTest(3,3));
    assert(m1.dataTest(test_arr2));

    MtmMatTriag<int> m7(5,2);
    m7 = m1;
    assert(m7.dimTest(3,3));
    assert(m7.dataTest(test_arr2));

    m1.resize(Dimensions(4,4), 2);
    std::vector<int> test_arr3 = {1,0,0,0,1,1,0,0,1,1,1,0,2,2,2,2};
    assert(m1.dimTest(4,4));
    assert(m1.dataTest(test_arr3));

    try {
        MtmMat<int> m8(Dimensions(4,5),0);
        MtmMatTriag<int> m9(m8);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m10(Dimensions(3,3),0);
        m10[0][2] = 1;
        m10[2][0] = 1;
        MtmMatTriag<int> m11(m10);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMatSq<int> m12(3,0);
        m12[0][2] = 1;
        m12[2][0] = 1;
        MtmMatTriag<int> m13(m12);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    MtmMatTriag<int> m14(3,1);
    try {
        m14.reshape(Dimensions(3,3));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m14.reshape(Dimensions(3,2));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m14.resize(Dimensions(4,5), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    MtmMatTriag<int> m15(5,1);
    try {
        m15[3][0] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int>::iterator it = m15.begin();
        ++it;
        *it = 10;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    m15.transpose();
    try {
        m15[0][3] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int>::iterator it = m15.begin();
        for (int i = 0;i < 5;i++, ++it) {}
        *it = 10;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    m15.resize(Dimensions(10,10) ,2);
    try {
        m15[0][3] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int>::iterator it = m15.begin();
        for (int i = 0;i < 10;i++, ++it) {}
        *it = 10;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    return;
}

void mtmMatTriagConstructors() {
    //int
    MtmMatTriag<int> mi0(3);
    MtmMatTriag<int> mi1l(3,1,false);
    MtmMatTriag<int> mi1(3,1);
    MtmMatTriag<int> mi2(mi1);
    MtmMat<int> mi3(Dimensions(3,3),0);
    mi3[0][0] = 1;
    mi3[0][1] = 1;
    mi3[1][1] = 1;
    mi3[0][2] = 1;
    mi3[1][2] = 1;
    mi3[2][2] = 1;
    MtmMatTriag<int> mi4(mi3);
    MtmMatSq<int> mi5(mi3);
    MtmMatTriag<int> mi6(mi5);

    assert(mi1.dimTest(3,3));
    assert(mi1l.dimTest(3,3));
    assert(mi2.dimTest(3,3));
    assert(mi4.dimTest(3,3));
    assert(mi6.dimTest(3,3));
    std::vector<int> itest_arr1 = {1,0,0,1,1,0,1,1,1};
    std::vector<int> itest_arr1l = {1,1,1,0,1,1,0,0,1};
    assert(mi1.dataTest(itest_arr1));
    assert(mi1l.dataTest(itest_arr1l));
    assert(mi2.dataTest(itest_arr1));
    assert(mi4.dataTest(itest_arr1));
    assert(mi6.dataTest(itest_arr1));

    //double
    MtmMatTriag<double> md0(3);
    MtmMatTriag<double> md1(3,0.1);
    MtmMatTriag<double> md2(md1);
    MtmMat<double> md3(Dimensions(3,3),0);
    md3[0][0] = 0.1;
    md3[0][1] = 0.1;
    md3[1][1] = 0.1;
    md3[0][2] = 0.1;
    md3[1][2] = 0.1;
    md3[2][2] = 0.1;
    MtmMatTriag<double> md4(md3);
    MtmMatSq<double> md5(md3);
    MtmMatTriag<double> md6(md5);
    assert(md1.dimTest(3,3));
    assert(md2.dimTest(3,3));
    assert(md4.dimTest(3,3));
    assert(md6.dimTest(3,3));
    std::vector<double> dtest_arr1 = {0.1,0,0,0.1,0.1,0,0.1,0.1,0.1};
    assert(md1.dataTest(dtest_arr1));
    assert(md2.dataTest(dtest_arr1));
    assert(md4.dataTest(dtest_arr1));
    assert(md6.dataTest(dtest_arr1));

    //float
    MtmMatTriag<float> mf0(3);
    MtmMatTriag<float> mf1(3,6.5);
    MtmMatTriag<float> mf2(mf1);
    MtmMat<float> mf3(Dimensions(3,3),0);
    mf3[0][0] = 6.5;
    mf3[0][1] = 6.5;
    mf3[1][1] = 6.5;
    mf3[0][2] = 6.5;
    mf3[1][2] = 6.5;
    mf3[2][2] = 6.5;
    MtmMatTriag<float> mf4(mf3);
    MtmMatSq<float> mf5(mf3);
    MtmMatTriag<float> mf6(mf5);
    assert(mf1.dimTest(3,3));
    assert(mf2.dimTest(3,3));
    assert(mf4.dimTest(3,3));
    assert(mf6.dimTest(3,3));
    std::vector<float> ftest_arr1 = {6.5,0,0,6.5,6.5,0,6.5,6.5,6.5};
    assert(mf1.dataTest(ftest_arr1));
    assert(mf2.dataTest(ftest_arr1));
    assert(mf4.dataTest(ftest_arr1));
    assert(mf6.dataTest(ftest_arr1));

    //Complex
    MtmMatTriag<Complex> mc0(3);
    MtmMatTriag<Complex> mc1(3,Complex(2,3));
    MtmMatTriag<Complex> mc2(mc1);
    MtmMat<Complex> mc3(Dimensions(3,3),Complex(0,0));
    mc3[0][0] = Complex(2,3);
    mc3[0][1] = Complex(2,3);
    mc3[1][1] = Complex(2,3);
    mc3[0][2] = Complex(2,3);
    mc3[1][2] = Complex(2,3);
    mc3[2][2] = Complex(2,3);
    MtmMatTriag<Complex> mc4(mc3);
    MtmMatSq<Complex> mc5(mc3);
    MtmMatTriag<Complex> mc6(mc5);
    assert(mc1.dimTest(3,3));
    assert(mc2.dimTest(3,3));
    assert(mc4.dimTest(3,3));
    assert(mc6.dimTest(3,3));
    std::vector<Complex> ctest_arr1 = {Complex(2,3),Complex(0,0),
                                       Complex(0,0),Complex(2,3),
                                       Complex(2,3),Complex(0,0),
                                       Complex(2,3),Complex(2,3),
                                       Complex(2,3)};
    assert(mc1.dataTest(ctest_arr1));
    assert(mc2.dataTest(ctest_arr1));
    assert(mc4.dataTest(ctest_arr1));
    assert(mc6.dataTest(ctest_arr1));
    return;
}

void mtmMatTriagOperators() {
    int scalar = 3;
    std::vector<int> test_arr_1 = {3,0,0,0,3,3,0,0,3,3,3,0,3,3,3,3};
    std::vector<int> test_arr_2 = {4,3,3,3,4,4,3,3,4,4,4,3,4,4,4,4};
    std::vector<int> test_arr_3 = {5,3,3,3,5,5,3,3,5,5,5,3,5,5,5,5};
    std::vector<int> test_arr_4 = {-1,0,0,0,-1,-1,0,0,-1,-1,-1,0,-1,-1,-1,-1};
    std::vector<int> test_arr_5 = {1,3,3,3,1,1,3,3,1,1,1,3,1,1,1,1};
    std::vector<int> test_arr_6 = {-2,-3,-3,-3,-2,-2,-3,-3,-2,-2,-2,-3,-2,-2,-2,-2};
    std::vector<int> test_arr_7 = {2,0,0,0,2,2,0,0,2,2,2,0,2,2,2,2};
    std::vector<int> test_arr_8 = {2,0,0,0,2,2,0,0,2,2,2,0,2,2,2,2};
    std::vector<int> test_arr_9 = {4,0,0,0,4,4,0,0,4,4,4,0,4,4,4,4};
    std::vector<int> test_arr_10 = {6,0,0,0,6,6,0,0,6,6,6,0,6,6,6,6};
    std::vector<int> test_arr_11 = {6,0,0,12,6,0,18,12,6};
    std::vector<int> test_arr_12 = {9,0,0,51,52,0,165,183,136};
    std::vector<int> test_arr_13 = {2,1,1,1,2,1,1,1,2};


    MtmMatTriag<int> m1(4, 1);
    MtmMatTriag<int> m2(4, 2);
    MtmMat<int> m3 = m1 + m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 + scalar;
    assert(m3.dataTest(test_arr_2));
    m3 = scalar + m2;
    assert(m3.dataTest(test_arr_3));
    m3 = m1 - m2;
    assert(m3.dataTest(test_arr_4));
    m3 = scalar - m2;
    assert(m3.dataTest(test_arr_5));
    m3 = m1 - scalar;
    assert(m3.dataTest(test_arr_6));
    MtmMatTriag<int> m4(4, -2);
//    m3 = -m4;
//    assert(m3.dataTest(test_arr_7));
    m3 = m1 * 2;
    assert(m3.dataTest(test_arr_8));
    m3 = m2 * 2;
    assert(m3.dataTest(test_arr_9));
    m3 = 3 * m2;
    assert(m3.dataTest(test_arr_10));

    m2 = MtmMatTriag<int>(3,2);
    m1 = MtmMatTriag<int>(3,3);

    m3 = m2 * m1;
    assert(m3.dimTest(3,3));
    assert(m3.dataTest(test_arr_11));
    assert(m3[0][0] == 6);

    m2 = MtmMatTriag<int>(3,0);
    m1 = MtmMatTriag<int>(3,0);
    m2[0][0] = 1;
    m2[0][1] = 3;
    m2[1][1] = 4;
    m2[0][2] = 6;
    m2[1][2] = 7;
    m2[2][2] = 8;

    m1[0][0] = 9;
    m1[0][1] = 12;
    m1[1][1] = 13;
    m1[0][2] = 15;
    m1[1][2] = 16;
    m1[2][2] = 17;

    m3 = m2 * m1;
    assert(m3.dimTest(3,3));
    assert(m3.dataTest(test_arr_12));

    m2 = MtmMatTriag<int>(3,1,false);
    m1 = MtmMatTriag<int>(3,1);
    m3 = m2 + m1;

    assert(m3.dimTest(3,3));
    assert(m3.dataTest(test_arr_13));
}

void mtmMatTriagIterators() {
    MtmMatTriag<int> m(2,0);

    MtmMatTriag<int>::nonzero_iterator nz_it_0 = m.nzbegin();

//    assert(nz_it_0.pubGetLocation() == 4);
    m[0][0] = 1;    //1 2
    m[0][1] = 2;    //0 3
    m[1][1] = 3;
    ++nz_it_0;
    MtmMatTriag<int>::iterator it_0 = m.begin();
    MtmMatTriag<int>::iterator it_end = m.end();
//    assert(it_0.pubGetLocation() == 0);
//    assert(it_end.pubGetLocation() == 4);

    int array[4] = {1,0,2,3};
    for(int i = 0; it_0 != it_end; ++it_0, ++i) {
        if (i != 1) {
            assert(*it_0 == array[i]);
            array[i]=array[i];
        }
    }
    array[0]=0;
    m[0][0] = 0; /// 0 2
    m[1][1] = 0; /// 0 0

    MtmMatTriag<int>::nonzero_iterator nz_it_1 = m.nzbegin();
    MtmMatTriag<int>::nonzero_iterator nz_it_end = m.nzend();

//    assert(nz_it_1.pubGetLocation() == 2);
//    assert(nz_it_end.pubGetLocation() == 4);

    int test_arr[1] = {2};
    for(int i = 0; nz_it_1 != nz_it_end; ++nz_it_1, i++) {
        assert(*nz_it_1 != 0);
        assert(*nz_it_1 == test_arr[i]);
        test_arr[i]=test_arr[i];
    }
    test_arr[0]=0;
    MtmMatTriag<int>::iterator it_1 = m.begin();
    MtmMatTriag<int>::iterator it_2 = m.begin();
    ++it_1;
    assert(it_1 != it_2);
    ++it_2;
    assert(it_1 == it_2);

    MtmMatTriag<int>::nonzero_iterator nz_it_2 = m.nzbegin();
    MtmMatTriag<int>::nonzero_iterator nz_it_3 = m.nzbegin();
    ++nz_it_2;
    assert(nz_it_2 != nz_it_3);
    ++nz_it_3;
    assert(nz_it_2 == nz_it_3);
    cout << "1" << endl;

    MtmMatTriag<int>::nonzero_iterator nz_it_4 = m.nzbegin();
    for(; nz_it_4 != nz_it_end; ++nz_it_4) {
        *nz_it_4 = 4;
    }
    std::vector<int> test_arr_0_4 = {0,0,4,0};
    assert(m.dataTest(test_arr_0_4));
    cout << "1" << endl;

    MtmMatTriag<int>::iterator it_3 = m.begin();
    for(int i = 0; it_3 != it_end; ++it_3, i++) {
        if (i != 1) {
            *it_3 = 1;
        }
    }

    std::vector<int> test_arr_1 = {1,0,1,1};
    assert(m.dimTest(2,2));
    assert(m.dataTest(test_arr_1));

    MtmMat<int>::iterator it_4 = m.begin();
    MtmMat<int>::iterator it_end_4 = m.end();
    for(int i = 0; it_4 != it_end_4; ++it_4, i++) {
        if (i != 1) {
            *it_4 = 0;
        }
    }
    std::vector<int> test_arr_11 = {0,0,0,0};
    assert(m.dimTest(2,2));
    assert(m.dataTest(test_arr_11));

    MtmMatSq<int>::iterator it_5 = m.begin();
    MtmMatSq<int>::iterator it_end_5 = m.end();
    for(int i = 0; it_5 != it_end_5; ++it_5, i++) {
        if (i != 1) {
            *it_5 = 1;
        }
    }
    assert(m.dimTest(2,2));
    assert(m.dataTest(test_arr_1));
    return;
}

void mtmMatTriagConst() {
    const MtmMatTriag<int> m1(3,1);
    int array[9] = {1,0,0,1,1,0,1,1,1};
    int i = 0;
    for (size_t c = 0; c < 3; c++) {
        for (size_t r = 0; r < 3; r++) {
            assert(m1[r][c] == array[i]);
            array[i]=array[i];
            i++;

        }
    }
    return;
}

void mtmMatTriagMethods() {
    MtmMatTriag<int> m1(3, 0);
    MtmMatTriag<int> m2(2, 0);
    MtmMatTriag<int> m3(4, 1);

    m2.resize(Dimensions(3,3), 1);
    std::vector<int> test_arr_2 = {0,0,0,0,0,0,1,1,1};
    assert(m2.dimTest(3,3));
    assert(m2.dataTest(test_arr_2));

    m3.resize(Dimensions(2,2), 2);
    std::vector<int> test_arr_3 = {1,0,1,1};
    assert(m3.dimTest(2,2));
    assert(m3.dataTest(test_arr_3));


    MtmMat<int>::iterator it = m1.begin();
    MtmMat<int>::iterator it_end = m1.end();
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][1] = 3;
    m1[0][2] = 4;
    m1[1][2] = 5;
    m1[2][2] = 6;
    std::vector<int> test_arr_1 = {1,0,0,2,3,0,4,5,6};
    std::vector<int> test_arr_1t = {1,2,4,0,3,5,0,0,6};
    assert(m1.pubGetIsUpper());
    m1.transpose();
    assert(m1.dimTest(3,3));
    assert(m1.dataTest(test_arr_1t));
    assert(!m1.pubGetIsUpper());

    m1.transpose();
    assert(m1.dimTest(3,3));
    assert(m1.dataTest(test_arr_1));
    assert(m1.pubGetIsUpper());
    ++it;
    ++it_end;
    return;
}

void mtmMatTriagDataTypes() {
    MtmMatTriag<int> m1(5,5);
    MtmMatTriag<double> m2(5,5.5);
    MtmMatTriag<float> m3(5, 4534.4);
    MtmMatTriag<Complex> m4(6,Complex(6,6));
    MtmMatTriag<int> m5(5,5,false);
    MtmMatTriag<double> m6(5,5.5,false);
    MtmMatTriag<float> m7(5, 4534.4,false);
    MtmMatTriag<Complex> m8(6,Complex(6,6),false);
}

void mtmMatTriagExceptionsTest() {
    MtmMatTriag<int> m0(1,0);
    MtmMatTriag<int> m5(3,0);
    MtmMatTriag<int> m6(2,0);

    try {
        m0 = m5 + m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 - m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 * m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(3,1));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.reshape(Dimensions(3,3));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.resize(Dimensions(4,5), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m7(Dimensions(4,5),0);
        MtmMatTriag<int> m8(m7);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m9(Dimensions(2,2),0);
        m9[0][1] = 1;
        m9[1][0] = 1;
        MtmMatTriag<int> m10(m9);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMatSq<int> m11(2,0);
        m11[0][1] = 1;
        m11[1][0] = 1;
        MtmMatTriag<int> m12(m11);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    MtmMatTriag<int>::iterator it = m5.begin();
    MtmMatTriag<int>::iterator it_end = m5.end();
    for (int i = 0; i < 20; i++, ++it) {}

    try {
        *it = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        *it_end = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it_end << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[0][3] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[3][0] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[0][4] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[4][0] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMatTriag<int> m1(-1,5);
        assert(false);
    }
    catch (MtmExceptions::OutOfMemory& e){
        cout<< e.what() <<endl;
    }

    MtmMatTriag<int> m20(3, 1);
    MtmMatTriag<int> m20l(3, 1, false);
    const MtmMatTriag<int> mc20(3, 1);
    const MtmMatTriag<int> mc20l(3, 1, false);

    assert(mc20[1][0] == 0);
    assert(mc20[2][0] == 0);
    assert(mc20[2][1] == 0);
    assert(mc20l[0][1] == 0);
    assert(mc20l[0][2] == 0);
    assert(mc20l[1][2] == 0);

    try {
        m20[1][0] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m20[2][0] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m20[2][1] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m20l[0][1] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m20l[0][2] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m20l[1][2] = 1;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }
}

void mtmMatTriagFunc() {
    class maxAbsolute {
        int currMax;
    public:
        maxAbsolute() : currMax(0) {}
        void operator()(int x) {
            int absX = x>(-x) ? x : -x;
            if (currMax<absX) {currMax=absX;}
        }
        int operator*() { return  currMax;}
    };

    MtmMatTriag<int> m(3,0,false);
    m[0][0]=1;m[1][0]=2;m[2][0]=0;
    m[1][1]=2;m[2][1]=1;
    m[2][2]=-3;
    maxAbsolute f;
    MtmVec<int> res(m.matFunc(f));
    assert(res[0]==2 and res[1]==2 and res[2]==3);
}

void mtmMatTriagTest() {
    mtmMatTriagAdditional();
    mtmMatTriagConstructors();
    mtmMatTriagOperators();
    mtmMatTriagIterators();
//    mtmMatTriagConst();
    mtmMatTriagMethods();
    mtmMatTriagDataTypes();
    mtmMatTriagExceptionsTest();//
    mtmMatTriagFunc();
    cout << "mtmMatTriagTest() Done" << endl;
    return;
}

//MtmVec Tests
void mtmVecConstructors() {
    //int
    MtmVec<int> mi0(3);
    MtmVec<int> mi1(3,1);
    MtmVec<int> mi2(mi1);

    assert(mi1.dimTest(3,1));
    assert(mi2.dimTest(3,1));
    std::vector<int> itest_arr1 = {1,1,1};
    assert(mi1.dataTest(itest_arr1));
    assert(mi2.dataTest(itest_arr1));

    //double
    MtmVec<double> md0(3);
    MtmVec<double> md1(3,0.1);
    MtmVec<double> md2(md1);
    assert(md1.dimTest(3,1));
    assert(md2.dimTest(3,1));
    std::vector<double> dtest_arr1 = {0.1,0.1,0.1};
    assert(md1.dataTest(dtest_arr1));
    assert(md2.dataTest(dtest_arr1));

    //float
    MtmVec<float> mf0(3);
    MtmVec<float> mf1(3,6.5);
    MtmVec<float> mf2(mf1);
    assert(mf1.dimTest(3,1));
    assert(mf2.dimTest(3,1));
    std::vector<float> ftest_arr1 = {6.5,6.5,6.5};
    assert(mf1.dataTest(ftest_arr1));
    assert(mf2.dataTest(ftest_arr1));

    //Complex
    MtmVec<Complex> mc0(3);
    MtmVec<Complex> mc1(3,Complex(2,3));
    MtmVec<Complex> mc2(mc1);
    assert(mc1.dimTest(3,1));
    assert(mc2.dimTest(3,1));
    std::vector<Complex> ctest_arr1 = {Complex(2,3),Complex(2,3),
                                       Complex(2,3)};
    assert(mc1.dataTest(ctest_arr1));
    assert(mc2.dataTest(ctest_arr1));
    return;
}

void mtmVecOperators() {
    int scalar = 2;
    std::vector<int> test_arr_0 = {0,0,0,0};
    std::vector<int> test_arr_1 = {1,1,1,1};
    std::vector<int> test_arr_m1 = {-1,-1,-1,-1};
    std::vector<int> test_arr_2 = {2,2,2,2};
    std::vector<int> test_arr_m2 = {-2,-2,-2,-2};
    std::vector<int> test_arr_3 = {3,3,3,3};
    std::vector<int> test_arr_6 = {6,6,6,6,6,6,6,6,6};

    MtmVec<int> m1(4, 0);
    MtmVec<int> m2(4, 1);
    MtmVec<int> m3 = m1 + m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 + scalar;
    assert(m3.dataTest(test_arr_2));
    m3 = scalar + m2;
    assert(m3.dataTest(test_arr_3));
    m3 = m1 - m2;
    assert(m3.dataTest(test_arr_m1));
    m3 = scalar - m2;
    assert(m3.dataTest(test_arr_1));
    m3 = m1 - scalar;
    assert(m3.dataTest(test_arr_m2));
    MtmVec<int> m4(4, -2);
//    m3 = -m4;
//    assert(m3.dataTest(test_arr_2));
    m3 = m1 * 2;
    assert(m3.dataTest(test_arr_0));
    m3 = m2 * 2;
    assert(m3.dataTest(test_arr_2));
    m3 = 3 * m2;
    assert(m3.dataTest(test_arr_3));

    m2 = MtmVec<int>(3,2);
    m1 = MtmVec<int>(3,3);
    m1.transpose();

    MtmMat<int> m5 = m2 * m1;
    assert(m5.dimTest(3,3));
    assert(m5.dataTest(test_arr_6));
    assert(m5[0][0] == 6);

    m2 = MtmVec<int>(3,0);
    m1 = MtmVec<int>(3,0);
    m2[0] = 1;
    m2[1] = 2;
    m2[2] = 3;
    m1[0] = 4;
    m1[1] = 5;
    m1[2] = 6;

    m1.transpose();
    std::vector<int> test_arr_new = {4, 8, 12, 5, 10, 15, 6, 12, 18};
    m5 = m2 * m1;
    assert(m5.dimTest(3,3));
    assert(m5.dataTest(test_arr_new));
}

void mtmVecIterators() {
    MtmVec<int> m(7, 0);
    MtmVec<int>::nonzero_iterator nz_it_0 = m.nzbegin();
//    assert(nz_it_0.pubGetLocation() == 7);
    for (size_t i = 0; i < 7; i++) {
        m[i] = i+1;
    }
    ++nz_it_0;
    MtmVec<int>::iterator it_0 = m.begin();
    MtmVec<int>::iterator it_end = m.end();
//    assert(it_0.pubGetLocation() == 0);
//    assert(it_end.pubGetLocation() == 7);
    for(int i = 1; it_0 != it_end; ++it_0, ++i) {
        assert(*it_0 == i);
    }

    m[0] = 0; /// 0 2 3 0 5 0 7
    m[3] = 0;
    m[5] = 0;

    MtmVec<int>::nonzero_iterator nz_it_1 = m.nzbegin();
    MtmVec<int>::nonzero_iterator nz_it_end = m.nzend();
//    assert(nz_it_1.pubGetLocation() == 1);
//    assert(nz_it_end.pubGetLocation() == 7);
    int test_arr[7] = {2,3,5,7};
    for(int i = 0; nz_it_1 != nz_it_end; ++nz_it_1, i++) {
        assert(*nz_it_1 != 0);
        assert(*nz_it_1 == test_arr[i]);
        test_arr[i]=test_arr[i];
    }
    test_arr[0]=0;
    MtmVec<int>::iterator it_1 = m.begin();
    MtmVec<int>::iterator it_2 = m.begin();
    ++it_1;
    assert(it_1 != it_2);
    ++it_2;
    assert(it_1 == it_2);

    MtmVec<int>::nonzero_iterator nz_it_2 = m.nzbegin();
    MtmVec<int>::nonzero_iterator nz_it_3 = m.nzbegin();
    ++nz_it_2;
    assert(nz_it_2 != nz_it_3);
    ++nz_it_3;
    assert(nz_it_2 == nz_it_3);

    MtmVec<int>::nonzero_iterator nz_it_4 = m.nzbegin();
    for(; nz_it_4 != nz_it_end; ++nz_it_4) {
        *nz_it_4 = 4;
    }
    std::vector<int> test_arr_0_4 = {0,4,4,0,4,0,4};
    assert(m.dataTest(test_arr_0_4));

    MtmVec<int>::iterator it_3 = m.begin();
    for(; it_3 != it_end; ++it_3) {
        *it_3 = 1;
    }
    std::vector<int> test_arr_1 = {1,1,1,1,1,1,1};
    assert(m.dimTest(7,1));
    assert(m.dataTest(test_arr_1));

//    MtmMat<int>::iterator it_4 = m.begin();
//    MtmMat<int>::iterator it_end_4 = m.end();
//    for(; it_4 != it_end_4; ++it_4) {
//        *it_4 = 0;
//    }
//    std::vector<int> test_arr_11 = {0,0,0,0,0,0,0};
//    assert(m.dimTest(7,1));
//    assert(m.dataTest(test_arr_11));

    return;
}

void mtmVecMethods() {
    MtmVec<int> m1(10, 1);
    MtmVec<int> m2(5, 1);
    MtmVec<int> m3(5, 1);
    MtmVec<int> m4(10, 1);
    MtmVec<int> m5(5, 1);
    MtmVec<int> m6(10, 1);

    m1.resize(Dimensions(5,1), 2);
    std::vector<int> test_arr_2 = {1,1,1,1,1};
    assert(m1.dimTest(5,1));
    assert(m1.dataTest(test_arr_2));
//    assert(m1.pubGetIsVertical());

    m2.resize(Dimensions(8,1), 2);
    std::vector<int> test_arr_3 = {1,1,1,1,1,2,2,2};
    assert(m2.dimTest(8,1));
    assert(m2.dataTest(test_arr_3));
//    assert(m2.pubGetIsVertical());

    m3.transpose();
    m3.resize(Dimensions(1,8), 2);
    assert(m3.dimTest(1,8));
    assert(m3.dataTest(test_arr_3));
//    assert(!m3.pubGetIsVertical());

    m4.transpose();
    m4.resize(Dimensions(1,5), 2);
    assert(m4.dimTest(1,5));
    assert(m4.dataTest(test_arr_2));
//    assert(!m4.pubGetIsVertical());

    MtmVec<int> v1(16,0);
    for (size_t i = 0; i < 16; i++) {
        v1[i] = i;
    }

    std::vector<int> test_arr_1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    v1.transpose();
    assert(v1.dimTest(1,16));
    assert(v1.dataTest(test_arr_1));

    v1.transpose();
    assert(v1.dimTest(16,1));
    assert(v1.dataTest(test_arr_1));

    std::vector<Complex> arr = {Complex(0,1), Complex(2,3), Complex(6,6)};
    MtmVec<Complex> v2(3,0);
    for (size_t i = 0; i < 3; i++) {
        v2[i] = arr[i];
    }
    v2.transpose();
    assert(v2.dimTest(1,3));
    assert(v2.dataTest(arr));

    v2.transpose();
    assert(v2.dimTest(3,1));
    assert(v2.dataTest(arr));

    return;
}

void mtmVecDataTypes() {
    MtmVec<int> m1(5,5);
    MtmVec<double> m2(5,5.5);
    MtmVec<float> m3(5, 4534.4);
    MtmVec<Complex> m4(6,Complex(6,6));
}

void mtmVecExceptionsTest() {
    MtmVec<int> m0(1,0);
    MtmVec<int> m5(3,0);
    MtmVec<int> m6(2,0);

    try {
        m0 = m5 + m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        m0 = m5 - m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m1(Dimensions(1,1),0);
        m1 = m5 * m6;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }


    try {
        m5.resize(Dimensions(4,2), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        m5.resize(Dimensions(1,5), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmVec<int> m55(3,1);
        m55.transpose();
        m55.resize(Dimensions(6,1), 1);
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }


    try {
        MtmVec<int> m1(0,5);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }


    MtmVec<int>::iterator it = m5.begin();
    MtmVec<int>::iterator it_end = m5.end();
    for (int i = 0; i < 20; i++, ++it) {}

    try {
        *it = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        *it_end = 0;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << *it_end << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        m5[4] = 4;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        cout << m5[4] << endl;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmVec<int> m1(-1,5);
        assert(false);
    }
    catch (MtmExceptions::OutOfMemory& e){
        cout<< e.what() <<endl;
    }
}

void mtmVecFunc() {
    class maxAbsolute {
        int currMax;
    public:
        maxAbsolute() : currMax(0) {}
        void operator()(int x) {
            int absX = x>(-x) ? x : -x;
            if (currMax<absX) {currMax=absX;}
        }
        int operator*() { return  currMax;}
    };

    MtmVec<int> v(5,2);
    v[1]=-4;v[3]=12;v[2]=-40;
    maxAbsolute f;
    assert(v.vecFunc(f)==40);
}

void mtmVecTest() {
    mtmVecConstructors();
    mtmVecOperators();
    mtmVecIterators();
    mtmVecMethods();
    mtmVecDataTypes();
    mtmVecExceptionsTest();
    mtmVecFunc();
    cout << "mtmVecTest() Done" << endl;
    return;
}

//Mixed Operators
void mixedOperatorsExceptions(){
    MtmMat<int> m_mat(Dimensions(2,6), 1);
    MtmMatSq<int> m_sq(3,2);
    MtmMatTriag<int> m_tri(4,3);
    MtmVec<int> m_vec(5,4);
    MtmMat<int> m_mat_ans(Dimensions(1,1),0);

    try {
        m_mat_ans = m_mat + m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat + m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat + m_vec;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq + m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq + m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri + m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri + m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_vec + m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }



    try {
        m_mat_ans = m_mat - m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat - m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat - m_vec;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq - m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq - m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri - m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri - m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_vec - m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }



    try {
        m_mat_ans = m_mat * m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat * m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_mat * m_vec;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq * m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq * m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_sq * m_vec;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri * m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri * m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_tri * m_vec;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_vec * m_mat;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_vec * m_sq;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        m_mat_ans = m_vec * m_tri;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    return;
}

void mixedOperatorsSuccess() {
    MtmMat<int> m_mat1(Dimensions(3,3), 1);
    MtmMat<int> m_mat2(Dimensions(3,1), 1);
    MtmMatSq<int> m_sq(3,2);
    MtmMatTriag<int> m_tri(3,3);
    MtmVec<int> m_vec(3,4);
    MtmMat<int> m_mat_ans(Dimensions(1,1),0);

    std::vector<int> arr_1 = {3,3,3,3,3,3,3,3,3};
    std::vector<int> arr_2 = {4,1,1,4,4,1,4,4,4};
    std::vector<int> arr_3 = {5,5,5};
    std::vector<int> arr_4 = {3,3,3,3,3,3,3,3,3};
    std::vector<int> arr_5 = {5,2,2,5,5,2,5,5,5};
    std::vector<int> arr_6 = {4,1,1,4,4,1,4,4,4};
    std::vector<int> arr_7 = {5,2,2,5,5,2,5,5,5};
    std::vector<int> arr_8 = {5,5,5};
    std::vector<int> arr_9 = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    std::vector<int> arr_10 = {-2,1,1,-2,-2,1,-2,-2,-2};
    std::vector<int> arr_11 = {-3,-3,-3};
    std::vector<int> arr_12 = {1,1,1,1,1,1,1,1,1};
    std::vector<int> arr_13 = {-1,2,2,-1,-1,2,-1,-1,-1};
    std::vector<int> arr_14 = {2,-1,-1,2,2,-1,2,2,2};
    std::vector<int> arr_15 = {1,-2,-2,1,1,-2,1,1,1};
    std::vector<int> arr_16 = {3,3,3};


    m_mat_ans = m_mat1 + m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_1));

    m_mat_ans = m_mat1 + m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_2));

    m_mat_ans = m_mat2 + m_vec;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr_3));

    m_mat_ans = m_sq + m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_4));

    m_mat_ans = m_sq + m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_5));

    m_mat_ans = m_tri + m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_6));

    m_mat_ans = m_tri + m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_7));

    m_mat_ans = m_vec + m_mat2;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr_8));


    m_mat_ans = m_mat1 - m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_9));

    m_mat_ans = m_mat1 - m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_10));

    m_mat_ans = m_mat2 - m_vec;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr_11));

    m_mat_ans = m_sq - m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_12));

    m_mat_ans = m_sq - m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_13));

    m_mat_ans = m_tri - m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_14));

    m_mat_ans = m_tri - m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr_15));

    m_mat_ans = m_vec - m_mat2;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr_16));

    std::vector<int> arr2_1 = {6,6,6,6,6,6,6,6,6};
    std::vector<int> arr2_2 = {3,3,3,6,6,6,9,9,9};
    std::vector<int> arr2_3 = {12,12,12};
    std::vector<int> arr2_4 = {6,6,6,6,6,6,6,6,6};
    std::vector<int> arr2_5 = {6,6,6,12,12,12,18,18,18};
    std::vector<int> arr2_6 = {24,24,24};
    std::vector<int> arr2_7 = {9,6,3,9,6,3,9,6,3};
    std::vector<int> arr2_8 = {18,12,6,18,12,6,18,12,6};
    std::vector<int> arr2_9 = {36,24,12};
    std::vector<int> arr2_10 = {12,12,12};
    std::vector<int> arr2_11 = {24,24,24};
    std::vector<int> arr2_12 = {12,24,36};

    m_mat_ans = m_mat1 * m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_1));

    m_mat_ans = m_mat1 * m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_2));

    m_mat_ans = m_mat1 * m_vec;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr2_3));

    m_mat_ans = m_sq * m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_4));

    m_mat_ans = m_sq * m_tri;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_5));

    m_mat_ans = m_sq * m_vec;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr2_6));

    m_mat_ans = m_tri * m_mat1;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_7));

    m_mat_ans = m_tri * m_sq;
    assert(m_mat_ans.dimTest(3,3));
    assert(m_mat_ans.dataTest(arr2_8));

    m_mat_ans = m_tri * m_vec;
    assert(m_mat_ans.dimTest(3,1));
    assert(m_mat_ans.dataTest(arr2_9));

    m_vec.transpose();
    m_mat_ans = m_vec * m_mat1;
    assert(m_mat_ans.dimTest(1,3));
    assert(m_mat_ans.dataTest(arr2_10));

    m_mat_ans = m_vec * m_sq;
    assert(m_mat_ans.dimTest(1,3));
    assert(m_mat_ans.dataTest(arr2_11));

    m_mat_ans = m_vec * m_tri;
    assert(m_mat_ans.dimTest(1,3));
    assert(m_mat_ans.dataTest(arr2_12));
    return;
}

void mixedOperatorsTest() {
    mixedOperatorsExceptions();
    mixedOperatorsSuccess();
    cout << "mixedOperatorsTest() Done" << endl;
    return;
}

//segelExampleTests
void exceptionsTest() {
    try {
        MtmVec<float> v(0,5);
        assert(false);
    }
    catch (MtmExceptions::IllegalInitialization& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmMat<int> m1(Dimensions(10,100000000000),5);
        assert(false);
    }
    catch (MtmExceptions::OutOfMemory& e){
        cout<< e.what() <<endl;
    }

    try {
        MtmVec<int> v1(3,5);
        MtmMat<int> m1(Dimensions(3,3),5);
        MtmMat<int> m3=m1+v1;
        assert(false);
    }
    catch (MtmExceptions::DimensionMismatch& e){
        cout<< e.what() <<endl;
    }
    try {
        MtmMat<int> m1(Dimensions(3,3),5);
        m1.reshape(Dimensions(2,3));
        assert(false);
    }
    catch (MtmExceptions::ChangeMatFail& e){
        cout<< e.what() <<endl;
    }
    try {
        MtmMat<int> m1(Dimensions(3,3),5);
        m1[4][3]=5;
        assert(false);
    }
    catch (MtmExceptions::AccessIllegalElement& e){
        cout<< e.what() <<endl;
    }
}

void constructors() {
    MtmVec<int> v1(5,3);
    MtmMat<int> m1(Dimensions(3,3),0);
    MtmMatSq<int> m2(3,1);
    MtmMatTriag<int> m3(3,1,true);
}

void dataTypes() {
    MtmVec<int> v1(5,3);
    MtmVec<double > v2(5,3);
    MtmVec<float> v3(5,3);
    MtmVec<Complex> v4(5,Complex(3,4));
}

void FuncExample() {
    class maxAbsolute {
        int currMax;
    public:
        maxAbsolute() : currMax(0) {}
        void operator()(int x) {
            int absX = x>(-x) ? x : -x;
            if (currMax<absX) {currMax=absX;}
        }
        int operator*() { return  currMax;}
    };

    MtmVec<int> v(5,0);
    v[1]=3;v[2]=-7;v[3]=-1;v[4]=2;
    MtmMat<int> m(Dimensions(2,3),0);
    m[0][1]=1;m[1][0]=2;
    m[0][1]=3;m[1][1]=2;
    m[0][2]=5;m[1][2]=-6;
    maxAbsolute f;
    assert (v.vecFunc(f)==7);
    MtmVec<int> res(m.matFunc(f));
    assert(res[0]==2 and res[1]==3 and res[2]==6);
}

void iterators() {
    MtmMatSq<int> m(2,0);
    m[1][0]=1;m[1][1]=2;

    int res_it[]={0,1,0,2};
    int res_nz_it[]={1,2};

    int i=0;
    for (MtmMatSq<int>::iterator it=m.begin();it!=m.end();++it) {
        assert (res_it[i]==(*it));
        res_it[i]=res_it[i];
        ++i;

    }

    i=0;
    for (MtmMatSq<int>::nonzero_iterator it=m.nzbegin();it!=m.nzend();++it) {
        assert (res_nz_it[i]==(*it));
        res_nz_it[i]=res_nz_it[i];
        ++i;
    }
    res_it[0]=0;
    res_nz_it[0]=0;
}

void segelExampleTest() {
    exceptionsTest();
    constructors();
    dataTypes();
    FuncExample();
    iterators();
    cout << "segelTest() Done" << endl;
    return;
}

int main() {
//    mtmComplexTest();
    mtmMatTest();
    mtmMatSqTest();
    mtmMatTriagTest();
    mtmVecTest();
    mixedOperatorsTest();
    segelExampleTest();
    cout << "Finished all tests!!!" << endl;
    return 0;
}