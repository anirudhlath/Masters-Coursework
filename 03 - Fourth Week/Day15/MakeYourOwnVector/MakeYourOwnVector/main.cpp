//
//  main.cpp
//  MakeYourOwnVector
//
//  Created by Anirudh Lath on 9/13/21.
//
#include "helper.hpp"
#include <iostream>



int main(int argc, const char * argv[]) {
    
    // T1: Make Vector Test
    myvector testVector(4);
    myvector testVector2(10);
    myvector testVector3(129);
    
    if (testVector.getCapacity() == 4 && testVector.getSize() == 0
        && testVector2.getCapacity() == 10 && testVector2.getSize() == 0
        && testVector3.getCapacity() == 129 && testVector3.getSize() == 0)
    {
        std::cout << "T1: makeVector() passed!\n";
    } else {
        std::cout << "T1: makeVector() failed!!!\n";
        exit(1);
    }
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity:   " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity:  " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";
    
    // T2: pushBack Test
    for(int i = 0; i < 150; i++) {
        testVector.pushBack(i);
        testVector2.pushBack(i);
        testVector3.pushBack(i);
        if (testVector.getSize() != i + 1 && testVector.getIndex(i) != i
            && testVector2.getSize() != i + 1 && testVector2.getIndex(i) != i
            && testVector3.getSize() != i + 1 && testVector3.getIndex(i) != i) {
            std::cout << "T2: pushBack() failed!!!\n";
            exit(1);
        }
    }
    std::cout << "T2: pushBack() passed!\n";
    std::cout << " Statistics of each vector:\n";
    std::cout << " *** NOTICE THE ADDRESS CHANGED DUE TO growVector() ***\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";

    
    // T3: get Test
    for (int i = 0; i < 150; i++) {
        if (testVector.get(i) != i
            && testVector2.get(i) != i
            && testVector3.get(i) != i ) {
            std::cout << "T3: get() failed!!!\n";
            exit(1);
        }
    }
    std::cout << "T3: get() passed!\n";
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";
    
    // T4: set Test
    for (int i = 150; i > 0; i--) {
        testVector.set(i - 1, 150 - i);
        testVector2.set(i - 1, 150 - i);
        testVector3.set(i - 1, 150 - i);
        if (   testVector.get(i - 1) != 150 - i
            && testVector2.get(i - 1) != 150 - i
            && testVector3.get(i - 1) != 150 - i) {
            std::cout << "T4: set() failed!!!\n";
            exit(1);
        }
    }
    std::cout << "T4: set() passed!\n";
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";
    
    // T5: growVector Test
    int vec1 = testVector.getCapacity();
    int vec2 = testVector2.getCapacity();
    int vec3 = testVector3.getCapacity();
    testVector.growVector();
    testVector2.growVector();
    testVector3.growVector();
    
    if (   testVector.getCapacity() != vec1 * 2
        && testVector2.getCapacity() != vec2 * 2
        && testVector3.getCapacity() != vec3 * 2) {
        std::cout << "T5: growVector() failed!!!\n";
        exit(1);
    }
    std::cout << "T5: growVector() passed!\n";
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";

    // T6: pushBack Test
    for(int i = 0; i < 150; i++) {
        testVector.popBack();
        testVector2.popBack();
        testVector3.popBack();
        if (testVector.getSize() != 150 - i - 1 && testVector.getIndex(i) != 0
            && testVector2.getSize() != 150 - i - 1 && testVector2.getIndex(i) != 0
            && testVector3.getSize() != 150 - i - 1 && testVector3.getIndex(i) != 0) {
            std::cout << "T6: popBack() failed!!!\n";
            exit(1);
        }
    }
    std::cout << "T6: popBack() passed!\n";
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";
    
    // T7: freeVector Test
    int *myvec1 = testVector.getAddress();
    int *myvec2 = testVector2.getAddress();
    int *myvec3 = testVector3.getAddress();
    
    testVector.freeVector();
    testVector2.freeVector();
    testVector3.freeVector();
    
    if (   testVector.getAddress() == myvec1
        && testVector2.getAddress() == myvec2
        && testVector3.getAddress() == myvec3) {
        std::cout << "T7: freeVector() failed!!!\n";
        exit(1);
    }
    std::cout << "T7: freeVector() passed!\n";
    
    std::cout << " Statistics of each vector:\n";
    std::cout << " testVector  ===> Size = " << testVector.getSize() << " | Capacity: " << testVector.getCapacity() << " | Address: " << testVector.getAddress() << "\n";
    std::cout << " testVector2 ===> Size = " << testVector2.getSize() << " | Capacity: " << testVector2.getCapacity() << " | Address: " << testVector2.getAddress() << "\n";
    std::cout << " testVector3 ===> Size = " << testVector3.getSize() << " | Capacity: " << testVector3.getCapacity() << " | Address: " << testVector3.getAddress() << "\n\n";
    
    std::cout << "[******************** ALL TESTS PASSED! ********************]\n\n";
    
    return 0;
}
