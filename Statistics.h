#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <vector>
#include <map>
#include <set>
#include <cmath>
#include "assert.h"

namespace Math {
    
    using namespace std;
    
    template<typename T>
    double sum(const vector<T>& values) {
        
        assert(values.size() > 0);
        
        double sumValue = 0;
        
        typename vector<T>::const_iterator vectorIterator;
        
        for (vectorIterator = values.begin(); vectorIterator != values.end(); ++vectorIterator) {
            sumValue += *vectorIterator;
        }
        
        return sumValue;
    }
    
    template<typename T>
    double mean(const vector<T>& values) {
        
        assert(values.size() > 0);
        
        double result = 0;
        
        result = sum(values) / values.size();
        
        return result;
    }
    
    template<typename T>
    double sumOfSquares(const vector<T>& values) {
        
        assert(values.size() > 0);
        
        double result = 0;
        
        typename vector<T>::const_iterator vectorIterator;
        
        for (vectorIterator = values.begin(); vectorIterator != values.end(); ++vectorIterator) {
            result += pow(*vectorIterator, 2);
        }
        
        return result;
    }
    
    template<typename T>
    double variance(const vector<T>& values) {
        
        assert(values.size() > 0);
        
        double sumOfSquaresValue = sumOfSquares(values);
        double meanValue = mean(values);
        
        double result;
        
        result = sumOfSquaresValue - pow(meanValue, 2);
        
        return result;
    }
    
    template<typename T>
    double sampleStandardDeviation(const vector<T>& values) {
        
        assert(values.size() > 1);
        
        double result = 0;
        
        result = sqrt(variance(values) / (values.size() - 1));
        
        return result;
    }
    
    template<typename T>
    double maxValue(const vector<T>& values) {
        
        assert(values.size() > 0);
        
        double result = *(values.begin());
        
        typename vector<T>::const_iterator vectorIterator;
        
        for (vectorIterator = values.begin(); vectorIterator != values.end(); ++vectorIterator) {
            
            double temp = *vectorIterator;
            
            if (result < temp) {
                result = temp;
            }
        }
        
        return result;
    }
    
    template<typename T>
    size_t maxValueIndex(const vector<T>& values) {
        
        double maxValue = 0;
        size_t maxIndex = 0;
        
        size_t index = 0;
        
        typename vector<T>::const_iterator vectorIterator;
        
        for (vectorIterator = values.begin(); vectorIterator != values.end(); ++vectorIterator) {
            
            if (vectorIterator == values.begin()) {
                maxValue = *vectorIterator;
            } else {
                if (*vectorIterator > maxValue) {
                    maxValue = *vectorIterator;
                    maxIndex = index;
                }
            }
            ++index;
        }
        
        return maxIndex;
    }
    
    template <typename T>
    inline const map<T, double> distribution(const vector<T>& data) {
        
        map<T, double> result;
        
        multiset<T> multiSet;
        
        size_t size = data.size();
        
        for (size_t index = 0; index < size; ++index) {
            
            multiSet.insert(data.at(index));
        }
        
        typename multiset<T>::iterator multiSetIterator;
        
        for (multiSetIterator = multiSet.begin(); multiSetIterator != multiSet.end(); ++multiSetIterator) {
            size_t count = multiSet.count(*multiSetIterator);
            result[*multiSetIterator] = count / (double)size;
        }

        return map<T, double>(result);
    }
}

#endif